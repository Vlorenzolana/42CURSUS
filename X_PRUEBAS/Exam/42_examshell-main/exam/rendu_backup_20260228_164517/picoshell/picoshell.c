#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int picoshell(char **cmds[]) 
{
	int fd[2];
	int in_fd = -1;
	int i = 0;
	int pid;

	while(cmds[i])
	{
		if (cmds[i + 1]) // Si hay un comando siguiente, se necesita crear un pipe para conectar la salida del comando actual con la entrada del siguiente.
		{
			if (pipe(fd) < 0) // Si pipe(fd) devuelve un valor negativo, significa que hubo un error al crear el pipe. En este caso, se cierran los fds abiertos y se devuelve 1 para indicar un error
				return(1);
		}
		else // Si no hay un comando siguiente, no se necesita crear un pipe, por lo que se inicializan los fds a -1 para indicar que no están en uso.
		{
			fd[1]=-1;
			fd[0]=-1;
		}
		pid = fork(); // fork() crea un nuevo proceso. El proceso padre recibe el PID del hijo, mientras que el proceso hijo recibe 0.
		if (pid < 0) // Si pid es menor que 0, se produjo un error al crear el proceso hijo. En este caso, se cierran los fds abiertos y se devuelve 1 para indicar un error.
		{
			if (fd[1] != -1) // Si el fd de escritura del pipe no es -1, significa que se creó un pipe y se deben cerrar ambos extremos para liberar los recursos.
			{
				close(fd[1]);
				close(fd[0]);
			}
			if (in_fd != -1)  // Si in_fd no es -1, significa que se abrió un fd para la entrada del comando anterior y se debe cerrar para liberar los recursos.
			{
				close(in_fd);
			}
			return (1);
		}
		if (pid == 0) // Si pid es igual a 0, estamos en el proceso hijo. En este caso, se configuran las redirecciones de entrada y salida según sea necesario, se ejecuta el comando con execvp, y si execvp falla, se devuelve 1 para indicar un error.
		{
			if (fd[1] != -1)
			{
				close(fd[0]);
				if (dup2(fd[1], 1) < 0) // dup2(fd[1], 1) duplica el fd de escritura del pipe en el descriptor de archivo 1 (stdout), redirigiendo la salida estándar al extremo de escritura del pipe. Si dup2 devuelve un valor negativo, significa que hubo un error al configurar la redirección, por lo que se devuelve 1 para indicar un error.
				{
					exit(1);
				}
				close(fd[1]);
			}
			if(in_fd != -1) // Si in_fd no es -1, significa que se abrió un fd para la entrada del comando anterior y se debe redirigir la entrada estándar.
			{
				if (dup2(in_fd, 0) < 0) // dup2(in_fd, 0) duplica el fd de entrada del comando anterior en el descriptor de archivo 0 (stdin), redirigiendo la entrada estándar al extremo de lectura del pipe. Si dup2 devuelve un valor negativo, significa que hubo un error al configurar la redirección, por lo que se devuelve 1 para indicar un error.
				{
					exit(1);
				}
				close(in_fd);
			}
			execvp(cmds[i][0],cmds[i]); // execvp(cmds[i][0], cmds[i]) ejecuta el comando especificado por cmds[i][0] con los argumentos en cmds[i]. Si execvp devuelve un valor negativo, significa que hubo un error al ejecutar el comando, por lo que se devuelve 1 para indicar un error.
			exit(1);
		}
		else
		{
			if (in_fd != -1) // Si in_fd no es -1, significa que se abrió un fd para la entrada del comando anterior y se debe cerrar para liberar los recursos.
			{
				close(in_fd);
			}
			if (fd[1] != -1) // Si el fd de escritura del pipe no es -1, significa que se creó un pipe y se deben cerrar ambos extremos para liberar los recursos.
			{
				close(fd[1]);
			}
			in_fd = fd[0]; // in_fd se actualiza para ser el fd de lectura del pipe actual, que se usará como entrada para el siguiente comando en la próxima iteración del bucle.
		}
		i++;
	}
	while (wait(NULL) > 0)
	{
		;
	}
	return(0);
}
/* 
// Test case structure
typedef struct {
	char *name;
	char **cmds[10];
	char *expected_output;
	int should_succeed;
} test_case_t;

// Function to run a test case
int run_test(test_case_t *test) {
	printf("Running test: %s\n", test->name);
	
	// Count FDs before
	int fds_before = count_open_fds();
	
	// Redirect stdout to capture output
	int stdout_backup = dup(STDOUT_FILENO);
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1) {
		perror("pipe");
		return 0;
	}
	
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	
	// Run picoshell
	int result = picoshell(test->cmds);
	
	// Restore stdout
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);
	
	// Read captured output
	char output[1024] = {0};
	close(pipe_fd[1]); // Close write end if not already closed
	read(pipe_fd[0], output, sizeof(output) - 1);
	close(pipe_fd[0]);
	
	// Remove trailing newline for comparison
	int len = strlen(output);
	if (len > 0 && output[len-1] == '\n') {
		output[len-1] = '\0';
	}
	
	// Count FDs after
	int fds_after = count_open_fds();
	
	// Check results
	int success = 1;
	
	// Check return value
	if (test->should_succeed == 1 && result != 0) {
		printf("  ❌ Expected success (0) but got %d\n", result);
		success = 0;
	} else if (test->should_succeed == 2 && (result != 0 && result != 1)) {
		printf("  ❌ Expected success (0 or 1) but got %d\n", result);
		success = 0;
	} else if (test->should_succeed == 0 && result == 0) {
		printf("  ❌ Expected failure (non-zero) but got 0\n");
		success = 0;
	}
	
	// Check output if expected
	if (test->expected_output && strcmp(output, test->expected_output) != 0) {
		printf("  ❌ Output mismatch\n");
		printf("     Expected: '%s'\n", test->expected_output);
		printf("     Got:      '%s'\n", output);
		success = 0;
	}
	
	// Check for FD leaks
	if (fds_after != fds_before) {
		printf("  ❌ File descriptor leak detected!\n");
		printf("     FDs before: %d, after: %d\n", fds_before, fds_after);
		success = 0;
	}
	
	if (success) {
		printf("  ✅ PASS\n");
	}
	
	printf("\n");
	return success;
} */
/* 
int main() {
	printf("=== PICOSHELL AUTOMATED TESTER ===\n\n");
	
	// Test cases
	test_case_t tests[] = {
		// Simple command
		{
			"Simple echo",
			{
				(char*[]){"echo", "hello", NULL},
				NULL
			},
			"hello",
			1
		},
		
		// Simple pipe
		{
			"Echo pipe to cat",
			{
				(char*[]){"echo", "test", NULL},
				(char*[]){"cat", NULL},
				NULL
			},
			"test",
			1
		},
		
		// Three command pipeline
		{
			"Echo pipe to cat pipe to cat",
			{
				(char*[]){"echo", "pipeline", NULL},
				(char*[]){"cat", NULL},
				(char*[]){"cat", NULL},
				NULL
			},
			"pipeline",
			1
		},
		
		// Test with sed
		{
			"Echo pipe to sed",
			{
				(char*[]){"echo", "hello", NULL},
				(char*[]){"sed", "s/l/x/g", NULL},
				NULL
			},
			"hexxo",
			1
		},
		
		// Test with grep (should find match)
		{
			"Echo pipe to grep match",
			{
				(char*[]){"echo", "hello world", NULL},
				(char*[]){"grep", "world", NULL},
				NULL
			},
			"hello world",
			1
		},
		
		// Test with grep (no match - should succeed but no output)
		{
			"Echo pipe to grep no match",
			{
				(char*[]){"echo", "hello", NULL},
				(char*[]){"grep", "xyz", NULL},
				NULL
			},
			"",
			2 // Accept exit code 0 or 1 as success
		},
		
		// Test with invalid command (should fail)
		{
			"Invalid command",
			{
				(char*[]){"nonexistent_command_xyz", NULL},
				NULL
			},
			NULL,
			0
		},
		
		// Complex pipeline
		{
			"Complex pipeline",
			{
				(char*[]){"echo", "aaa bbb ccc", NULL},
				(char*[]){"sed", "s/a/x/g", NULL},
				(char*[]){"sed", "s/b/y/g", NULL},
				(char*[]){"sed", "s/c/z/g", NULL},
				NULL
			},
			"xxx yyy zzz",
			1
		}
	};
	
	int total_tests = sizeof(tests) / sizeof(tests[0]);
	int passed_tests = 0;
	
	// Run all tests
	for (int i = 0; i < total_tests; i++) {
		if (run_test(&tests[i])) {
			passed_tests++;
		}
	}
	
	// Summary
	printf("=== TEST SUMMARY ===\n");
	printf("Passed: %d/%d tests\n", passed_tests, total_tests);
	
	if (passed_tests == total_tests) {
		printf("🎉 ALL TESTS PASSED! No memory leaks or FD leaks detected.\n");
		return 0;
	} else {
		printf("❌ Some tests failed.\n");
		return 1;
	}
} */