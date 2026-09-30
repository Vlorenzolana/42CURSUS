#!/bin/bash

# 1. Read Secrets from files
SQL_PASSWORD=$(cat /run/secrets/db_password)
SQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# 2. Setup folders
mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld
chmod 777 /var/run/mysqld

# 3. Initialize DB if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    chown -R mysql:mysql /var/lib/mysql
    mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
fi

# 4. Start temporary server
mysqld_safe --skip-networking &
pid="$!"

echo "Waiting for MariaDB..."
until mysqladmin ping >/dev/null 2>&1; do
    sleep 1
done

# 5. Configure Database
mariadb -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
mariadb -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mariadb -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';"
mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mariadb -e "FLUSH PRIVILEGES;"

# 6. Stop temp server and start real server
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
wait "$pid"

echo "Starting MariaDB..."
exec mysqld