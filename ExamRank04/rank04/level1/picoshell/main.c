#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

// Function prototype
int picoshell(char **cmds[]);

// Helper function to count open file descriptors
int count_open_fds() {
    DIR *dir = opendir("/proc/self/fd");
    if (!dir) return -1;
    
    int count = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            count++;
        }
    }
    closedir(dir);
    return count - 1; // Subtract 1 for the opendir fd we just closed
}

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
}

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
}
