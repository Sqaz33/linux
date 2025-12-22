# Find

### type

`find path -type [f/d/l(ref)/b(block)/c(device)/p(fifo)/s(socket)]`

### logic

```bash
find . '(' -type f -or -type d ')'
find . ! -name "*.txt" # not
find . -maxdepth 1 '(' -user user1 -or -type f -and -user user2 ')'
```

### size

```bash
find . -size 10M       # ровно 10 MB
find . -size +100M    # больше 100 MB
find . -size -1k      # меньше 1 KB
```

### perm

```bash
find . -perm 644 # точное
find . -perm -644 # не меньше
```

### depth

`find . -maxdepth 1`

### users and groups

```bash
find /home -user alice
find /var -group www-data
find / -nouser
find / -nogroup

```

### wildcard

```bash
find . -name "????.*"
find . -name "test[1-3].txt"
```

# Grep
