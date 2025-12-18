#!/bin/bash
source functions.sh
source colors.sh
clear
bash label.sh
printf "${BLUE}%s${RESET}\n" "┌─────────────────────────────────────────────────────────┐"
printf "${BLUE}%s${GREEN}%s${BLUE}%s${RESET}\n" "│" "  🎯 Choose your practice level for Exam 42 Rank 02  🎯  " "│"
printf "${BLUE}%s${RESET}\n" "└─────────────────────────────────────────────────────────┘"
printf "${CYAN}%s${RESET}\n" "∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼"
printf "${YELLOW}${BOLD}%s${RESET}\n" "⭐ 1. Level0 - Foundation Exercises"
printf "${YELLOW}${BOLD}%s${RESET}\n" "🔥 2. Level1 - Intermediate Challenges"
printf "${YELLOW}${BOLD}%s${RESET}\n" "💎 3. Level2 - Advanced Problems"
printf "${YELLOW}${BOLD}%s${RESET}\n" "🏆 4. Level3 - Expert Level"
printf "${CYAN}%s${RESET}\n" "∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼∼"
printf "${GREEN}${BOLD}Enter your choice (1-4): ${RESET}"
read opt

case $opt in
    menu)
        bash menu.sh
        ;;
    1)
        clear
        echo "$(tput setaf 2)$(tput bold)level0 is being prepared $(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank02 level0
        ;;
    2)  
        mkdir ../../rendu
        clear
        echo "$(tput setaf 2)$(tput bold)level1 is being prepared...$(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank02 level1
        ;;
    3) 
        mkdir ../../rendu
        clear
        echo "$(tput setaf 2)$(tput bold)level2 is being prepared...$(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank02 level2
        ;;
    4)
        mkdir ../../rendu
        clear
        echo "$(tput setaf 2)$(tput bold)level3 is being prepared...$(tput sgr0)"
        display_animation
        clear
        bash level_base.sh rank02 level3
        ;;
    exit)
        cd ../../../../
        rm -rf rendu
        clear
        exit 1
        ;;
    *)
        echo "$(tput setaf 1)Wrong input$(tput sgr0)"
        sleep 1
        bash rank02.sh
esac
