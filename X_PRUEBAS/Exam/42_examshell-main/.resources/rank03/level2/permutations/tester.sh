#!/bin/bash
source ../../../main/colors.sh

expected_files="*.c *.h"
rendu_dir="../../../../rendu/permutations"

# Check if rendu directory exists
if [ ! -d "$rendu_dir" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Directory $rendu_dir does not exist$(tput sgr 0)"
    exit 1
fi

# Find C files in rendu directory
c_files=$(find "$rendu_dir" -name "*.c" -type f)
if [ -z "$c_files" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: No .c files found in $rendu_dir$(tput sgr 0)"
    exit 1
fi

# Compile the program
echo "${BLUE}Compiling permutations program...${RESET}"
gcc -Wall -Werror -Wextra -o permutations_test $c_files 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    exit 1
fi

# Test 1: Single character "a"
echo "${BLUE}Testing single character 'a'...${RESET}"
./permutations_test "a" > output1.txt 2>/dev/null
if [ "$(cat output1.txt)" != "a" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Single character 'a' should return 'a'$(tput sgr 0)"
    echo "Expected: a"
    echo "Got: $(cat output1.txt)"
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Test 2: Two characters "ab"
echo "${BLUE}Testing two characters 'ab'...${RESET}"
./permutations_test "ab" > output2.txt 2>/dev/null
expected2="ab
ba"
if [ "$(cat output2.txt)" != "$expected2" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Two characters 'ab' test failed$(tput sgr 0)"
    echo "Expected:"
    echo "$expected2"
    echo "Got:"
    cat output2.txt
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Test 3: Three characters "abc" (should be in alphabetical order)
echo "${BLUE}Testing three characters 'abc'...${RESET}"
./permutations_test "abc" > output3.txt 2>/dev/null
expected3="abc
acb
bac
bca
cab
cba"
if [ "$(cat output3.txt)" != "$expected3" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Three characters 'abc' test failed$(tput sgr 0)"
    echo "Expected:"
    echo "$expected3"
    echo "Got:"
    cat output3.txt
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Test 4: Count permutations for "abc" (should be 6)
lines=$(wc -l < output3.txt)
if [ $lines -ne 6 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: 'abc' should have 6 permutations, got $lines$(tput sgr 0)"
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Test 5: Different order input "bac"
echo "${BLUE}Testing different order input 'bac'...${RESET}"
./permutations_test "bac" > output5.txt 2>/dev/null
# Should still be in alphabetical order of permutations
expected5="abc
acb
bac
bca
cab
cba"
if [ "$(cat output5.txt)" != "$expected5" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Input 'bac' should produce alphabetically ordered permutations$(tput sgr 0)"
    echo "Expected:"
    echo "$expected5"
    echo "Got:"
    cat output5.txt
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Test 6: Four characters "abcd" (should be 4! = 24 permutations)
echo "${BLUE}Testing four characters 'abcd'...${RESET}"
./permutations_test "abcd" > output6.txt 2>/dev/null
lines=$(wc -l < output6.txt)
if [ $lines -ne 24 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: 'abcd' should have 24 permutations, got $lines$(tput sgr 0)"
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Check if all permutations are unique
unique_lines=$(sort output6.txt | uniq | wc -l)
if [ $unique_lines -ne 24 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: 'abcd' permutations should all be unique$(tput sgr 0)"
    echo "Got $unique_lines unique permutations out of $lines total"
    rm -f permutations_test output*.txt expected*.txt
    exit 1
fi

# Check if first few permutations are in correct alphabetical order
head -5 output6.txt > first5.txt
expected_first5="abcd
abdc
acbd
acdb
adbc"
if [ "$(cat first5.txt)" != "$expected_first5" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: First 5 permutations of 'abcd' not in correct order$(tput sgr 0)"
    echo "Expected:"
    echo "$expected_first5"
    echo "Got:"
    cat first5.txt
    rm -f permutations_test output*.txt expected*.txt first5.txt
    exit 1
fi

# Test 7: Empty string
echo "${BLUE}Testing empty string...${RESET}"
./permutations_test "" > output7.txt 2>/dev/null
lines=$(wc -l < output7.txt)
# Empty string should either produce no output or one empty line
if [ $lines -gt 1 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Empty string should produce at most 1 line$(tput sgr 0)"
    rm -f permutations_test output*.txt expected*.txt first5.txt
    exit 1
fi

# Test 8: Wrong number of arguments
echo "${BLUE}Testing wrong number of arguments...${RESET}"
./permutations_test > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with no arguments$(tput sgr 0)"
    rm -f permutations_test output*.txt expected*.txt first5.txt temp.txt
    exit 1
fi

./permutations_test "abc" "def" > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with too many arguments$(tput sgr 0)"
    rm -f permutations_test output*.txt expected*.txt first5.txt temp.txt
    exit 1
fi

# Test 9: Check that all permutations contain all original characters
echo "${BLUE}Testing character preservation...${RESET}"
while IFS= read -r line; do
    # Check if length matches original
    if [ ${#line} -ne 4 ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Permutation '$line' has wrong length$(tput sgr 0)"
        rm -f permutations_test output*.txt expected*.txt first5.txt temp.txt
        exit 1
    fi
    # Check if it contains exactly the characters a, b, c, d
    sorted_chars=$(echo "$line" | grep -o . | sort | tr -d '\n')
    if [ "$sorted_chars" != "abcd" ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Permutation '$line' doesn't contain exactly 'abcd'$(tput sgr 0)"
        rm -f permutations_test output*.txt expected*.txt first5.txt temp.txt
        exit 1
    fi
done < output6.txt

# Cleanup
rm -f permutations_test output*.txt expected*.txt first5.txt temp.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0