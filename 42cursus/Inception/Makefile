VOLUME_DIR=/home/soulee/data
DOCKER_COMPOSE=docker-compose
DOCKER_COMPOSE_FILE=./srcs/docker-compose.yml
PROJECT_NAME=Inception

all:
	mkdir -p $(VOLUME_DIR)/db
	mkdir -p $(VOLUME_DIR)/wordpress
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up --build -d

logs:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) logs

up:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up

down:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

clean: down
	docker system prune -f --all

fclean: clean
	rm -rf $(VOLUME_DIR)/db/*
	rm -rf $(VOLUME_DIR)/wordpress/*
	docker volume rm $$(docker volume ls -q)

re: fclean all

.PHONY:	all up down clean fclean re