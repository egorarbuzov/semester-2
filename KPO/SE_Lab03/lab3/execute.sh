#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

print_message() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

if ! command -v g++ &> /dev/null; then
    print_error "g++ не найден. Установите компилятор GCC."
    exit 1
fi

print_message "Начинаем компиляцию проекта..."

mkdir -p obj

print_message "Создание предкомпилированного заголовка..."

if g++ -std=c++11 -Wall -x c++-header stdafx.h -o stdafx.h.gch; then
    print_message "Предкомпилированный заголовок успешно создан"
else
    print_error "Ошибка при создании предкомпилированного заголовка"
    exit 1
fi

print_message "Компиляция исходных файлов с использованием PCH..."

source_files=(
    "dayNumber.cpp"
    "isYearVis.cpp"
    "monthsFunc.cpp"
    "main.cpp"
    "stdafx.cpp"
)

object_files=()

for file in "${source_files[@]}"; do
    print_message "Компиляция $file..."
    
    obj_file="obj/${file%.cpp}.o"
    
    if g++ -std=c++11 -Wall -I. -include stdafx.h -c "$file" -o "$obj_file"; then
        print_message "✓ $file скомпилирован успешно"
        object_files+=("$obj_file")
    else
        print_error "✗ Ошибка при компиляции $file"
        exit 1
    fi
done

print_message "Линковка объектных файлов..."

if g++ -std=c++11 "${object_files[@]}" -o program; then
    print_message "✓ Программа успешно скомпилирована! Исполняемый файл: ./program"
else
    print_error "✗ Ошибка при линковке"
    exit 1
fi

chmod +x program

print_message "Компиляция завершена!"
print_message "Для запуска программы выполните: ./program"

read -p "Удалить объектные файлы и PCH? (y/n): " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    rm -rf obj stdafx.h.gch
    print_message "Временные файлы удалены"
fi

exit 0
