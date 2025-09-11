#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror rip.c -o rip_test || { echo "Falha na compilacao rip"; exit 1; }
echo "# Teste rip string='(()())())('"
./rip_test '(()())())('
