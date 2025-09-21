#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static volatile sig_atomic_t timeout_occurred = 0;

static void alarm_handler(int sig)
{
    (void)sig;
    timeout_occurred = 1;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid;
    int status;
    struct sigaction sa, old_sa;

    if (!f)
        return -1;

    // Set up alarm handler
    timeout_occurred = 0;
    sa.sa_handler = alarm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, &old_sa) == -1)
        return -1;

    pid = fork();
    if (pid == -1)
    {
        sigaction(SIGALRM, &old_sa, NULL);
        return -1;
    }

    if (pid == 0)  // Child process
    {
        // Execute the function and exit with code 0
        f();
        exit(0);
    }
    else  // Parent process
    {
        alarm(timeout);

        // Wait for child process
        pid_t result = waitpid(pid, &status, 0);
        
        alarm(0);  // Cancel alarm
        sigaction(SIGALRM, &old_sa, NULL);  // Restore old signal handler
        
        if (timeout_occurred)
        {
            // Timeout occurred, kill the child if still alive
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);  // Wait for the killed child
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;  // Bad function
        }
        
        if (result == -1)
        {
            return -1;
        }

        // Check if child was terminated by signal
        if (WIFSIGNALED(status))
        {
            if (verbose)
                printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
            return 0;  // Bad function
        }

        // Check if child was terminated by signal
        if (WIFSIGNALED(status))
        {
            if (verbose)
                printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
            return 0;  // Bad function
        }

        // Check if child exited
        if (WIFEXITED(status))
        {
            int exit_code = WEXITSTATUS(status);
            if (exit_code != 0)
            {
                if (verbose)
                    printf("Bad function: exited with code %d\n", exit_code);
                return 0;  // Bad function
            }
            else
            {
                if (verbose)
                    printf("Nice function!\n");
                return 1;  // Nice function
            }
        }

        // If we get here, something unexpected happened
        return -1;
    }
}