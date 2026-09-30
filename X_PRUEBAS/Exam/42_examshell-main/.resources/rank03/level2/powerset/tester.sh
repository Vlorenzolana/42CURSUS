#!/bin/bash
source ../../../main/colors.sh

expected_files="*.c *.h"
rendu_dir="../../../../rendu/powerset"

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
echo "${BLUE}Compiling powerset program...${RESET}"
gcc -Wall -Werror -Wextra -o powerset_test $c_files 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    exit 1
fi

# Test 1: Example from subject - powerset 3 1 0 2 4 5 3
echo "${BLUE}Testing example: powerset 3 1 0 2 4 5 3...${RESET}"
./powerset_test 3 1 0 2 4 5 3 > output1.txt 2>/dev/null
exit_code=$?
if [ $exit_code -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Program exited with error code $exit_code$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Check if output contains valid subsets that sum to 3
valid_found=0
while IFS= read -r line; do
    if [ -z "$line" ]; then
        # Empty line should represent empty subset (sum = 0)
        if [ "$1" == "0" ]; then
            valid_found=1
        fi
        continue
    fi
    
    # Calculate sum of numbers in this line
    sum=0
    for num in $line; do
        # Check if number is from the original set
        case "$num" in
            1|0|2|4|5|3) sum=$((sum + num)) ;;
            *) 
                echo "$(tput setaf 1)$(tput bold)FAIL: Invalid number '$num' not in original set$(tput sgr 0)"
                rm -f powerset_test output*.txt
                exit 1
                ;;
        esac
    done
    
    # Check if sum equals target (3)
    if [ $sum -eq 3 ]; then
        valid_found=1
    else
        echo "$(tput setaf 1)$(tput bold)FAIL: Subset '$line' sums to $sum, not 3$(tput sgr 0)"
        rm -f powerset_test output*.txt
        exit 1
    fi
done < output1.txt

if [ $valid_found -eq 0 ] && [ $(wc -l < output1.txt) -gt 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: No valid subsets found for target 3$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Test 2: Simple case - powerset 5 1 2 3 4 5
echo "${BLUE}Testing simple case: powerset 5 1 2 3 4 5...${RESET}"
./powerset_test 5 1 2 3 4 5 > output2.txt 2>/dev/null
# Possible subsets that sum to 5: [5], [1,4], [2,3]
lines=$(wc -l < output2.txt)
if [ $lines -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should find at least one subset summing to 5$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Validate each subset
while IFS= read -r line; do
    if [ -z "$line" ]; then
        continue
    fi
    
    sum=0
    prev_num=-1
    for num in $line; do
        # Check if number is from the original set
        case "$num" in
            1|2|3|4|5) sum=$((sum + num)) ;;
            *) 
                echo "$(tput setaf 1)$(tput bold)FAIL: Invalid number '$num' not in original set$(tput sgr 0)"
                rm -f powerset_test output*.txt
                exit 1
                ;;
        esac
        
        # Check order is preserved (should be in original set order)
        if [ $prev_num -ge 0 ] && [ $num -le $prev_num ]; then
            echo "$(tput setaf 1)$(tput bold)FAIL: Subset '$line' not in original order$(tput sgr 0)"
            rm -f powerset_test output*.txt
            exit 1
        fi
        prev_num=$num
    done
    
    if [ $sum -ne 5 ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Subset '$line' sums to $sum, not 5$(tput sgr 0)"
        rm -f powerset_test output*.txt
        exit 1
    fi
done < output2.txt

# Test 3: Target 0 (should include empty subset)
echo "${BLUE}Testing target 0 (empty subset): powerset 0 1 2 3...${RESET}"
./powerset_test 0 1 2 3 > output3.txt 2>/dev/null
# Should have at least one line (empty line for empty subset)
lines=$(wc -l < output3.txt)
if [ $lines -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Target 0 should include empty subset (empty line)$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Check if there's an empty line
if ! grep -q "^$" output3.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Target 0 should include empty line$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Test 4: Impossible target
echo "${BLUE}Testing impossible target: powerset 100 1 2 3...${RESET}"
./powerset_test 100 1 2 3 > output4.txt 2>/dev/null
lines=$(wc -l < output4.txt)
if [ $lines -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Impossible target should produce no output$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Test 5: Single element set
echo "${BLUE}Testing single element: powerset 5 5...${RESET}"
./powerset_test 5 5 > output5.txt 2>/dev/null
expected_output="5"
if [ "$(cat output5.txt)" != "$expected_output" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Single element test failed$(tput sgr 0)"
    echo "Expected: '$expected_output'"
    echo "Got: '$(cat output5.txt)'"
    rm -f powerset_test output*.txt
    exit 1
fi

# Test 6: Negative numbers
echo "${BLUE}Testing negative numbers: powerset 1 -1 2...${RESET}"
./powerset_test 1 -1 2 > output6.txt 2>/dev/null
# Should find subset [-1, 2] that sums to 1
found_solution=0
while IFS= read -r line; do
    if [ -z "$line" ]; then
        continue
    fi
    
    sum=0
    for num in $line; do
        sum=$((sum + num))
    done
    
    if [ $sum -eq 1 ]; then
        found_solution=1
        break
    fi
done < output6.txt

if [ $found_solution -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should find subset summing to 1 with negative numbers$(tput sgr 0)"
    rm -f powerset_test output*.txt
    exit 1
fi

# Test 7: Wrong number of arguments
echo "${BLUE}Testing wrong number of arguments...${RESET}"
./powerset_test > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with no arguments$(tput sgr 0)"
    rm -f powerset_test output*.txt temp.txt
    exit 1
fi

./powerset_test 5 > temp.txt 2>&1
exit_code=$?
if [ $exit_code -eq 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with only target argument$(tput sgr 0)"
    rm -f powerset_test output*.txt temp.txt
    exit 1
fi

# Cleanup
rm -f powerset_test output*.txt temp.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0