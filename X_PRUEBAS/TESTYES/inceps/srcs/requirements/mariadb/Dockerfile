FROM debian:bookworm

# Install MariaDB Server
RUN apt-get update -y && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Create the folder for the database socket and give permission
RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

# Copy the configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy the initialization script 
COPY tools/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

# Expose port 3306 (standard MySQL port)
EXPOSE 3306

# Start the script that launches MariaDB
ENTRYPOINT ["/usr/local/bin/script.sh"]
