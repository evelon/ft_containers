#!/usr/bin/env bash

tested_path="../"
include_path="$tested_path"
deepthought_dir="deepthought"
log_dir="logs"

mkdir -p $deepthought_dir $log_dir

srcs="srcs"

CC="clang++"
CFLAGS="-Werror -Wextra -Wall -std=c++98"

if false; then
  CFLAGS+=" -fsanitize=address -g3"
fi

emoji[0]="😆"
emoji[1]="🥵"

function printheader ()
{
  printf "😪...  jolim tester\n\n"
}

compile ()
{
  $CC $CFLAGS -I./$include_path -DNAMESPACE=$1 "$2" -o "$3" &>/dev/null
}

compare ()
{
  # 1=test_files/$container/$file
  container=$(echo $1 | cut -d "/" -f 2)
  file=$(echo $1 | cut -d "/" -f 3)
  test_name=$(echo $file | cut -d "." -f 1)
  ft_out="a.out"
  ft_log="$log_dir/ft.$container.$test_name.log"
  std_out="a.out"
  std_log="$log_dir/std.$container.$test_name.log"

  printf "%-30s: " $test_name

  compile "FT" "$1" "$ft_out"
  ft_ret=$?
  compile "STD" "$1" "$std_out"
  std_ret=$?
  comp_ret=$(test $ft_ret -eq $std_ret && echo 0 || echo 1)
  printf "COMPILE: ${emoji[$comp_ret]} "
  if [ $std_ret != 0 ]; then
    printf " Compliation should be failed! 🤭\n"
    rm -f $ft_out $std_out &>/dev/null
    return 0
  fi

  if [ $ft_ret ]; then
    ./$ft_out &>$ft_log
    ft_ret=$?
  fi
  if [ $std_ret ]; then
    ./$std_out &>$std_log
    std_ret=$?
  fi
  comp_ret=$(test $ft_ret -eq $std_ret && echo 0 || echo 1)
  printf "| RESULT: ${emoji[$comp_ret]} "

  if [ $std_ret != 0 ]; then
    printf " Error must occur! 🤭\n"
    rm -f $ft_out $std_out &>/dev/null
    rm -f $ft_log $std_log &>/dev/null
    return 0
  fi

  diff_file="$deepthought_dir/$container.$test_name.diff"
  diff $std_log $ft_log 2>/dev/null 1>"$diff_file";
  comp_ret=$?

  printf "| OUTPUT: ${emoji[!!$comp_ret]}\n"

  rm -f $ft_out $std_out
  [ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null
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
