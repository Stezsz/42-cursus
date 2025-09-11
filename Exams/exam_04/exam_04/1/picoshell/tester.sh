#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror picoshell.c main.c -o picoshell_test
echo "# Teste pipeline: ls -1 | wc -l"
./picoshell_test ls -1 '|' wc -l
