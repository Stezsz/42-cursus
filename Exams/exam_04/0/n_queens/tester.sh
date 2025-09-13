#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror n_queens.c -o n_queens_test
echo "# Teste n_queens N=4"
./n_queens_test 4 | sort
