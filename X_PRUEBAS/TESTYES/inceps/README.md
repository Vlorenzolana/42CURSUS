*This project has been created as part of the 42 curriculum by otboumeh.*

# 42 Inception

## Description
Inception is a System Administration project that aims to broaden knowledge of system administration by using **Docker**. The goal is to set up a small infrastructure composed of different services using **Docker Compose**. 

Instead of using pre-made images, we build our own Docker images from a base OS (Debian Bookworm) to understand how services like NGINX, WordPress, and MariaDB work under the hood.

## Instructions
### Prerequisites
* Docker Engine
* Docker Compose
* Make
* Sudo privileges

### Installation & Execution
1.  Clone the repository:
    ```bash
    git clone <repo_url> inception
    cd inception
    ```
2.  Build and start the project:
    ```bash
    sudo make
    ```
3.  Stop the project:
    ```bash
    sudo make down
    ```
4.  Clean everything (Delete data and containers):
    ```bash
    sudo make fclean
    ```

## Project Description & Design Choices
This project uses **Docker** to containerize services. Unlike Virtual Machines, which virtualize an entire operating system (including the kernel), Docker containers share the host's Linux kernel but run in isolated userspaces. This makes them lightweight and fast.

### Technical Comparisons

#### Virtual Machines vs Docker
* **Virtual Machines (VM):** Run a full OS (Guest OS) on top of a Hypervisor. They are heavy, slow to boot, and consume fixed hardware resources.
* **Docker:** Runs isolated processes (containers) sharing the Host Kernel. They are lightweight, start instantly, and only use resources they essentially need.

#### Secrets vs Environment Variables
* **Environment Variables (.env):** easy to use but insecure for sensitive data. Anyone running `docker inspect` can see the passwords in plain text.
* **Docker Secrets:** The secure standard. Passwords are stored in files on the host and mounted into the container at `/run/secrets/`. They never appear in environment logs or inspection. **This project uses Docker Secrets for maximum security.**

#### Docker Network vs Host Network
* **Host Network:** The container shares the host’s IP and port space directly. No isolation.
* **Docker Network (Bridge):** Containers get their own internal IP addresses and can talk to each other by name (DNS). We use a custom bridge network (`inception`) so services can communicate securely without being exposed to the outside world unnecessarily.

#### Docker Volumes vs Bind Mounts
* **Docker Volumes:** Storage managed entirely by Docker (usually deep in `/var/lib/docker`). Harder to access manually.
* **Bind Mounts:** Maps a specific folder on your Host Machine (e.g., `/home/otmane/data`) to a folder inside the container. We use Bind Mounts so we can easily verify, backup, or modify data directly from the host.

## Resources
* [Docker Documentation](https://docs.docker.com/)
* [MariaDB Knowledge Base](https://mariadb.com/kb/en/)
* [WordPress CLI Commands](https://developer.wordpress.org/cli/commands/)
* [NGINX Configuration Guide](https://nginx.org/en/docs/)

### AI Usage
AI tools (Gemini) were used in this project for:
* Debugging complex Docker Compose networking issues.
* Optimizing bash scripts (`wpscript.sh`) to properly handle database connection loops.
* Refactoring the project architecture to migrate from `.env` variables to Docker Secrets.
* Drafting the documentation structure.