#!/usr/bin/env bash

. functions.sh
printheader
containers="list vector set map stack"

if [ $# -ne 0 ]; then
	containers=$@
fi

for container in ${containers[@]}; do
	run_test $container 2>/dev/null
	printf "\n"
done