#!/usr/bin/env bash

tested_path="../"
include_path="$tested_path"
deepthought_dir="deepthought"
logfile_dir="logs"
srcs="srcs"

CC="clang++"
CFLAGS="-Werror -Wextra -Wall -std=c++98"

if false; then
	CFLAGS+=" -fsanitize=address -g3"
fi

function printheader ()
{
	printf "😪  jolim tester\n"
}

compare ()
{
	containers = $(echo $1 | cut -d "/" -f 2);
	file_name = $(echo $1 | cut -d "/" -f 3);
	test_name = $(echo $file_name | cut -d "." -f 1);
}

compare $1