//
//
//
// THIS IS A VERY INITAL TEST
//
//
//
//
//

#include "assets.h"

void	*escribir(void *arg)
{
	t_assets	*s;

	s = (t_assets *)arg;
	pthread_mutex_lock(&r->mutex);
	strncpy(s->str, "Hola desde hilo 1!", strlen("Hola desde hilo 1!") + 1);
	printf("Hilo 1 escribe: %s\n", s->str);
	pthread_mutex_unlock(&s->mutex);
	return (NULL);
}

void	*reescribir(void *arg)
{
	t_assets	*s;

	s = (t_assets *)arg;
	pthread_mutex_lock(&s->mutex);
	strncpy(s->str, "Modif. por hilo2!", strlen("Modif. por hilo2!") + 1);
	printf("Hilo 1 escribe: %s\n", s->str);
	pthread_mutex_unlock(&s->mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t hilo1, hilo2;
	t_assets assets;

	size_t size_str = 100;
	assets.str = (char *)malloc(size_str * sizeof(char));

	if (!assets.str)
	{
		perror("Error al asignar memoria");
		return (1);
	}

	pthread_mutex_init(&assets.mutex, NULL);
	strncpy(assets.str, "str inicial", size_str);

	pthread_create(&hilo1, NULL, escribir, &assets);
	pthread_join(hilo1, NULL);

	pthread_create(&hilo2, NULL, reescribir, &assets);
	pthread_join(hilo2, NULL);

	pthread_mutex_destroy(&assets.mutex);
	free(assets.str); // Liberamos la memoria asignada dinámicamente

	return (0);
}