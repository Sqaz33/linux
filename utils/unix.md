> https://web.archive.org/web/20190816135930/http://ph7spot.com/musings/in-unix-everything-is-a-file

# In UNIX Everything is a File

This fundamental concept is actually two-fold:

* In UNIX everything is a stream of bytes
* In UNIX the filesystem is used as a universal name space

### In UNIX Everything is a Stream of Bytes

So what really constitutes a file in UNIX? A file is not much more than a plain collection of bytes that you can read and/or write. Once you have a reference to a file, called a file descriptor, I/O access in UNIX is done using the same set of operations, the same API – whatever the type of the device and the underlying hardware.

as a stream of bytes that you can:

* `read`
* `write`
* `lseek`
* `close`

### The Filesystem is a Universal Name Space

In UNIX, files are not only a stream of bytes with a consistent API, they can also be referenced in a uniform manner: the filesystem is used as a universal namespace.

For instance you can reference a local directory with `/usr/local`, a file with `/home/joe/memo.pdf`, a CD-ROM with `/mnt/cdrom`, a directory on a network drive with `/usr`, a hard disk partition with `/dev/sda1`, a UNIX domain socket with `/tmp/mysql.sock`, a terminal with `/dev/tty0` or even a mouse with `/dev/mouse`.

The namespace is hierarchical and all resources can be referenced from the root directory (`/`). You can access multiple filesystems within the same namespace: you just “attach” a device or a filesystem (let’s say an external hard-drive) at a specific location in the namespace (say `/backups`). In UNIX jargon, this action is called *mounting* a filesystem, and the namespace location where you attach the filesystem is called a *mount point*. You can reference all the resources of a mounted filesystem as a part of the global namespace by prefixing them with the mount point (say the file `/backups/myproject-Oct07.zip`)

### Pseudo Filesystems

This approach lead to the creation of numerous *pseudo* filesystems that behave like normal file systems but can be used to access resources that are not directly related to a traditional filesystem.

For instance you can use a pseudo filesystem to query and control processes, access kernel internals or establish TCP connections.
