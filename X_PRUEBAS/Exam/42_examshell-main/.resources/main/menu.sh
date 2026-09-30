clear
# permisson
find ../rank02/level0 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank02/level1 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank02/level2 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank02/level3 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank03/level1 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank03/level2 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank04/level1 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank04/level2 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank05/level1 -name "tester.sh" -exec chmod +rwx {} \;
find ../rank05/level2 -name "tester.sh" -exec chmod +rwx {} \;

bash label.sh
bash intro.sh
