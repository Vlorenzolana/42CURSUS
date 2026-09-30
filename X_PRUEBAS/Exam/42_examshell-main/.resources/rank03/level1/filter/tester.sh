#!/bin/bash
source ../../../main/colors.sh

expected_file="filter.c"
rendu_dir="../../../../rendu/filter"

# Check if required files exist
if [ ! -f "$rendu_dir/$expected_file" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Missing file $expected_file$(tput sgr 0)"
    exit 1
fi

# Compile the program
echo "${BLUE}Compiling filter program...${RESET}"
gcc -Wall -Werror -Wextra -o filter_test "$rendu_dir/$expected_file" 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    exit 1
fi

# Compile reference (if exists)
if [ -f "filter.c" ]; then
    gcc -Wall -Werror -Wextra -o filter_ref filter.c 2>/dev/null
    has_reference=1
else
    has_reference=0
fi

# Test 1: Example from sub.txt - 'abcdefaaaabcdeabcabcdabc' with 'abc'
echo "${BLUE}Testing sub.txt example 1...${RESET}"
echo "abcdefaaaabcdeabcabcdabc" | ./filter_test "abc" > output1.txt 2>/dev/null
expected_output="***defaaa***de******d***"
actual_output=$(cat output1.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: sub.txt example 1 failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 2: Example from sub.txt - 'ababcabababc' with 'ababc'
echo "${BLUE}Testing sub.txt example 2...${RESET}"
echo "ababcabababc" | ./filter_test "ababc" > output2.txt 2>/dev/null
expected_output="*****ab*****"
actual_output=$(cat output2.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: sub.txt example 2 failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 3: Verify equivalence with sed 's/bonjour/*******/g'
echo "${BLUE}Testing equivalence with sed (bonjour)...${RESET}"
echo "bonjour world bonjour universe" | ./filter_test "bonjour" > output3.txt 2>/dev/null
expected_output="******* world ******* universe"
actual_output=$(cat output3.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: sed equivalence test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 4: Multiple consecutive matches
echo "${BLUE}Testing consecutive matches...${RESET}"
echo "abcabcabc" | ./filter_test "abc" > output4.txt 2>/dev/null
expected_output="*********"
actual_output=$(cat output4.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Consecutive matches failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 5: Empty input
echo "${BLUE}Testing empty input...${RESET}"
echo "" | ./filter_test "test" > output5.txt 2>/dev/null
expected_output=""
actual_output=$(cat output5.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Empty input test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 6: Long pattern
echo "${BLUE}Testing long pattern...${RESET}"
echo "this is a very long pattern to test replacement functionality" | ./filter_test "very long pattern" > output6.txt 2>/dev/null
expected_output="this is a ***************** to test replacement functionality"
actual_output=$(cat output6.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Long pattern test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected_output'"
    echo "${RED}Got:${RESET}      '$actual_output'"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 7: Newlines in input
echo "${BLUE}Testing newlines in input...${RESET}"
printf "line1\ntest line2\ntest line3" | ./filter_test "test" > output7.txt 2>/dev/null
expected_output="line1
**** line2
**** line3"
actual_output=$(cat output7.txt)
if [ "$actual_output" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Newlines test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET}"
    echo "$expected_output"
    echo "${RED}Got:${RESET}"
    echo "$actual_output"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Test 8: Wrong number of arguments
echo "${BLUE}Testing wrong number of arguments...${RESET}"
./filter_test > output8.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with wrong number of arguments$(tput sgr 0)"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

./filter_test arg1 arg2 > output8b.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with too many arguments$(tput sgr 0)"
    rm -f filter_test filter_ref output*.txt
    exit 1
fi

# Cleanup
rm -f filter_test filter_ref output*.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0