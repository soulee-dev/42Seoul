FROM	debian:buster

RUN		apt-get update && \
		apt-get install -y mariadb-server mariadb-client

RUN		mkdir -p /var/run/mysqld
RUN		chown mysql:mysql /var/run/mysqld

COPY	./conf/my.cnf /etc/mysql/
COPY	./tools/entry.sh /

RUN		chmod +x /entry

ENTRYPOINT ["sh", "/entry.sh"]