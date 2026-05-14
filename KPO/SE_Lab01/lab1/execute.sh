#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}Очистка предыдущей сборки...${NC}"
rm -f *.o *.gch program program.exe

echo -e "${GREEN}1. Создание предкомпилированного заголовка...${NC}"
clang++ -x c++-header -o stdafx.h.gch stdafx.h
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибка при создании предкомпилированного заголовка${NC}"
    exit 1
fi

echo -e "${GREEN}2. Компиляция stdafx.cpp...${NC}"
clang++ -c stdafx.cpp -include stdafx.h -o stdafx.o
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибка при компиляции stdafx.cpp${NC}"
    exit 1
fi

echo -e "${GREEN}3. Компиляция основных файлов...${NC}"

# Массив с основными файлами проекта
files=("dayNumber.cpp" "isYearVis.cpp" "main.cpp")

for file in "${files[@]}"; do
    if [ -f "$file" ]; then
        echo -e "${BLUE}   Компиляция $file...${NC}"
        clang++ -c "$file" -include stdafx.h -o "${file%.cpp}.o"
        if [ $? -ne 0 ]; then
            echo -e "${RED}   Ошибка при компиляции $file${NC}"
            exit 1
        fi
    else
        echo -e "${RED}   Файл $file не найден${NC}"
        exit 1
    fi
done

echo -e "${GREEN}4. Компоновка исполняемого файла...${NC}"

clang++ *.o -o program
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибка при компоновке${NC}"
    exit 1
fi

echo -e "${GREEN}✅ Сборка завершена успешно!${NC}"
echo -e "${BLUE}Исполняемый файл: ./program${NC}"
echo -e "${BLUE}Тип файла:${NC}"
file program | sed 's/.*: //'
echo -e "${BLUE}Размер:${NC}"
ls -lh program | awk '{print $5}'

echo -e "${GREEN}Запуск программы:${NC}"
./program