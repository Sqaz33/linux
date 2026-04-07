# Users and Groups

**Пользователь** — это субъект, от имени которого:

* запускаются процессы
* принадлежат файлы и каталоги
* применяются права доступа
* ведётся аудит и логировани

Managing users is done for the purpose of security by limiting access in certain specific ways. The [superuser](https://en.wikipedia.org/wiki/Superuser "wikipedia:Superuser") (root) has complete access to the operating system and its configuration; it is intended for administrative use only.

Users may be grouped together into a "group", and users may be added to an existing group to utilize the privileged access it grants.

## Permissions and ownership

Every file on a GNU/Linux system is owned by a user and a group. Three types of access permissions: read, write, and execute. Different access permissions can be applied to a file's owning user, owning group, and others (those without ownership).

`$ ls -l .`

```
➜  linux git:(master) ls -l
total 8
drwxrwxrwx 1 user1 user1 4096 Dec 21 14:07 examples
-rwxrwxrwx 1 user1 user1  471 Dec 21 13:56 terminal.md
```

Permissions, owner user, owner group.

Permissions: owning user, owning group, and others.

## User management

`who`, `whoami`: To list users currently logged on the system

```bash
➜  linux git:(master) ✗ whoami
user1
➜  linux git:(master) ✗ who
user1    pts/1        2025-12-21 13:49
```

`passwd -Sa`: To list all existing user accounts including their properties stored in the user database

```bash
➜  linux git:(master) ✗ sudo passwd -Sa
root L 11/22/2023 0 99999 7 -1
daemon L 11/22/2023 0 99999 7 -1
bin L 11/22/2023 0 99999 7 -1
sys L 11/22/2023 0 99999 7 -1
```

`useradd`: To add a new user, use the *useradd* command

```bash
➜  linux git:(master) ✗ sudo useradd -m -G root -s /bin/zsh user2
```

`passwd`: change user password

```bash
➜  linux git:(master) ✗ sudo passwd user2   
New password: 
Retype new password: 
passwd: password updated successfully
```

### chmod

`chmod g+w` 421

```
r=4
w=2
x=1
```

### chown

`chwon user file/directory`

### Switch User

`su username`
