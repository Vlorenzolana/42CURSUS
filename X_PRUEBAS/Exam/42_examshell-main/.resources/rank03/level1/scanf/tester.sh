#!/bin/bash
source ../../../main/colors.sh

expected_file="ft_scanf.c"
rendu_dir="../../../../rendu/scanf"

# Check if required files exist
if [ ! -f "$rendu_dir/$expected_file" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Missing file $expected_file$(tput sgr 0)"
    exit 1
fi

# Create test main program
cat > test_main.c << 'EOF'
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

// Include the ft_scanf function from student's file
extern int ft_scanf(const char *, ...);

int main(void)
{
    printf("Testing ft_scanf implementation...\n");
    return 0;
}
EOF

# Create individual test programs
cat > test1.c << 'EOF'
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

extern int ft_scanf(const char *, ...);

int main(void)
{
    int num;
    char str[100];
    char c;
    
    // Test: %d %s %c
    int result = ft_scanf("%d %s %c", &num, str, &c);
    printf("%d %d [%s] [%c]\n", result, num, str, c);
    return 0;
}
EOF

cat > test2.c << 'EOF'
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

extern int ft_scanf(const char *, ...);

int main(void)
{
    char str1[100];
    char str2[100];
    
    // Test: %s %s
    int result = ft_scanf("%s %s", str1, str2);
    printf("%d [%s] [%s]\n", result, str1, str2);
    return 0;
}
EOF

cat > test3.c << 'EOF'
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

extern int ft_scanf(const char *, ...);

int main(void)
{
    int num1, num2, num3;
    
    // Test: %d %d %d
    int result = ft_scanf("%d %d %d", &num1, &num2, &num3);
    printf("%d %d %d %d\n", result, num1, num2, num3);
    return 0;
}
EOF

cat > test4.c << 'EOF'
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

extern int ft_scanf(const char *, ...);

int main(void)
{
    char c1, c2, c3;
    
    // Test: %c%c%c (no spaces)
    int result = ft_scanf("%c%c%c", &c1, &c2, &c3);
    printf("%d [%c] [%c] [%c]\n", result, c1, c2, c3);
    return 0;
}
EOF

# Compile tests
echo "${BLUE}Compiling ft_scanf tests...${RESET}"
gcc -Wall -Werror -Wextra -o test1 test1.c "$rendu_dir/$expected_file" 2>/dev/null
if [ $? -ne 0 ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Compilation error$(tput sgr 0)"
    rm -f test*.c test1 test2 test3 test4
    exit 1
fi

gcc -Wall -Werror -Wextra -o test2 test2.c "$rendu_dir/$expected_file" 2>/dev/null
gcc -Wall -Werror -Wextra -o test3 test3.c "$rendu_dir/$expected_file" 2>/dev/null
gcc -Wall -Werror -Wextra -o test4 test4.c "$rendu_dir/$expected_file" 2>/dev/null

# Test 1: Mixed types (%d %s %c)
echo "${BLUE}Testing mixed types (%d %s %c)...${RESET}"
echo "42 hello a" | ./test1 > output1.txt 2>/dev/null
expected="3 42 [hello] [a]"
actual=$(cat output1.txt)
if [ "$actual" != "$expected" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Mixed types test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected'"
    echo "${RED}Got:${RESET}      '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Test 2: Multiple strings (%s %s)
echo "${BLUE}Testing multiple strings (%s %s)...${RESET}"
echo "first second" | ./test2 > output2.txt 2>/dev/null
expected="2 [first] [second]"
actual=$(cat output2.txt)
if [ "$actual" != "$expected" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Multiple strings test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected'"
    echo "${RED}Got:${RESET}      '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Test 3: Multiple integers (%d %d %d)
echo "${BLUE}Testing multiple integers (%d %d %d)...${RESET}"
echo "123 456 789" | ./test3 > output3.txt 2>/dev/null
expected="3 123 456 789"
actual=$(cat output3.txt)
if [ "$actual" != "$expected" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Multiple integers test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected'"
    echo "${RED}Got:${RESET}      '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Test 4: Characters without spaces (%c%c%c)
echo "${BLUE}Testing characters without spaces (%c%c%c)...${RESET}"
echo "abc" | ./test4 > output4.txt 2>/dev/null
expected="3 [a] [b] [c]"
actual=$(cat output4.txt)
if [ "$actual" != "$expected" ]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Characters without spaces test failed$(tput sgr 0)"
    echo "${GREEN}Expected:${RESET} '$expected'"
    echo "${RED}Got:${RESET}      '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Test 5: Invalid input (partial match)
echo "${BLUE}Testing invalid input...${RESET}"
echo "abc hello world" | ./test1 > output5.txt 2>/dev/null
# Should fail to convert the first integer
actual=$(cat output5.txt)
if [[ "$actual" == "3 "* ]]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should fail with invalid integer$(tput sgr 0)"
    echo "${RED}Got:${RESET} '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Test 6: EOF handling
echo "${BLUE}Testing EOF handling...${RESET}"
echo -n "" | ./test1 > output6.txt 2>/dev/null
actual=$(cat output6.txt)
# Should return 0 conversions on EOF
if [[ "$actual" == "3 "* ]]; then
    echo "$(tput setaf 1)$(tput bold)FAIL: Should handle EOF correctly$(tput sgr 0)"
    echo "${RED}Got:${RESET} '$actual'"
    rm -f test*.c test1 test2 test3 test4 output*.txt
    exit 1
fi

# Cleanup
rm -f test*.c test1 test2 test3 test4 output*.txt

echo "$(tput setaf 2)$(tput bold)PASSED 🎉$(tput sgr 0)"
exit 0