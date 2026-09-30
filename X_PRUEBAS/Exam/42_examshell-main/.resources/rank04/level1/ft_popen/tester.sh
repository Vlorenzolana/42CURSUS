#!/bin/bash
source ../../../main/colors.sh

file1=ft_popen.c
file2=../../../../rendu/ft_popen/ft_popen.c

# Test 1
gcc -Werror -Wall -Wextra -o out1 main.c ft_popen.c
gcc -Werror -Wall -Wextra -o out2 main.c ../../../../rendu/ft_popen/ft_popen.c

./out1 "test command 1" > out1.txt 2>/dev/null
./out2 "test command 1" > out2.txt 2>/dev/null

if ! diff -q out1.txt out2.txt >/dev/null ; then
    out1=$(cat out1.txt)
    out2=$(cat out2.txt)
    echo "$(tput setaf 1)$(tput bold)FAIL$(tput sgr 0)"
    echo "${GREEN}Expected Output:${RESET} \"$out1\""
    echo "${RED}Your Output:${RESET}     \"$out2\""
    rm out1 out2 out1.txt out2.txt 2>/dev/null
    exit 1
fi

# Test 2
./out1 "test command 2" > out1.txt 2>/dev/null
./out2 "test command 2" > out2.txt 2>/dev/null

if ! diff -q out1.txt out2.txt >/dev/null ; then
    out1=$(cat out1.txt)
    out2=$(cat out2.txt)
    echo "$(tput setaf 1)$(tput bold)FAIL$(tput sgr 0)"
    echo "${GREEN}Expected Output:${RESET} \"$out1\""
    echo "${RED}Your Output:${RESET}     \"$out2\""
    rm out1 out2 out1.txt out2.txt 2>/dev/null
    exit 1
fi

# Add more tests as needed...

rm out1 out2 out1.txt out2.txt 2>/dev/null
echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0