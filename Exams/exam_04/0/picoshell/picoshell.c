#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
    if (!cmds || !cmds[0])
        return 1;

    // Count number of commands
    int cmd_count = 0;
    while (cmds[cmd_count])
        cmd_count++;

    if (cmd_count == 0)
        return 1;

    // Create pipes for communication between commands
    int pipes[cmd_count - 1][2];
    pid_t pids[cmd_count];

    // Create all pipes
    for (int i = 0; i < cmd_count - 1; i++)
    {
        if (pipe(pipes[i]) == -1)
        {
            // Close any previously created pipes
            for (int j = 0; j < i; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            return 1;
        }
    }

    // Fork and execute each command
    for (int i = 0; i < cmd_count; i++)
    {
        pids[i] = fork();
        if (pids[i] == -1)
        {
            // Close all pipes and return error
            for (int j = 0; j < cmd_count - 1; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            return 1;
        }

        if (pids[i] == 0)  // Child process
        {
            // Set up input redirection (except for first command)
            if (i > 0)
            {
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }

            // Set up output redirection (except for last command)
            if (i < cmd_count - 1)
            {
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // Close all pipe file descriptors
            for (int j = 0; j < cmd_count - 1; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            // Execute the command
            execvp(cmds[i][0], cmds[i]);
            exit(1);  // If execvp fails
        }
    }

    // Parent process: close all pipes
    for (int i = 0; i < cmd_count - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes
    for (int i = 0; i < cmd_count; i++)
    {
        int status;
        waitpid(pids[i], &status, 0);
        // If any child process fails, we could return 1
        // But according to the subject, we return 0 if all processes are waited for
    }

    return 0;
}