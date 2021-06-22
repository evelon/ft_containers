#!/usr/bin/env bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 <file> [FT / STD] [path/to/includes=..]"
  exit 1
fi

if [ -z "$2" ]; then
  NAMESPACE="FT";
else
  NAMESPACE=$2
fi
if [ -z "$3" ]; then
  INCLUDE_PATH="..";
else
  INCLUDE_PATH="$3"
fi

CC="clang++"
CFLAGS="-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3"

eval "$CC $CFLAGS -I./$INCLUDE_PATH -DNAMESPACE=$NAMESPACE $1 && ./a.out"
