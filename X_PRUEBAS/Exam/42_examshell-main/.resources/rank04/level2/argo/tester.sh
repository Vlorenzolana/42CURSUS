#!/bin/bash
# Colors (basic, no external file needed)
RED="$(tput setaf 1)$(tput bold)"
GREEN="$(tput setaf 2)$(tput bold)"
YELLOW="$(tput setaf 3)$(tput bold)"
RESET="$(tput sgr0)"

# Paths
REF="argo.c"
USR="../../../../rendu/argo/argo.c"

# Compile both versions
echo "${YELLOW}Compiling reference...${RESET}"
if ! gcc -Wall -Wextra -Werror -o ref "$REF"; then
    echo "${RED}Reference compilation failed!${RESET}"
    exit 1
fi

echo "${YELLOW}Compiling your version...${RESET}"
if ! gcc -Wall -Wextra -Werror -o usr "$USR"; then
    echo "${RED}Your compilation failed!${RESET}"
    rm -f ref
    exit 1
fi

# Tests to run
tests=(
    '1'
    '"bonjour"'
    '"escape! \" "'
    '{"tomatoes":42,"potatoes":234}'
    '{"recursion":{"recursion":{"recursion":{"recursion":"recursion"}}}}'
    '"unfinished string'
    '"unfinished string 2\""'
    '{"no value?":}'
)

echo
echo "${YELLOW}Running tests...${RESET}"
pass_count=0

for input in "${tests[@]}"; do
    # Run both and capture output
    echo -n "$input" | ./usr /dev/stdin > out_usr.txt 2>/dev/null
    echo -n "$input" | ./ref /dev/stdin > out_ref.txt 2>/dev/null

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

# Cleanup
rm -f ref usr out_usr.txt out_ref.txt

echo
if [ $pass_count -eq ${#tests[@]} ]; then
    echo "${GREEN}ALL TESTS PASSED 🎉${RESET}"
else
    echo "${RED}$(( ${#tests[@]} - pass_count )) TEST(S) FAILED ❌${RESET}"
fi

