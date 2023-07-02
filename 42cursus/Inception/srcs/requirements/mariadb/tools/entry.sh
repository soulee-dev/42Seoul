#!/bin/sh
mysql_install_db --user=root

echo \
"
CREATE DATABASE ${DB_NAME};
USE ${DB_NAME};
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON * TO '${DB_USER}'@'%' WITH GRANT OPTION:
ALTER USER 'root'@'localhost' IDENTIFIED BY '${ROOT_PASSWORD}';
FLUSH PRIVILEGES;
" > db.sql


mysql -uroot --bootstrap < db.sql
mysql -uroot