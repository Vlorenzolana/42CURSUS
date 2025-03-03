#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_HILOS 5
#define ITERACIONES 1000000

// Variable compartida entre los hilos
int				contador = 0;

// Mutex para sincronización
pthread_mutex_t	mutex;

void	*incrementar_contador(void *arg)
{
	for (int i = 0; i < ITERACIONES; i++)
	{
		// Bloquear el mutex para acceder al contador de manera segura
		pthread_mutex_lock(&mutex);
		// Incrementar el contador
		contador++;
		// Desbloquear el mutex
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	hilos[NUM_HILOS];

	// Inicializar el mutex
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		perror("Error al inicializar el mutex");
		return (1);
	}
	// Crear los hilos
	for (int i = 0; i < NUM_HILOS; i++)
	{
		if (pthread_create(&hilos[i], NULL, incrementar_contador, NULL) != 0)
		{
			perror("Error al crear el hilo");
			return (1);
		}
	}
	// Esperar a que los hilos terminen
	for (int i = 0; i < NUM_HILOS; i++)
	{
		pthread_join(hilos[i], NULL);
	}
	// Imprimir el valor final del contador
	printf("Valor final del contador: %d\n", contador);
	// Destruir el mutex
	pthread_mutex_destroy(&mutex);
	return (0);
}
