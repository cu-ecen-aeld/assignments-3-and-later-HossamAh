#!/bin/sh
# Author: Hossam Ahmed


filesdir=$1
searchstr=$2


if [ $# -lt 2 ]
then
    echo "the parameters were not specified"
    exit 1
fi


if [ ! -d "$filesdir" ]
then
    echo "${filesdir} does not represent a directory on the filesystem"
    exit 1
fi

matching_lines=$(grep -r  $searchstr $filesdir | wc -l)
files_count=$(ls ${filesdir} | wc -l)
echo "The number of files are ${files_count} and the number of matching lines are ${matching_lines}" 