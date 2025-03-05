
• RECURSOS:
◦ Threads playlist: 
◦ ![CodeVault](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
◦ Philosophers-visualizer:
◦ ![Visual Threads](https://nafuka11.github.io/philosophers-visualizer/)

• PARAMETROS:
◦ [number_of_philosophers]: n filósofos + n tenedores.
◦ [time_to_die]: si no empieza a comer en [time_to_die] ms
desde comienzo ultima comida o desde el principio, morirá.
◦ [time_to_eat]: tiempo para comer. Durante ese tiempo,
tendrá los tenedores ocupados.
◦ [time_to_sleep]:tiempo para dormir.
◦ [time_to_think]: tiempo de sobra
◦ [number_of_times_each_philosopher_must_eat]: si to-
dos los filósofos comen al menos number_of_times_each_philosopher_must_eat
veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá
con la muerte de un filósofo.

• CASO ESPECIAL: 
◦ [MIN] :	1 FILOSOFO
◦ [MAX]	: 200 FILOSOFO
◦ Cada filósofo tendrá asignado un número del 1 al number_of_philosophers.
◦ El filósofo número 1 se sentará al lado del filósofo número number_of_philosophers.
◦ Cualquier otro filósofo número N se sentará entre el número N - 1 y el número N + 1.

• LOGS:
◦ Cualquier cambio de estado de un filósofo debe tener el siguiente formato:
◦ timestamp_in_ms X:  `has taken a l_fork`
◦ timestamp_in_ms X:  `is eating`
◦ timestamp_in_ms X:  `is sleeping`
◦ timestamp_in_ms X:  `is thinking`
◦ timestamp_in_ms X:  `died`

• Importante:
◦ Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos
    y X con el numero del filósofo.
◦ El estado impreso no debe estar roto o alterado por el estado de otros filósofos
◦ No puedes tener más de 10ms entre la muerte de un filósofo y el momento en el que
    imprimes su muerte.
◦ Te recuerdo, los filósofos deben evitar morir.
◦ Tu programa no debe tener ningún data races.

• Instructiones
◦ make
◦ ./philo 4 410 200 200 5 
	* 4 - number of philos
	* 410 - time to die
	* 200 - time to eat
	* 200 - time to sleep
	* 5 - number of meals until finishing. Program can run without this argument (./philo 4 410 200 200)

• Used Functions
◦ `pthread_create()`: Creates a new thread.
◦ `pthread_join()`: Waits until a specific thread finishes to avoid having zombie threads.
◦ `pthread_mutex_init()`: Creates a mutex.
◦ `pthread_mutex_destroy()`: Destroys a mutex.
◦ `pthread_mutex_lock()`: Locks a mutex.
◦ `pthread_mutex_unlock()`: Unlocks a mutex.
◦ `usleep()`: Makes a thread sleep for a specified number of microseconds.
◦ `gettimeofday()`: Returns the number of microseconds passed since January 1, 1970.
◦ `malloc()`: Allocates memory on the heap.
◦ `free()`: Frees memory from the heap.
◦ `printf()`: Prints messages.
