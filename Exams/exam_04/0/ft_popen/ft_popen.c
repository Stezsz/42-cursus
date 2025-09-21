#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    int pipefd[2];
    pid_t pid;

    // Check for invalid parameters
    if (!file || !argv || (type != 'r' && type != 'w'))
        return -1;

    // Create pipe
    if (pipe(pipefd) == -1)
        return -1;

    // Fork process
    pid = fork();
    if (pid == -1)
    {
        close(pipefd[0]);
        close(pipefd[1]);
        return -1;
    }

    if (pid == 0)  // Child process
    {
        if (type == 'r')
        {
            // For read mode: redirect stdout to pipe write end
            close(pipefd[0]);  // Close read end
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
        }
        else  // type == 'w'
        {
            // For write mode: redirect stdin from pipe read end
            close(pipefd[1]);  // Close write end
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
        }
        
        // Execute the command
        execvp(file, argv);
        exit(1);  // If execvp fails
    }
    else  // Parent process
    {
        if (type == 'r')
        {
            // For read mode: return read end, close write end
            close(pipefd[1]);
            return pipefd[0];
        }
        else  // type == 'w'
        {
            // For write mode: return write end, close read end
            close(pipefd[0]);
            return pipefd[1];
        }
    }
}