#!/bin/bash
source colors.sh

rank=$1
level=$2

base_dir="$(cd "$(dirname "$0")" && pwd)"

# Set question array based on rank and level
if [[ "$rank" == "rank02" ]]; then
    if [[ "$level" == *"level0"* ]]; then
        qsub=(first_word fizzbuzz ft_putstr ft_strcpy ft_strlen ft_swap repeat_alpha rev_print rot_13 rotone search_and_replace ulstr)
    elif [[ "$level" == *"level1"* ]]; then
        qsub=(alpha_mirror camel_to_snake print_bits do_op ft_atoi ft_strcmp reverse_bits ft_strrev ft_strcspn ft_strdup inter is_power_of_2 last_word max snake_to_camel swap_bits union wdmatch)
    elif [[ "$level" == *"level2"* ]]; then
        qsub=(add_prime_sum epur_str expand_str ft_list_size ft_atoi_base ft_range ft_rrange hidenp lcm paramsum pgcd print_hex rstr_capitalizer str_capitalizer tab_mult)
    elif [[ "$level" == *"level3"* ]]; then
        qsub=(flood_fill fprime ft_itoa ft_split rev_wstr rostring ft_list_foreach sort_int_tab sort_list ft_list_remove_if)
    else
        echo "Invalid level: $level for rank02"
        exit 1
    fi
elif [[ "$rank" == "rank03" ]]; then
    if [[ "$level" == *"level1"* ]]; then
        qsub=(broken_gnl filter scanf)
    elif [[ "$level" == *"level2"* ]]; then
        qsub=(n_queens permutations powerset rip tsp)
    else
        echo "Invalid level: $level for rank03"
        exit 1
    fi
elif [[ "$rank" == "rank04" ]]; then
    if [[ "$level" == *"level1"* ]]; then
        qsub=(ft_popen picoshell sandbox)
    elif [[ "$level" == *"level2"* ]]; then
        qsub=(argo vbc)
    else
        echo "Invalid level: $level for rank04"
        exit 1
    fi
else
    echo "Invalid rank: $rank"
    exit 1
fi

# Shuffle questions manually
shuffle_array() {
    local i tmp size max rand
    size=${#qsub[*]}
    max=$(( 32768 / size * size ))

    for ((i = size - 1; i > 0; i--)); do
        while (( (rand = RANDOM) >= max )); do :; done
        rand=$(( rand % (i + 1) ))
        tmp=${qsub[i]}
        qsub[i]=${qsub[rand]}
        qsub[rand]=$tmp
    done
    shuffled=("${qsub[@]}")
}

shuffle_array
num=${#shuffled[@]}
i=0
cd "../$rank/$level/${shuffled[$i]}"

while true; do
    cd "../${shuffled[$i]}"
    mkdir -p "$base_dir/../../rendu/${shuffled[$i]}"

   # Copy question files if needed
if [[ "$rank" == "rank03" && "$level" == *"level1"* ]]; then
    if [ -f "broken_gnl.c" ]; then
        cp "broken_gnl.c" "$base_dir/../../rendu/${shuffled[$i]}/broken_gnl.c"
    fi
elif [[ "$rank" == "rank04" && "$level" == *"level2"* ]]; then
    if [ -f "given.c" ]; then
        cp "given.c" "$base_dir/../../rendu/${shuffled[$i]}/given.c"
    fi
    touch "$base_dir/../../rendu/${shuffled[$i]}/${shuffled[$i]}.c"
else
    touch "$base_dir/../../rendu/${shuffled[$i]}/${shuffled[$i]}.c"
fi

    subject=$(cat sub.txt)

    # Check if all questions are completed
    if [ $i -ge $num ]; then
        clear
        echo "These questions at $level are completed."
        echo "=============================================="
        read -rp "${GREEN}${BOLD}Please press enter for return to the menu.${RESET}" enterx
        sleep 2
        cd ../../main
        bash menu.sh
        exit
    fi

    # Inner loop for testing or navigating
    while true; do
        clear
        echo -e "${WHITE}$subject${RESET}"
        echo
        echo "Please type 'test' to test code, 'next' for next or 'exit' for exit."
        echo
        read -rp "/>" input
        case $input in
            next)
                i=$((i+1))
                break
                ;;
            test)
                clear
                ./tester.sh &
                pid=$!
                slept=0

                while [ $slept -lt 10 ] && kill -0 $pid 2>/dev/null; do
                    sleep 1
                    slept=$((slept+1))
                done

                if kill -0 $pid 2>/dev/null; then
                    echo "$(tput setaf 1)$(tput bold)TIMEOUT$(tput sgr 0)"
                    echo "It can be because of infinite loop ∞"
                    echo "Please check your code or just try again."
                    kill $pid 2>/dev/null
                fi

                echo "=============================================="
                read -rp "${GREEN}${BOLD}Please press enter to continue your practice.${RESET}" enter
                break
                ;;
            menu)
                cd ../../../../
                if [ -d rendu ]; then
                    mkdir -p trace
                    cp -r rendu "trace/rendu_backup_$(date +%s)"
                    rm -rf rendu
                fi
                cd .resources/main
                bash menu.sh
                exit
                ;;
            exit)
                cd ../../../../
                if [ -d rendu ]; then
                    mkdir -p trace
                    cp -r rendu "trace/rendu_backup_$(date +%s)"
                    rm -rf rendu
                fi
                exit 1
                ;;
            *)
                echo "Please type 'test' to test code, 'next' for next or 'exit' to quit."
                ;;
        esac
    done
done
