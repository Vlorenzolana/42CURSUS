#!/bin/bash

mkdir -p exit logs #create folder even if already exists

echo "what's he smallest BUFFER_SIZE you'd like to check?"
read minbuff
echo "what's he biggest BUFFER_SIZE you'd like to check?"
read maxbuff

for i in $(seq $minbuff $maxbuff); do
{
    cc get_next_line.c -D BUFFER_SIZE=$i
    ./a.out > exit/gnl$i
    diff text.txt exit/gnl$i >> logs/log_gnl
} done

echo "do you wanna read the content of logs?"
echo "write \"1\" -->yes or \"2\" --> nope"
read nopeyes

if [ $nopeyes -eq 1 ]; then
    cat logs/log_gnl
else
    echo "next"
fi

echo "do you want to eliminate log files?"
echo "write \"1\" -->yes or \"2\" --> nope"
read yesnope

if [ $yesnope -eq 1 ]; then
    rm -rf exit logs
    rm ./a.out
else
    echo "ciao"
fi
