#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror permutation.c -o permutation_test
echo "# Teste permutation 'bca' (ordena internamente para abc)"
./permutation_test bca | sort
