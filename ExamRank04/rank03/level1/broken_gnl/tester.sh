#!/bin/bash
source ../../../main/colors.sh

# Test files
expected_files="get_next_line.c get_next_line.h"
rendu_dir="../../../../rendu/broken_gnl"

# Check if required files exist
for file in $expected_files; do
    if [ ! -f "$rendu_dir/$file" ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Missing file $file$(tput sgr 0)"
        exit 1
    fi
done

# Create test files
echo -e "Line 1\nLine 2\nLine 3" > test1.txt
echo -e "Single line" > test2.txt
echo -e "Empty\n\nLines" > test3.txt
echo -e "No newline at end" > test4.txt
truncate -s 0 empty.txt

# Create test program
cat > test_main.c << 'EOF'
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    
    char *line;
    int line_count = 0;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]", ++line_count, line);
        if (line[strlen(line) - 1] != '\n')
            printf("\\n");
        printf("\n");
        free(line);
    }
    
    printf("Total lines read: %d\n", line_count);
    close(fd);
    return 0;
}
EOF

# Test 1: Basic functionality
echo "${BLUE}Testing basic functionality...${RESET}"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 -o test_gnl test_main.c $rendu_dir/get_next_line.c 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    rm -f test*.txt empty.txt test_main.c
    exit 1
fi

./test_gnl test1.txt > output1.txt 2>/dev/null
expected_lines=$(wc -l < test1.txt)
if ! grep -q "Total lines read: $expected_lines" output1.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Wrong number of lines read$(tput sgr 0)"
    cat output1.txt
    rm -f test*.txt empty.txt test_main.c test_gnl output*.txt
    exit 1
fi

# Test 2: Single line file
echo "${BLUE}Testing single line...${RESET}"
./test_gnl test2.txt > output2.txt 2>/dev/null
if ! grep -q "Total lines read: 1" output2.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Single line test failed$(tput sgr 0)"
    rm -f test*.txt empty.txt test_main.c test_gnl output*.txt
    exit 1
fi

# Test 3: Empty lines
echo "${BLUE}Testing empty lines...${RESET}"
./test_gnl test3.txt > output3.txt 2>/dev/null
if ! grep -q "Total lines read: 3" output3.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Empty lines test failed$(tput sgr 0)"
    rm -f test*.txt empty.txt test_main.c test_gnl output*.txt
    exit 1
fi

# Test 4: Empty file
echo "${BLUE}Testing empty file...${RESET}"
./test_gnl empty.txt > output4.txt 2>/dev/null
if ! grep -q "Total lines read: 0" output4.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Empty file test failed$(tput sgr 0)"
    rm -f test*.txt empty.txt test_main.c test_gnl output*.txt
    exit 1
fi

# Test 5: Different buffer sizes
echo "${BLUE}Testing different buffer sizes...${RESET}"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 -o test_gnl_small test_main.c $rendu_dir/get_next_line.c 2>/dev/null
./test_gnl_small test1.txt > output5.txt 2>/dev/null
if ! grep -q "Total lines read: 3" output5.txt; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Small buffer size test failed$(tput sgr 0)"
    rm -f test*.txt empty.txt test_main.c test_gnl* output*.txt
    exit 1
fi

# Memory leak test (basic)
echo "${BLUE}Testing for basic memory management...${RESET}"
if command -v valgrind >/dev/null 2>&1; then
    valgrind --leak-check=full --error-exitcode=1 ./test_gnl test1.txt >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo "$(tput setaf 1)$(tput bold)FAIL: Memory leaks detected$(tput sgr 0)"
        rm -f test*.txt empty.txt test_main.c test_gnl* output*.txt
        exit 1
    fi
else
    echo "${YELLOW}Valgrind not available, skipping memory leak test${RESET}"
fi

# Cleanup
rm -f test*.txt empty.txt test_main.c test_gnl* output*.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0