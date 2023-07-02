#!/bin/sh
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wpp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir -p /run/php

cd /var/www

wp core install --allow-root --path=/var/www \
	--url=$URL \
	--title=$TITLE \
	--admin_email=$ADMIN_EMAIL \
	--admin_user=$ADMIN_USER \
	--admin_password=$ADMIN_PASSWORD \
	--skip-email

wp user create -allow-root --path=/var/www \
	$USER_LOGIN \
	$USER_EMAIL \
	--role=author \
	--user_pass=$USER_PASS

sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

exec /usr/sbin/php-fpm7.3 -F