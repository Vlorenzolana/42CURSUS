#!/bin/bash
source ../../../main/colors.sh

file1=max.c
file2=../../../../rendu/max/max.c
main=main.c

compile() {
    gcc -Werror -Wall -Wextra -o out1 "$file1" "$main"
    gcc -Werror -Wall -Wextra -o out2 "$file2" "$main"
}

run_test() {
    test_args=("$@")
    test_number=$((++test_count))

    compile

    ./out1 "${test_args[@]}" > out1.txt 2>/dev/null
    ./out2 "${test_args[@]}" > out2.txt 2>/dev/null

    out1=$(cat out1.txt)
    out2=$(cat out2.txt)

    echo -e "\n${CYAN}Test $test_number:${RESET} ./out1 ${test_args[*]}"

    if ! diff -q out1.txt out2.txt >/dev/null; then
        echo "$(tput setaf 1)$(tput bold)FAIL$(tput sgr 0)"
        echo "${GREEN}Expected Output:${RESET} \"$out2\""
        echo "${RED}Your Output:${RESET}     \"$out1\""
        rm -f out1 out2 out1.txt out2.txt
        exit 1
    else
        echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
        echo "${YELLOW}Output:${RESET} \"$out1\""
    fi
}

test_count=0

# Add all your tests here
run_test "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification."
run_test "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "
run_test "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot"
run_test "Papache est un sabre" "a" "o"
run_test "zaz" "art" "zul"
run_test "zaz" "r" "u"
run_test "jacob" "a" "b" "c" "e"
run_test "ZoZ eT Dovid oiME le METol." "o" "a"
run_test "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e"
run_test "AkjhZ zLKIJz , 23y "
run_test "FOR PONY"
run_test "this        ...       is sparta, then again, maybe    not"
run_test "   "
run_test "a" "b"
run_test "  lorem,ipsum  "
run_test ""
run_test # no arguments

echo -e "\n${GREEN}All tests passed successfully!${RESET}"
rm -f out1 out2 out1.txt out2.txt

