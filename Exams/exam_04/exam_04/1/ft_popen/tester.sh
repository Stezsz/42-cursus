#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -Werror ft_popen.c main.c -o ft_popen_test
./ft_popen_test
