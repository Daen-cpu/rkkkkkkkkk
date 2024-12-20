#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Пожалуйста, укажите директорию и расширение файлов."
  exit 1
fi

directory=$1
extension=$2

if [ ! -d "$directory" ]; then
  echo "Директория не найдена."
  exit 1
fi

files=$(find "$directory" -type f -name "*.$extension")

if [ -n "$files" ]; then
  echo "$files"
else
  echo "Файлы с расширением .$extension не найдены."
fi
