FROM		debian:buster

RUN			apt-get update && \
			apt-get install -y nginx openssl

RUN			openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
			-keyout /etc/ssl/private/nginx-selfsigned.key \
			-out /etc/ssl/certs/nginx-selfsigned.crt \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=soulee"

COPY		./conf/default /etc/nginx/sites-available

EXPOSE		443

ENTRYPOINT	["nginx", "-g", "daemon off;"]