#!/bin/bash
# === Colors ===
RED="$(tput setaf 1)$(tput bold)"
GREEN="$(tput setaf 2)$(tput bold)"
YELLOW="$(tput setaf 3)$(tput bold)"
RESET="$(tput sgr0)"

REF="vbc.c"
USR="../../../../rendu/vbc/vbc.c"

# Check for vbc.h in rendu/vbc
HDR="../../../../rendu/vbc/vbc.h"
if [ ! -f "$HDR" ]; then
    echo "${RED}Missing vbc.h in rendu/vbc!${RESET}"
    exit 1
fi

echo "${YELLOW}Compiling reference...${RESET}"
if ! gcc -Wall -Wextra -Werror -o ref "$REF"; then
    echo "${RED}Reference compilation failed!${RESET}"
    exit 1
fi

echo "${YELLOW}Compiling your version...${RESET}"
# Compile user code with vbc.h if present
if ! gcc -Wall -Wextra -Werror -o usr "$USR" "$HDR"; then
    echo "${RED}Your compilation failed!${RESET}"
    rm -f ref
    exit 1
fi

tests=(
    '1'
    '2+3'
    '3*4+5'
    '3+4*5'
    '(3+4)*5'
    '(((((2+2)*2+2)*2+2)*2+2)*2'
    '1+'
    '1+2)'
    '1+2+3+4+5'
    '2*4+9+3+2*1+5+1+6+6*1*1+8*0+0+5+0*4*9*5*8+9*7+5*1+3+1+4*5*7*3+0*3+4*8+8+8+4*0*5*3+5+4+5*7+9+6*6+7+9*2*6*9+2+1*3*7*1*1*5+1+2+7+4+3*4*2+0+4*4*2*2+6+7*5+9+0+8*4+6*7+5+4*4+2+5*5+1+6+3*5*9*9+7*4*3+7+4*9+3+0+1*8+1+2*9*4*5*1+0*1*9+5*3*5+9*6+5*4+5+5*8*6*4+9*2+0+0+1*5*3+6*8*0+0+2*3+7*5*6+8+6*6+9+3+7+0*0+5+2*8+2*7*2+3+9*1*4*8*7*9+2*0+1*6*4*2+8*8*3*1+8+2*4+8*3+8*3+9*5+2*3+9*5*6*4+3*6*6+7+4*8+0+2+9*8*0*6*8*1*2*7+0*5+6*5+0*2+7+2+3+8*7+6+1*3+5+4*5*4*6*1+4*7+9*0+4+9*8+7+5+6+2+6+1+1+1*6*0*9+7+6*2+4*4+1*6*2*9+3+0+0*1*8+4+6*2+6+2*7+7+0*9+6+2*1+6*5*2*3*5*2*6*4+2*9*2*4*5*2*2*3+8+8*3*2*3+0*5+9*6+8+3*1+6*9+8+9*2*0+2'
    '(1)'
    '(((((((3)))))))'
    '(1+2)*3'
    '((6*6+7+5+8)*(1+0+4*8+7)+2)+4*(1+2)'
    '((1+3)*12+(3*(2+6))'
    ''
    'abc'
    '1++2'
    '1**2'
    '1+2*'
    '(*1+2)'
    '1+2)('
    '((1+2)*3))'
    '((1+2)*3'
    '9*9*9*9*9*9*9*9*9*9'
    '0+0+0+0+0+0+0+0+0+0'
    '(((((((((1+1)))))))))'
    '1*(2+3*(4+5*(6+7)))'
    '((2+3)*((4+5)*(6+7)))'
    '1+2+3+4+5+6+7+8+9+0'
    '1*2*3*4*5*6*7*8*9*0'
    '(((((3+2)*2)+1)*2)+1)'
)

echo
echo "${YELLOW}Running tests...${RESET}"
pass_count=0

for input in "${tests[@]}"; do
    ./usr "$input" > out_usr.txt 2>/dev/null
    ./ref "$input" > out_ref.txt 2>/dev/null

    if diff -q out_usr.txt out_ref.txt >/dev/null; then
        echo "${GREEN}PASS${RESET}  Input: $input"
        pass_count=$((pass_count + 1))
    else
        echo "${RED}FAIL${RESET}  Input: $input"
        echo "  ${GREEN}Expected:${RESET} \"$(cat out_ref.txt)\""
        echo "  ${RED}Yours:   ${RESET} \"$(cat out_usr.txt)\""
        echo "-------------------------------------------"
    fi
done

rm -f ref usr out_usr.txt out_ref.txt

echo
if [ $pass_count -eq ${#tests[@]} ]; then
    echo "${GREEN}ALL TESTS PASSED 🎉${RESET}"
else
    echo "${RED}$(( ${#tests[@]} - pass_count )) TEST(S) FAILED ❌${RESET}"
fi