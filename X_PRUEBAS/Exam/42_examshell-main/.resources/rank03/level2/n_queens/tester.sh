#!/bin/bash
source ../../../main/colors.sh

expe# Test 2: n=4 (should have exactly 2 solutions as per sub.txt)
echo "${BLUE}Testing n=4 (sub.txt example)...${RESET}"
./n_queens_test 4 > output2.txt 2>/dev/null
lines=$(wc -l < output2.txt)
if [ $lines -ne 2 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=4 should have exactly 2 solutions as specified in sub.txt, got $lines$(tput sgr 0)"
    cat output2.txt
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Verify the specific solutions from sub.txt: "1 3 0 2" and "2 0 3 1"
expected_solutions=("1 3 0 2" "2 0 3 1")
while IFS= read -r line; do
    found=false
    for expected in "${expected_solutions[@]}"; do
        if [ "$line" = "$expected" ]; then
            found=true
            break
        fi
    done
    if [ "$found" = false ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Unexpected solution for n=4: '$line'$(tput sgr 0)"
        echo "Expected solutions: ${expected_solutions[*]}"
        rm -f n_queens_test n_queens_ref output*.txt
        exit 1
    fi
done < output2.txt="*.c *.h"
rendu_dir="../../../../rendu/n_queens"

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
echo "${BLUE}Compiling n_queens program...${RESET}"
gcc -Wall -Werror -Wextra -o n_queens_test $c_files 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    exit 1
fi

# Compile reference if it exists
if [ -f "n_queens.c" ]; then
    gcc -Wall -Werror -Wextra -o n_queens_ref n_queens.c 2>/dev/null
    has_reference=1
else
    has_reference=0
fi

# Test 1: n=2 (should have no solution as per sub.txt)
echo "${BLUE}Testing n=2 (sub.txt example)...${RESET}"
./n_queens_test 2 > output1.txt 2>/dev/null
lines=$(wc -l < output1.txt)
if [ $lines -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=2 should have no solutions as specified in sub.txt, got $lines$(tput sgr 0)"
    cat output1.txt
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi
    exit 1
fi

# Test 2: n=2 (should have 0 solutions)
echo "${BLUE}Testing n=2...${RESET}"
./n_queens_test 2 > output2.txt 2>/dev/null
lines=$(wc -l < output2.txt)
if [ $lines -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=2 should have no solutions, got $lines$(tput sgr 0)"
    cat output2.txt
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Test 3: n=3 (should have 0 solutions)
echo "${BLUE}Testing n=3...${RESET}"
./n_queens_test 3 > output3.txt 2>/dev/null
lines=$(wc -l < output3.txt)
if [ $lines -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=3 should have no solutions, got $lines$(tput sgr 0)"
    cat output3.txt
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Test 4: n=4 (should have exactly 2 solutions)
echo "${BLUE}Testing n=4...${RESET}"
./n_queens_test 4 > output4.txt 2>/dev/null
lines=$(wc -l < output4.txt)
if [ $lines -ne 2 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=4 should have exactly 2 solutions, got $lines$(tput sgr 0)"
    cat output4.txt
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Check if solutions contain valid positions (0-3 for n=4)
while IFS= read -r line; do
    # Split line into positions and check each
    for pos in $line; do
        if ! [[ "$pos" =~ ^[0-3]$ ]]; then
            echo "$(tput setaf 1)$(tput bold)FAIL: Invalid position '$pos' in n=4 solution$(tput sgr 0)"
            echo "Line: $line"
            rm -f n_queens_test n_queens_ref output*.txt
            exit 1
        fi
    done
    # Check if we have exactly 4 positions
    pos_count=$(echo $line | wc -w)
    if [ $pos_count -ne 4 ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: n=4 solution should have 4 positions, got $pos_count$(tput sgr 0)"
        echo "Line: $line"
        rm -f n_queens_test n_queens_ref output*.txt
        exit 1
    fi
done < output4.txt

# Test 5: n=8 (should have 92 solutions)
echo "${BLUE}Testing n=8...${RESET}"
./n_queens_test 8 > output8.txt 2>/dev/null
lines=$(wc -l < output8.txt)
if [ $lines -ne 92 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=8 should have exactly 92 solutions, got $lines$(tput sgr 0)"
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Test 6: n=0 (should handle gracefully)
echo "${BLUE}Testing n=0...${RESET}"
./n_queens_test 0 > output0.txt 2>/dev/null
lines=$(wc -l < output0.txt)
if [ $lines -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=0 should have no solutions, got $lines$(tput sgr 0)"
    rm -f n_queens_test n_queens_ref output*.txt
    exit 1
fi

# Test 7: Wrong number of arguments
echo "${BLUE}Testing wrong number of arguments...${RESET}"
./n_queens_test > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with no arguments$(tput sgr 0)"
    rm -f n_queens_test n_queens_ref output*.txt temp.txt
    exit 1
fi

./n_queens_test 4 5 > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with too many arguments$(tput sgr 0)"
    rm -f n_queens_test n_queens_ref output*.txt temp.txt
    exit 1
fi

# Test 8: Check solution validity for n=4 (known solutions)
echo "${BLUE}Validating n=4 solutions...${RESET}"
# Known valid solutions for n=4: "1 3 0 2" and "2 0 3 1"
sort output4.txt > sorted4.txt
echo -e "1 3 0 2\n2 0 3 1" | sort > expected4.txt
if ! diff -q sorted4.txt expected4.txt >/dev/null; then
    echo "$(tput setaf 1)$(tput bold)FAIL: n=4 solutions don't match expected$(tput sgr 0)"
    echo "Expected:"
    cat expected4.txt
    echo "Got:"
    cat sorted4.txt
    rm -f n_queens_test n_queens_ref output*.txt temp.txt sorted4.txt expected4.txt
    exit 1
fi

# Cleanup
rm -f n_queens_test n_queens_ref output*.txt temp.txt sorted4.txt expected4.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0