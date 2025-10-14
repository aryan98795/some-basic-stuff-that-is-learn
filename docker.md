To completely remove **all Docker containers, images, volumes, and networks**, you can run these commands. Be careful — this **deletes everything**.

---

### 1. Stop and remove all containers

```bash
docker stop $(docker ps -aq)
docker rm -f $(docker ps -aq)
```

### 2. Remove all images

```bash
docker rmi -f $(docker images -aq)
```

### 3. Remove all networks (except default ones)

```bash
docker network rm $(docker network ls | awk '/bridge|host|none/ {next} {print $1}')
```

### 4. Remove all volumes

```bash
docker volume rm $(docker volume ls -q)
```

---

### Optional: Clean up everything in **one command**

```bash
docker system prune -a --volumes --force
```

* `-a` → remove all unused images, not just dangling ones
* `--volumes` → remove all unused volumes
* `--force` → skip confirmation

After this, your Docker will be completely clean — no containers, images, networks, or volumes left.

---

```bash
docker system prune -a --volumes -f
```

**Explanation:**

* `docker system prune` → removes stopped containers, unused networks, dangling images.
* `-a` → also removes all unused images, not just dangling ones.
* `--volumes` → removes all unused volumes.
* `-f` → force, no confirmation prompt.

💡 Warning: This **deletes all your Docker data**, so make sure you don’t need anything.

```bash
docker rm -f $(docker ps -aq) && docker rmi -f $(docker images -aq) && docker volume rm $(docker volume ls -q) && docker network rm $(docker network ls -q)
```

**Explanation:**

1. `docker rm -f $(docker ps -aq)` → force-remove all containers (running or stopped).
2. `docker rmi -f $(docker images -aq)` → force-remove all images.
3. `docker volume rm $(docker volume ls -q)` → remove all volumes.
4. `docker network rm $(docker network ls -q)` → remove all networks.

⚠️ **Caution:** This **completely wipes your Docker setup**. Nothing can be recovered after this.
