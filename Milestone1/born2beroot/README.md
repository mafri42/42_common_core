his project has been created as part of the 42 curriculum by masacco.
***
# 📚 BORN2BEROOT

***
## 📝 Description
Born2beroot is a system administration project that focuses on the creation and configuration of a secure virtual machine. The goal is to set up a server from scratch, implementing strict security protocols, user management, and system monitoring.

### Key Objectives:
- Deep understanding of virtualization (hypervisors).
- Setting up an OS with specific partitioning (LVM).
- Implementing a strict password policy and sudo rules.
- Configuring network security (SSH, Firewall).
- Writing a script for automated system monitoring.

---
## 🛠️ Instructions
1. Download the ISO: Obtain the latest stable version of Debian (or Rocky Linux).
2. Setup VM: Use VirtualBox or UTM to create a new machine.
3. Partitioning: Ensure you follow the LVM (Logical Volume Management) requirements.
4. Configuration: Run the setup for SSH (Port 4241), UFW/firewalld, and Password Policies.

## 🏗 Project Description & Choices

### Operating System
For this project, I chose to install **DEBIAN**. Below is a comparison of the two available choices:

| Feature | Debian | Rocky Linux |
| :--- | :--- | :--- |
| **System Type** | Independent (Community-driven) | RHEL-based (Enterprise-grade) |
| **Package Manager** | `apt` | `dnf` / `yum` |
| **Stability** | High (Conservative update cycle) | High (Binary compatible with RHEL) |
| **Learning Curve** | Moderate | Steeper (Stricter security defaults) |

**My Choice:** I chose **[Debian/Rocky]** because of its stability and the extensive community support, which is ideal for learning the basics of system administration.

---

### Main Design Choices

#### 1. Partitioning (LVM)
I configured the system using **LVM (Logical Volume Management)**. 
- **Purpose:** It provides a layer of abstraction over physical hard drives, allowing for dynamic resizing of partitions and better management of disk space without the need for reformatting.
- **Setup:** I created separate logical volumes for `/`, `/home`, `/var`, `/tmp`, and others to ensure that a localized data overflow doesn't crash the entire system.

#### 2. Security Policies & User Management
- **Sudo:** Implemented strict `sudo` configurations, including a custom log file located at `/var/log/sudo/`, a TTY requirement, and personalized error messages.
- **Password Policy:** Configured `libpam-pwquality` to enforce a minimum length of 10 characters, requiring uppercase, lowercase, and numbers, while preventing consecutive identical characters.
- **SSH:** Restricted SSH access to port **4242** and disabled `root` login to prevent brute-force attacks.

---

### Technical Comparisons

#### 🛡 AppArmor vs SELinux
* **AppArmor (My choice on Debian):** Uses path-based MAC (Mandatory Access Control). It is simpler to define security profiles for specific applications based on their file paths.
* **SELinux (Default on Rocky):** Uses label-based MAC. It is more granular and robust but requires a deeper understanding of security contexts and policy enforcement.

#### 🧱 UFW vs Firewalld
* **UFW (Uncomplicated Firewall):** A simplified command-line interface for `iptables`. It focuses on ease of use for managing simple rules.
* **Firewalld:** A dynamic firewall manager that supports "zones" to define the trust level of network connections. It allows configuration changes without breaking active sessions.

#### 💻 VirtualBox vs UTM
* **VirtualBox:** A powerful hypervisor that works across Windows, Linux, and Intel Macs. It offers extensive GUI tools for hardware management.
* **UTM:** A specialized hypervisor for macOS (Apple Silicon). It utilizes Apple's **Virtualization.framework** to achieve near-native performance on ARM-based chips.