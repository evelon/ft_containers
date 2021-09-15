#!/usr/bin/env bash

tested_path="../"
include_path="$tested_path"

srcs="srcs"

CC="clang++"
CFLAGS="-Werror -Wextra -Wall -std=c++98"

function printheader ()
{
  printf "😪...  jolim tester\n\n"
}

compile ()
{
  $CC $CFLAGS -I./$include_path "$1" -o "$2" &>/dev/null
}

compare ()
{
  # 1=test_files/$container/$file
  container=$(echo $1 | cut -d "/" -f 2)
  file=$(echo $1 | cut -d "/" -f 3)
  test_name=$(echo $file | cut -d "." -f 1)

  printf "%-30s: " $test_name

  compile "$1" "timing.out"

  ./timing.out

  rm -f "timing.out"
}

run_test ()
{
  printf "\e[4mcontainer %s\e[0m\n" $1
  test_dir="srcs/$1"
  files=$(ls $test_dir | grep 'cpp')

  for file in ${files[*]}; do
    compare "$test_dir/$file"
  done
  echo
}
