#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

static void ok_function(void)
{
    write(1, "OK function running\n", 20);
}

static void slow_function(void)
{
    sleep(3);
}

static void crash_function(void)
{
    int *p = NULL;
    *p = 42;
    (void)p;
}

int main(void)
{
    printf("== sandbox tester ==\n");
    int r1 = sandbox(ok_function, 2, true);
    printf("Resultado ok_function: %d\n", r1);
    int r2 = sandbox(slow_function, 1, true);
    printf("Resultado slow_function: %d\n", r2);
    int r3 = sandbox(crash_function, 2, true);
    printf("Resultado crash_function: %d\n", r3);
    return 0;
}
