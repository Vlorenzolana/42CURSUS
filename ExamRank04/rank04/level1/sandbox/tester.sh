#!/bin/bash
source ../../../main/colors.sh

file1=sandbox.c
file2=../../../../rendu/sandbox/sandbox.c

# Compile reference and user solutions
gcc -Werror -Wall -Wextra -o out1 main.c "$file1"
gcc -Werror -Wall -Wextra -o out2 main.c "$file2"
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)COMPILATION FAILED$(tput sgr 0)"
    echo "${RED}Your code did not compile. Please fix the errors above.${RESET}"
    rm out1 out2 out1.txt out2.txt 2>/dev/null
    exit 1
fi

# Run both executables (no arguments needed)
./out1 > out1.txt 2>/dev/null
./out2 > out2.txt 2>/dev/null

if ! diff -q out1.txt out2.txt >/dev/null ; then
    out1=$(cat out1.txt)
    out2=$(cat out2.txt)
    echo "$(tput setaf 1)$(tput bold)FAIL$(tput sgr 0)"
    echo "${GREEN}Expected Output:${RESET} \"$out1\""
    echo "${RED}Your Output:${RESET}     \"$out2\""
    rm out1 out2 out1.txt out2.txt 2>/dev/null
    exit 1
fi

rm out1 out2 out1.txt out2.txt 2>/dev/null
echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0