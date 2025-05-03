#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void err(char *str)
{
    while (*str)
        write(2, str++, 1);
}
int cd(char **argv, int i)
{
    if (i != 2)
        return (err("error: cd: bad arguments\n"), 1);
    if (chdir(argv[1]) == -1)
        return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1);
    return (0);
}
void set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n"), exit(1);
}
int execute(char **argv, int i, char **envp)
{
    int has_pipe;
    int fd[2];
    int pid;
    int status;
    has_pipe = argv[i] && !strcmp(argv[i], "|");
    if (!strcmp(*argv, "cd"))
        return (cd(argv, i));
    if (has_pipe && (pipe(fd) == -1))
        err("error: fatal\n"), exit(1);
        // return (err("error: fatal\n"), 1);
    if ((pid = fork()) == -1)
        // return (err("error: fatal\n"), 1);
        err("error: fatal\n"), exit(1);
    if (!pid)
    {
        argv[i] = 0;
        set_pipe(has_pipe, fd, 1);
        execve(*argv, argv, envp);
        err("error: cannot execute "), err(*argv), err("\n"), exit(1);
    }
    waitpid(pid, &status, 0);
    set_pipe(has_pipe, fd, 0);
    return (WIFEXITED(status) && WEXITSTATUS(status));
}
int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;
    (void)argc;
    while (argv[i])
    {
        argv += i + 1;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (i)
            status = execute(argv, i, envp);
    }
    return(status);
}
