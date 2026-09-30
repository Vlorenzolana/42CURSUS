#!/bin/bash

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Comprehensive Valgrind Test Script for ft_popen
echo -e "${BLUE}🔍 Running COMPREHENSIVE VALGRIND ANALYSIS${NC}"
echo "=========================================="
echo "Flags: --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes"
echo ""

# Compile the test
echo -e "${BLUE}📦 Compiling ft_popen...${NC}"
gcc -Wall -Wextra -Werror -std=c99 -o ft_popen main.c ft_popen.c

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilation failed!${NC}"
    exit 1
fi

echo -e "${GREEN}✅ Compilation successful!${NC}"
echo ""

# Compile reference solution
gcc -Wall -Wextra -Werror -std=c99 -o ref_ft_popen main.c ft_popen.c
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Reference compilation failed!${NC}"
    exit 1
fi

# Compile user solution
USER_C="../../../../rendu/ft_popen/ft_popen.c"
if [ ! -f "$USER_C" ]; then
    echo -e "${RED}❌ User solution not found: $USER_C${NC}"
    exit 1
fi
cp main.c user_main.c
cp "$USER_C" user_ft_popen.c
gcc -Wall -Wextra -Werror -std=c99 -o user_ft_popen user_main.c user_ft_popen.c
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ User compilation failed!${NC}"
    exit 1
fi

# Run both and capture output
./ref_ft_popen > ref_output.txt 2>&1
echo "[DEBUG] Reference output:"; cat ref_output.txt
./user_ft_popen > user_output.txt 2>&1
echo "[DEBUG] User output:"; cat user_output.txt

# Compare outputs
output_match=true
output_error_msg=""
if diff -q ref_output.txt user_output.txt > /dev/null; then
    echo -e "${GREEN}✅ Output matches reference!${NC}"
else
    echo -e "${RED}❌ Output does NOT match reference!${NC}"
    echo -e "${YELLOW}--- Reference Output ---${NC}"
    cat ref_output.txt
    echo -e "${YELLOW}--- Your Output ---${NC}"
    cat user_output.txt
    echo -e "${YELLOW}--- Diff ---${NC}"
    diff ref_output.txt user_output.txt
    output_match=false
    output_error_msg="Output does not match reference solution."
fi

# Run with comprehensive valgrind flags and capture output
echo -e "${BLUE}🚀 Executing comprehensive valgrind analysis...${NC}"
echo "Command: valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes ./ft_popen"
echo ""

# Capture valgrind output to analyze
valgrind_output=$(valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    -s \
    --track-fds=yes \
    --error-exitcode=1 \
    ./ft_popen 2>&1)

exit_code=$?

# Display the full output
echo "$valgrind_output"

echo ""
echo -e "${BLUE}🏁 Valgrind analysis completed with exit code: $exit_code${NC}"
echo ""

# Parse and analyze the output
echo "======================================="
echo -e "${YELLOW}📊 DETAILED ANALYSIS RESULTS:${NC}"
echo "======================================="

# Check for memory leaks
has_leaks=false
if echo "$valgrind_output" | grep -q "definitely lost:" && echo "$valgrind_output" | grep "definitely lost:" | grep -v "0 bytes"; then
    has_leaks=true
fi
if echo "$valgrind_output" | grep -q "indirectly lost:" && echo "$valgrind_output" | grep "indirectly lost:" | grep -v "0 bytes"; then
    has_leaks=true
fi
if echo "$valgrind_output" | grep -q "possibly lost:" && echo "$valgrind_output" | grep "possibly lost:" | grep -v "0 bytes"; then
    has_leaks=true
fi

# Check for open file descriptors
has_open_fds=false
if echo "$valgrind_output" | grep -q "FILE DESCRIPTORS" && echo "$valgrind_output" | grep -A 10 "FILE DESCRIPTORS" | grep -q "Open file descriptor"; then
    has_open_fds=true
fi

# Check for errors
has_errors=false
if echo "$valgrind_output" | grep -q "ERROR SUMMARY" && echo "$valgrind_output" | grep "ERROR SUMMARY" | grep -v "0 errors"; then
    has_errors=true
fi

# Display results with color coding
echo -n "Memory Leaks: "
if [ "$has_leaks" = true ]; then
    echo -e "${RED}DETECTED - You have memory leaks!${NC}"
else
    echo -e "${GREEN}PASSED - No memory leaks detected${NC}"
fi

echo -n "Open File Descriptors: "
if [ "$has_open_fds" = true ]; then
    echo -e "${RED}DETECTED - You have unclosed file descriptors!${NC}"
else
    echo -e "${GREEN}PASSED - All file descriptors properly closed${NC}"
fi

echo -n "Valgrind Errors: "
if [ "$has_errors" = true ]; then
    echo -e "${RED}DETECTED - Valgrind found errors!${NC}"
else
    echo -e "${GREEN}PASSED - No valgrind errors${NC}"
fi

echo ""
echo "======================================="
echo -n "OVERALL RESULT: "
if [ "$has_leaks" = false ] && [ "$has_open_fds" = false ] && [ "$has_errors" = false ] && [ "$output_match" = true ]; then
    echo -e "${GREEN}✅ ALL TESTS PASSED!${NC}"
    echo -e "${GREEN}Your ft_popen implementation is clean!${NC}"
else
    echo -e "${RED}❌ ISSUES DETECTED!${NC}"
    echo -e "${YELLOW}Summary of errors:${NC}"
    if [ "$has_leaks" = true ]; then
        echo -e "${RED}  → Memory leaks detected.${NC}"
    fi
    if [ "$has_open_fds" = true ]; then
        echo -e "${RED}  → Unclosed file descriptors detected.${NC}"
    fi
    if [ "$has_errors" = true ]; then
        echo -e "${RED}  → Valgrind errors detected.${NC}"
    fi
    if [ "$output_match" = false ]; then
        echo -e "${RED}  → Output does not match reference solution.${NC}"
    fi
fi
echo "======================================="

# Wait for user to press enter before continuing
read -rp "Press enter to continue..." dummy

# Cleanup temporary files
rm -f ref_ft_popen user_ft_popen user_main.c user_ft_popen.c ref_output.txt user_output.txt
