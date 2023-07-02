#!/bin/sh
mysql_install_db --user=root

echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME};
FLUSH PRIVILEGES;
USE ${DB_NAME};
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON * TO '${DB_USER}'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${ROOT_PASSWORD}';" > db.sql

mysqld -uroot --bootstrap < db.sql
mysqld -uroot