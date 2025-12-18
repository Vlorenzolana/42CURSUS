#!/bin/bash
source functions.sh
source colors.sh
clear
bash label.sh
printf "${BLUE}%s${RESET}\n" "┌─────────────────────────────────────────────────────────┐"
printf "${BLUE}%s${GREEN}%s${BLUE}%s${RESET}\n" "│" "  🎯 Choose your practice level for Exam 42 Rank 04  🎯  " "│"
printf "${BLUE}%s${RESET}\n" "└─────────────────────────────────────────────────────────┘"
printf "${CYAN}%s${RESET}\n" "∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼"
printf "${YELLOW}${BOLD}%s${RESET}\n" "🔥 1. Level1 - Intermediate Challenges"
printf "${YELLOW}${BOLD}%s${RESET}\n" "💎 2. Level2 - Advanced Problems"
printf "${YELLOW}${BOLD}%s${RESET}\n" "💎 3. Go Back to Menu"
printf "${CYAN}%s${RESET}\n" "∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼"
printf "${GREEN}${BOLD}Enter your choice (1-3): ${RESET}"
read opt

case $opt in
    menu)
        bash menu.sh
        ;;
    1)
        clear
        echo "$(tput setaf 2)$(tput bold)level1 is being prepared...$(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank04 level1
        ;;
    2) 
        mkdir ../../rendu
        clear
        echo "$(tput setaf 2)$(tput bold)level2 is being prepared...$(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank04 level2
        ;;
    exit)
        cd ../../../../
        rm -rf rendu
        clear
        exit
        ;;
    3)
        bash rank04_menu.sh
        ;;
    *)
        echo "$(tput setaf 1)Wrong input$(tput sgr0)"
        sleep 1
        bash rank04.sh
esac