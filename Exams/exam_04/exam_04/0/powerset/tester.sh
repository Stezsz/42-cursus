#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror powerset.c -o powerset_test
echo "# Teste powerset target=5 lista=1 2 3 4"
./powerset_test 5 1 2 3 4 | sort
