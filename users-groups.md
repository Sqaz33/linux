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
