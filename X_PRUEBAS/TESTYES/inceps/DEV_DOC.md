# Developer Documentation

## 1. Environment Setup
To set up the development environment from scratch:

1.  **Domain Setup:** Ensure the domain is mapped in `/etc/hosts`:
    ```
    127.0.0.1 otboumeh.42.fr
    ```
2.  **Directory Structure:** The project relies on the `srcs` folder structure:
    * `requirements/`: Contains Dockerfiles for mariadb, nginx, and wordpress.
    * `secrets/`: Contains `.txt` files for passwords (must be created manually or via Makefile).
    * `docker-compose.yml`: Orchestrates the containers.

## 2. Build and Launch
We use `make` to automate Docker Compose commands.

* **Build & Start (Detached):**
    ```bash
    sudo make
    ```
    This creates the data directories at `/home/otmane/data/`, builds the images using Debian Bookworm, and starts the network.

* **Rebuild (Force Recreation):**
    If you edit a Dockerfile or a config file, force a rebuild:
    ```bash
    sudo make re
    ```

## 3. Managing Containers
* **View Logs:** Real-time logs for debugging:
    ```bash
    sudo make logs
    ```
* **Enter a Container:** To debug inside a running container:
    ```bash
    sudo docker exec -it wordpress bash
    # or
    sudo docker exec -it mariadb bash
    ```

## 4. Data Persistence & Storage
Data is persisted on the Host Machine using **Bind Mounts**. This ensures data survives even if containers are deleted.

* **Database Files:** Stored at `/home/otmane/data/mariadb`
* **WordPress Files:** Stored at `/home/otmane/data/wordpress`

**Docker Volumes Configuration:**
In `docker-compose.yml`, volumes are mapped as:
```yaml
volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/otmane/data/mariadb