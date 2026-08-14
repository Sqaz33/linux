# Перенаправление

$ ./prog < test/002.in 1> 1.out 2> 1.err

### Aborted

$./prog \$> 1.all

Aborted - пишет сама оболчка.

$./prog \$> 1.all || false

Aborted - не пишется

# Вложенные оболочки

$(echo "Hello World!")

# Цикл

For, while

$ for i in tests/*.in; do echo \$1; cat \$i; ./prog < \$i done

### lvalue, rvalue

\$i - rvalue

i - lvalue

# PATH

Путь, по которуму ищуться файлы
