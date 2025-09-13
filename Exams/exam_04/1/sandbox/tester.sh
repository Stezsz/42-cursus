#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror sandbox.c main.c -o sandbox_test
./sandbox_test
