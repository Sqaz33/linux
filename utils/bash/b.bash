#!/bin/bash

#var
NAME="Stepan"
echo $NAME

# subs
DATE=$(date)
echo "Сегодня: $DATE"

# args
echo "1: $1, всего штук: $#"

#br
if [ "$1" -gt 10 ] && [ "$1" -ne 0 ]; then 
    echo "> 10"
else 
    echo "<= 10"
fi

if [ -f "$0" ]; then 
    echo "file: $0"
fi

# return code
ls nofile.txt
echo $?

# func
sub() {
    echo $(( $1 - $2 ))
}

sub 1 2
RES=$(sub 1 2)
echo "$RES"

# loop
for i in 1 3 5; do
    echo "i = $i"
done

for i in {1..3}; do
    echo "i = $i"
done

for ((i=1; i<=3; i++)); do
    echo "i = $i"
done

# while 
I=1
while [ $I -lt 10 ]; do
    echo "$I"
    I=$(($I + 1))
done

#case 
ACTION="$2"
case "$ACTION" in
    start)
        echo "start"
        ;;
    stop)
        echo "stop"
        ;;
    *)
        echo "??"
        ;;
esac

# ~~~
RES=$(./a.out)
echo "$RES"

while read -r line; do
    echo "Line: $line"
done < <(./s)
