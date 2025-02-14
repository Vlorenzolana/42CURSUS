#include <unistd.h>

void put_nbr(int n)
{
    if (n >=10)
        put_nbr(n/10);
    char digit = n%10 + '0';
    write(1, &digit, 1);
}

int main(void)
{
    int i;

    i = 0;

    while (i < 100)
    {
        i++;

        if (i % 3 == 0)
            write(1, "fizz", 5);
        else if (i % 5 == 0)
            write(1, "buzz", 5);
        else if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else
            put_nbr(i);
        write(1, "\n", 1);
    }
}