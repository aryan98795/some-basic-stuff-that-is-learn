### ✅ Linux Directory Structure Explained

Linux has a **hierarchical file system** starting at the **root directory `/`**.

Here’s a simplified breakdown of common top-level directories:

---

## 📂 **Top-Level Linux Directories**

| Directory        | Purpose                                                   |
| ---------------- | --------------------------------------------------------- |
| `/`              | Root of the entire filesystem                             |
| `/bin`           | Essential **binary executables** (e.g., `ls`, `cp`)       |
| `/sbin`          | System binaries (e.g., `reboot`, `fsck`) — for root       |
| `/usr`           | User-installed programs and data                          |
| `/usr/bin`       | Most user commands (`gcc`, `python`, etc.)                |
| `/usr/lib`       | Libraries for `/usr/bin` programs                         |
| `/etc`           | System configuration files                                |
| `/home`          | User directories (`/home/aryan`, etc.)                    |
| `/root`          | Home directory for **root** user                          |
| `/var`           | Variable files (logs, mail, cache, etc.)                  |
| `/tmp`           | Temporary files (auto deleted)                            |
| `/dev`           | Device files (e.g., `/dev/sda1`, `/dev/null`)             |
| `/proc`          | Virtual filesystem for process and system info            |
| `/boot`          | Kernel and bootloader files                               |
| `/lib`           | Shared libraries needed by binaries in `/bin` and `/sbin` |
| `/mnt`, `/media` | Mount points for external devices (USB, CD)               |
| `/opt`           | Optional software packages                                |
| `/srv`           | Data for services (e.g., web server content)              |

---

## 🔹 Basic Navigation Commands

| Command             | Description                   |
| ------------------- | ----------------------------- |
| `ls`                | List files in directory       |
| `cd /path`          | Change directory              |
| `pwd`               | Print working directory       |
| `mkdir name`        | Make a new directory          |
| `rmdir name`        | Remove empty directory        |
| `rm -r name`        | Remove directory and contents |
| `find / -name file` | Search for a file             |

---

## 🔹 Example Tree

```
/
├── bin/
├── etc/
├── home/
│   ├── aryan/
│   └── user2/
├── usr/
│   └── bin/
├── var/
└── tmp/
```

---
