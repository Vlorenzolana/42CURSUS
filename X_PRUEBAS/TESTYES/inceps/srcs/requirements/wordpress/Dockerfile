FROM debian:bookworm

# 1. Install PHP and dependencies
RUN apt-get update -y && \
    apt-get install -y php8.2 php8.2-fpm php8.2-mysql mariadb-client curl && \
    rm -rf /var/lib/apt/lists/*

# 2. Install WP-CLI (THIS WAS MISSING!)
# This tool allows the script to download and configure WordPress.
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# 3. Copy configuration files
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/wpscript.sh /usr/local/bin/

# 4. Permissions and setup
RUN chmod +x /usr/local/bin/wpscript.sh
RUN mkdir -p /var/www/wordpress

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wpscript.sh"]