#!/bin/bash

while getopts b:f: flag
do
    case ${flag} in
    b) border=${OPTARG};;
    f) folder=${OPTARG};;
    esac
done

echo "folder is $folder"
echo "bolder is $border"