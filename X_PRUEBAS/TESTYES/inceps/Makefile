COMPOSE_FILE = ./srcs/docker-compose.yml
DATA_PATH = /home/otmane/data

DOCKER_COMPOSE = docker-compose -f $(COMPOSE_FILE)

GREEN = \033[0;32m
RESET = \033[0m

all:
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	
	@echo "$(GREEN)Building Inception...$(RESET)"
	
	@printf "MariaDB    ... "
	@$(DOCKER_COMPOSE) build -q mariadb
	@echo "$(GREEN)✅$(RESET)"

	@printf "WordPress  ... "
	@$(DOCKER_COMPOSE) build -q wordpress
	@echo "$(GREEN)✅$(RESET)"

	@printf "NGINX      ... "
	@$(DOCKER_COMPOSE) build -q nginx
	@echo "$(GREEN)✅$(RESET)"

	@printf "Network    ... "
	@$(DOCKER_COMPOSE) up -d > /dev/null
	@echo "$(GREEN)✅$(RESET)"
	
	@echo "$(GREEN)All systems operational! 🚀$(RESET)"

up:
	@printf "Starting containers ... "
	@$(DOCKER_COMPOSE) up -d > /dev/null
	@echo "$(GREEN)✅$(RESET)"

down:
	@printf "Stopping containers ... "
	@$(DOCKER_COMPOSE) down > /dev/null
	@echo "$(GREEN)✅$(RESET)"

clean:
	@printf "Cleaning Docker     ... "
	@$(DOCKER_COMPOSE) down --rmi all -v > /dev/null
	@echo "$(GREEN)✅$(RESET)"

fclean: clean
	@printf "Cleaning Data       ... "
	@sudo rm -rf $(DATA_PATH)/mariadb/*
	@sudo rm -rf $(DATA_PATH)/wordpress/*
	@echo "$(GREEN)✅$(RESET)"
	@echo "$(GREEN)Deep clean complete.$(RESET)"

re: fclean all

logs:
	@$(DOCKER_COMPOSE) logs -f

ps:
	@$(DOCKER_COMPOSE) ps

.PHONY: all up down clean fclean re logs ps