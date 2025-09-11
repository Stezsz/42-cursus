#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror argo.c -o argo_test
cat > sample.json <<EOF
{"num":123,"str":"ola","map":{"x":1,"y":"z"}}
EOF
echo "# Teste argo sample.json"
./argo_test sample.json
rm -f sample.json
