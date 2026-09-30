# User Documentation

## 1. Services Provided
This stack provides a fully functional WordPress website running on a LEMP stack (Linux, NGINX, MariaDB, PHP).
* **Website:** A blog/CMS platform accessible via domain name.
* **Database:** A persistent SQL database storing all site content.
* **Security:** SSL/TLS encryption (HTTPS) is enforced.

## 2. Starting and Stopping
As a user, you can control the stack using the simplified Makefile commands:

* **Start the Site:**
    ```bash
    sudo make
    ```
    *Wait for the green checks ✅ to appear.*

* **Stop the Site:**
    ```bash
    sudo make down
    ```

## 3. Accessing the Website
Once the project is running:
* **Front End (Blog):** Open `https://otboumeh.42.fr` in your browser.
    *(Accept the security warning, as we use a self-signed certificate).*
* **Admin Panel:** Open `https://otboumeh.42.fr/wp-admin` to manage content.

## 4. Credentials
For security reasons, passwords are **not** displayed in the environment settings. 
Credentials for the **Administrator** and **Database Users** are located in the secure folder on the host machine:

* **Path:** `./srcs/secrets/`
* **Files:**
    * `credentials.txt` (WordPress Admin Password)
    * `db_password.txt` (Database User Password)
    * `db_root_password.txt` (Database Root Password)

## 5. Checking Service Status
To verify that the website and database are running correctly, you can run:
```bash
sudo make ps