#!/bin/bash

# 1. Read Secrets from files
SQL_PASSWORD=$(cat /run/secrets/db_password)
ADMIN_PASSWORD=$(cat /run/secrets/credentials)
USER1_PASS=$(cat /run/secrets/user1_password)

# 2. Wait for MariaDB (The Connection Loop)
while ! mariadb -h"mariadb" -u$SQL_USER -p$SQL_PASSWORD -e "SELECT 1;" >/dev/null 2>&1; do
    echo "Waiting for MariaDB connection..."
    sleep 1
done
echo "MariaDB is connected!"

# 3. Install WordPress
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    echo "Installing WordPress..."
    cd /var/www/wordpress

    wp core download --allow-root

    wp config create \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost=mariadb \
        --allow-root

    wp core install \
        --url=$DOMAIN_NAME \
        --title=$SITE_TITLE \
        --admin_user=$ADMIN_USER \
        --admin_password=$ADMIN_PASSWORD \
        --admin_email=$ADMIN_EMAIL \
        --allow-root

    # Create Second User using the secret password
    wp user create $USER1_LOGIN $USER1_EMAIL --role=author --user_pass=$USER1_PASS --allow-root
    
    echo "WordPress installed successfully."
else
    echo "WordPress is already installed."
fi

# 4. Start PHP-FPM
echo "Starting PHP-FPM..."
exec /usr/sbin/php-fpm8.2 -F