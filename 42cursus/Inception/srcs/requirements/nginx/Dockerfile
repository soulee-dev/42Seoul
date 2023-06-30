FROM		debian:buster

RUN			apt update && \
			apt upgrade && \
			apt install -y nginx openssl

RUN			sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
				-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=eunrlee"

COPY		./conf/default /etc/nginx/site-avaliable

EXPOSE		443

ENTRYPOINT	["nginx", "-g", "daemon off;"]