#!/bin/bash
source functions.sh
source colors.sh

run_level() {
    level=$1
    clear
    echo "$(tput setaf 2)$(tput bold)Level $level is being prepared...$(tput sgr0)"
    display_animation
    clear
    until bash rank05_exam_mode.sh rank05 level$level; do
        echo "$(tput setaf 1)Test failed. Try again.$(tput sgr0)"
        read -p "Press Enter to retry Level $level..."
        clear
    done
    echo "$(tput setaf 2)✔️  Level $level passed!$(tput sgr0)"
    sleep 1
}

start_exam() {
    clear
    bash label.sh
    echo "$(tput setaf 2)$(tput bold)🧪 Welcome to the Rank05 Exam!$(tput sgr0)"
    echo "=================================================="
    sleep 1

    for level in 1 2; do
        mkdir -p ../../rendu 
        run_level $level
    done

    echo "=================================================="
    echo "$(tput setaf 2)$(tput bold)🎉 Congratulations! You passed the Rank05 exam!$(tput sgr0)"
    echo "=================================================="

    # Backup rendu folder
    if [ -d "../../rendu" ]; then
        timestamp=$(date +%Y%m%d_%H%M%S)
        mkdir -p ../../exam
        cp -r ../../rendu "../../exam/rendu_backup_$timestamp"
        echo -e "${CYAN}📁 rendu folder backed up to: exam/rendu_backup_$timestamp${RESET}"
        
        # Clean after backup
        rm -rf ../../rendu
        echo -e "${RED}🗑️  rendu folder has been cleared after successful exam.${RESET}"
    fi

    # Ask to retry
    echo
    read -rp "$(echo -e ${YELLOW}${BOLD}"Do you want to retry the exam? (y/n): "${RESET})" retry
    case "$retry" in
        y|Y)
            echo -e "${YELLOW}🔄 Restarting the exam...${RESET}"
            sleep 1
            bash rank05.sh
            ;;
        *)
            echo -e "${GREEN}Goodbye!${RESET}"
            exit 0
            ;;
    esac
}

start_exam  # Call the function
