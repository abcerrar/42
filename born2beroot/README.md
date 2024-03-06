# born2beroot Project

## Introduction
The born2beroot project is part of the curriculum at 42 coding school. The main objective of this project is to configure a Debian machine with various system administration tasks and techniques. Although there are no files uploaded to the repository, the project involves configuring a Debian machine with the following tasks:

- Change the hostname
- Implement a strong password policy
- Manage user groups
- Password policies
- Configure UFW (Uncomplicated Firewall)
- Configure SSH
- Create a script that runs every 10 minutes displaying system information

## Requirements
To complete the born2beroot project, you will need access to a Debian-based system and basic knowledge of system administration concepts.

## Configuration Steps
1. **Changing the hostname:** Modify the hostname of the machine to a desired value using the `hostnamectl` command.

2. **Implementing a strong password policy:** Update the password policy configuration file (`/etc/pam.d/common-password`) to enforce strong password rules such as minimum length, complexity, expiration, etc.

3. **Managing user groups:** Use the `adduser` and `usermod` commands to create and manage user groups as needed.

4. **Password policies:** Configure password policies using the `pam_pwquality` module to enforce password strength requirements.

5. **Configuring UFW:** Set up UFW (Uncomplicated Firewall) to manage firewall rules and secure network traffic according to project requirements.

6. **Configuring SSH:** Modify the SSH configuration file (`/etc/ssh/sshd_config`) to enhance security by disabling root login, limiting SSH access to specific users, and configuring SSH key-based authentication.

7. **Creating a system information script:** Write a script that collects system information (e.g., CPU usage, memory usage, disk space) and displays it to the user. Schedule the script to run every 10 minutes using cron.

## Usage
Follow the steps outlined above to configure the Debian machine according to the born2beroot project requirements.

## Contributing
Contributions to born2beroot are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request with your changes.

## License
This project is licensed under the [MIT License](LICENSE).

