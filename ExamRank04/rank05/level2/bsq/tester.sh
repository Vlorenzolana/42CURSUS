#!/bin/bash

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}🔍 Running COMPREHENSIVE TESTING for bsq${NC}"
echo "=========================================="
echo ""

# Paths
RANDOM_FOLDER="../../../../rendu/bsq"

# Check if user solution exists
if [ ! -d "$RANDOM_FOLDER" ]; then
    echo -e "${RED}❌ User rendu folder not found!${NC}"
    exit 1
fi

USER_C_FILES=$(find "$RANDOM_FOLDER" -name "*.c")
USER_H_FILES=$(find "$RANDOM_FOLDER" -name "*.h")

if [ -z "$USER_C_FILES" ] || [ -z "$USER_H_FILES" ]; then
    echo -e "${RED}❌ User solution not found: No .c or .h files${NC}"
    exit 1
fi

# Copy tester main to temporary file
cp main.c temp_main.c

# Copy user files into working folder
cp "$RANDOM_FOLDER"/* .

# Compile reference solution
echo -e "${BLUE}📦 Compiling reference solution...${NC}"
gcc -Wall -Wextra -Werror -std=c99 -o ref_bsq temp_main.c bsq.c
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Reference compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}✅ Reference compilation successful!${NC}"
echo ""

# Compile user solution
echo -e "${BLUE}📦 Compiling user solution...${NC}"
gcc -Wall -Wextra -Werror -std=c99 -o user_bsq temp_main.c bsq.c
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ User compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}✅ User compilation successful!${NC}"
echo ""

# Create test maps if missing
cat > test1.map << 'EOF'
9 . o x
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
EOF

cat > test2.map << 'EOF'
5 . # O
.....
.....
.....
.....
.....
EOF

cat > test3.map << 'EOF'
3 a b c
aaa
aaa
aaa
EOF

# Function to run tests
run_test() {
    local num=$1
    local file=$2
    echo -e "${BLUE}🚀 Running Test $num...${NC}"
    ./ref_bsq "$file" > "ref_output${num}.txt" 2>&1
    ./user_bsq "$file" > "user_output${num}.txt" 2>&1

    if diff -q "ref_output${num}.txt" "user_output${num}.txt" > /dev/null; then
        echo -e "${GREEN}✅ Test $num output matches reference!${NC}"
        return 0
    else
        echo -e "${RED}❌ Test $num output does NOT match reference!${NC}"
        echo -e "${YELLOW}--- Diff ---${NC}"
        diff "ref_output${num}.txt" "user_output${num}.txt"
        return 1
    fi
}

# Run all tests
tests_passed=true
for i in 1 2 3; do
    run_test "$i" "test${i}.map" || tests_passed=false
done

# Standard input test
echo -e "${BLUE}🚀 Running Test 4 (stdin)...${NC}"
./ref_bsq < test1.map > ref_output4.txt 2>&1
./user_bsq < test1.map > user_output4.txt 2>&1
if diff -q ref_output4.txt user_output4.txt > /dev/null; then
    echo -e "${GREEN}✅ Test 4 output matches reference!${NC}"
else
    echo -e "${RED}❌ Test 4 output does NOT match reference!${NC}"
    diff ref_output4.txt user_output4.txt
    tests_passed=false
fi

# Valgrind check
echo -e "${BLUE}🚀 Running Valgrind memory check...${NC}"
valgrind_output=$(valgrind --leak-check=full --show-leak-kinds=all -s ./user_bsq test1.map 2>&1)
valgrind_exit=$?

echo "$valgrind_output"

if echo "$valgrind_output" | grep -q "definitely lost:" && ! echo "$valgrind_output" | grep -q "definitely lost: 0 bytes"; then
    echo -e "${RED}❌ Memory leaks detected!${NC}"
    tests_passed=false
else
    echo -e "${GREEN}✅ No memory leaks detected.${NC}"
fi

# Summary
echo "======================================="
if [ "$tests_passed" = true ]; then
    echo -e "${GREEN}✅ PASSED!${NC}"
else
    echo -e "${RED}❌ SOME TESTS FAILED!${NC}"
fi
echo "======================================="

# Cleanup
rm -f temp_main.c user_bsq ref_bsq
