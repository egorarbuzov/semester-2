#!/bin/bash

# Цвета для вывода
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Очистка предыдущей сборки
echo -e "${BLUE}Очистка предыдущей сборки...${NC}"
rm -f *.o *.gch program program.exe  # Удаляем и .exe на всякий случай

# 1. Создание предкомпилированного заголовка stdafx.h
echo -e "${GREEN}1. Создание предкомпилированного заголовка...${NC}"
clang++ -x c++-header -o stdafx.h.gch stdafx.h
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибка при создании предкомпилированного заголовка${NC}"
    exit 1
fi

# 2. Компиляция stdafx.cpp
echo -e "${GREEN}2. Компиляция stdafx.cpp...${NC}"
clang++ -c stdafx.cpp -include stdafx.h -o stdafx.o
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибка при компиляции stdafx.cpp${NC}"
    exit 1
fi

# 3. Компиляция остальных cpp файлов
echo -e "${GREEN}3. Компиляция остальных файлов...${NC}"

for file in *.cpp; do
    if [ "$file" != "stdafx.cpp" ]; then
        echo -e "${BLUE}   Компиляция $file...${NC}"
        clang++ -c "$file" -include stdafx.h -o "${file%.cpp}.o"
        if [ $? -ne 0 ]; then
            echo -e "${RED}   Ошибка при компиляции $file${NC}"
            exit 1
        fi
    fi
done

# 4. Компоновка в нативный исполняемый файл macOS
echo -e "${GREEN}4. Компоновка исполняемого файла...${NC}"

# Компоновка в файл БЕЗ расширения .exe
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

# Запуск программы
echo -e "${GREEN}Запуск программы:${NC}"
./program