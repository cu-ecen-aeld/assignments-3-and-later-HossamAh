#!/bin/sh
# Author: Hossam Ahmed

writefile=$1
writestr=$2

if [ $# -lt 2 ]
then
    echo "the parameters were not specified"
    exit 1
fi
mkdir -p "$(dirname "$writefile")" && touch "$writefile"

echo "$writestr" > "$writefile"

if [ $? -eq 1 ]
then
    echo error
    exit 1
fi 