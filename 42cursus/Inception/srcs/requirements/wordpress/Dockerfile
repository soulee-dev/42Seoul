FROM	debian:buster

RUN		apt-get update && \
		apt-get install -y php7.3 php-fpm php7.3-mysql curl

RUN		mkdir -p /var/www
RUN		curl -O https://wordpress.org/latest.tar.gz
RUN		tar -xvf latest.tar.gz
RUN		mv /wordpress/* /var/www
RUN		chown -R www-data:www-data /var/www
RUN		rm -r /wordpress latest.tar.gz

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/
COPY	./conf/wp-config.php /var/www
COPY	./tools/entry.sh /

RUN		chmod +x /entry.sh

EXPOSE	9000

ENTRYPOINT	["sh", "/entry.sh"]