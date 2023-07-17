FROM	debian:buster

RUN		apt-get update && \
		apt-get install -y mariadb-server mariadb-client && \
		apt-get install -y dumb-init

RUN		mkdir -p /var/run/mysqld
RUN		chown mysql:mysql /var/run/mysqld

COPY	./conf/my.cnf /etc/mysql/
COPY	./tools/entry.sh /

RUN		chmod +x /entry.sh

EXPOSE	3306

ENTRYPOINT	["/usr/bin/dumb-init", "--", "/entry.sh"]