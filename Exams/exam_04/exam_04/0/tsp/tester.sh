#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror tsp.c -lm -o tsp_test
cat > points.txt <<EOF
0, 0
0, 1
1, 0
1, 1
EOF
echo "# Teste tsp quadrado 4 pontos"
./tsp_test points.txt
rm -f points.txt
