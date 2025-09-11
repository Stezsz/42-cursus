#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror vbc.c -o vbc_test
echo "# Teste vbc expressao '2+3*(4+5)'"
./vbc_test '2+3*(4+5)'
