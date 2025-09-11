#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_popen(const char *file, char *const argv[], char type);

static void test_read(void)
{
    char *args[] = {"echo", "Ola42", NULL};
    int fd = ft_popen("echo", args, 'r');
    if (fd < 0) { perror("ft_popen r"); return; }
    char buf[128];
    ssize_t n = read(fd, buf, sizeof(buf)-1);
    if (n >= 0) {
        buf[n] = '\0';
        printf("[READ ] '%s'", buf); // echo adiciona \n
    }
    close(fd);
}

static void test_write(void)
{
    char *args[] = {"cat", NULL};
    int fd = ft_popen("cat", args, 'w');
    if (fd < 0) { perror("ft_popen w"); return; }
    const char *msg = "PIPE_TEST\n";
    write(fd, msg, strlen(msg));
    close(fd); // cat imprime no stdout do pai
    printf("[WRITE] enviado '%s'\n", msg);
}

int main(void)
{
    printf("== ft_popen tester ==\n");
    test_read();
    test_write();
    if (ft_popen(NULL, NULL, 'r') == -1)
        printf("[INVAL] OK - argumentos invalidos retornam -1\n");
    return 0;
}
