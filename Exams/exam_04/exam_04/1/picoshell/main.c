#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int picoshell(char **cmds[]);

static int count_cmds(int argc, char **argv)
{
    int count = 1;
    for (int i = 1; i < argc; i++)
        if (strcmp(argv[i], "|") == 0)
            count++;
    return count;
}

// Uso: ./picoshell_test ls -1 | wc -l
int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]);
        return 1;
    }
    int cmd_count = count_cmds(argc, argv);
    char ***cmds = calloc(cmd_count + 1, sizeof(char **));
    if (!cmds) { perror("calloc"); return 1; }

    int i = 1, j = 0;
    while (i < argc) {
        int len = 0;
        while (i + len < argc && strcmp(argv[i + len], "|") != 0)
            len++;
        cmds[j] = calloc(len + 1, sizeof(char *));
        if (!cmds[j]) { perror("calloc"); return 1; }
        for (int k = 0; k < len; k++)
            cmds[j][k] = argv[i + k];
        cmds[j][len] = NULL;
        i += len + 1; // pula comando + pipe
        j++;
    }
    cmds[cmd_count] = NULL;

    int ret = picoshell(cmds);

    for (int k = 0; cmds[k]; k++)
        free(cmds[k]);
    free(cmds);
    return ret;
}
