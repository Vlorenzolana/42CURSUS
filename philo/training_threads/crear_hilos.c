#include <pthread.h>
#include <stdio.h>

// Función que será ejecutada por los hilos
void	*imprimir_mensaje(void *arg)
{
	printf("Hola desde el hilo!\n");
	return (NULL);
}

int	main(void)
{
	pthread_t hilo1, hilo2; // Declaración de dos hilos
	// Crear el primer hilo
	if (pthread_create(&hilo1, NULL, imprimir_mensaje, NULL) != 0)
	{
		perror("Error al crear el hilo 1");
		return (1);
	}
	// Crear el segundo hilo
	if (pthread_create(&hilo2, NULL, imprimir_mensaje, NULL) != 0)
	{
		perror("Error al crear el hilo 2");
		return (1);
	}
	// Esperar a que los hilos terminen su ejecución
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	printf("Los hilos han terminado su ejecución.\n");
	return (0);
}
