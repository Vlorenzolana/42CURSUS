FROM debian:bookworm

# 1. Install NGINX and OpenSSL
RUN apt-get update -y && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# 2. Setup SSL Certificate folder
RUN mkdir -p /etc/nginx/ssl

# 3. Generate the SSL Certificate
# This creates a self-signed certificate for TLS 1.2/1.3
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=otboumeh.42.fr/UID=otboumeh"

# 4. Copy the NGINX configuration file
# (Make sure your 'conf/nginx.conf' file exists in your folder structure!)
COPY conf/nginx.conf /etc/nginx/nginx.conf

# 5. Create the folder for the NGINX PID file (required for NGINX to run)
RUN mkdir -p /var/run/nginx

# 6. Start NGINX in the foreground
# This is the compliant way (replaces 'tail -f').
CMD [ "nginx", "-g", "daemon off;" ]
