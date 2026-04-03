// SE_Lab05.cpp
#include "stdafx.h"
#include <iostream>
#include <locale>
#include "Dictionary.h"

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + \
    defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + \
    defined(TEST_UPENTRY_07) + defined(TEST_UPENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Нельзя определять более одного макроса из списка!"
#endif

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    try
    {
        #ifdef TEST_CREATE_01
        Dictionary::Instance d1 = Dictionary::Create("ОченьДлинноеИмяСловаря", 5);
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        #endif

        #ifdef TEST_CREATE_02
        Dictionary::Instance d1 = Dictionary::Create("Dict", DICTMAXSIZE + 1);
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        #endif

        #ifdef TEST_ADDENTRY_03
        Dictionary::Instance d1 = Dictionary::Create("Dict", 2);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::AddEntry(d1, {2, "Второй"});
        Dictionary::AddEntry(d1, {3, "Третий"});
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_ADDENTRY_04
        Dictionary::Instance d1 = Dictionary::Create("Dict", 5);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::AddEntry(d1, {1, "Дубликат"});
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_GETENTRY_05
        Dictionary::Instance d1 = Dictionary::Create("Dict", 5);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::Entry found = Dictionary::GetEntry(d1, 999);
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_GETENTRY_06
        Dictionary::Instance d1 = Dictionary::Create("Dict", 5);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::DelEntry(d1, 999);
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_UPDENTRY_07
        Dictionary::Instance d1 = Dictionary::Create("Dict", 5);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::UpdEntry(d1, 999, {999, "Новый"});
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_UPDENTRY_08
        Dictionary::Instance d1 = Dictionary::Create("Dict", 5);
        Dictionary::AddEntry(d1, {1, "Первый"});
        Dictionary::AddEntry(d1, {2, "Второй"});
        Dictionary::UpdEntry(d1, 1, {2, "Дубликат"});
        std::cout << "ОШИБКА: Исключение не выброшено!" << std::endl;
        Dictionary::Delete(d1);
        #endif

        #ifdef TEST_DICTIONARY
        Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 7);
        
        Dictionary::AddEntry(d1, {1, "Гладкий"});
        Dictionary::AddEntry(d1, {2, "Вежлик"});
        Dictionary::AddEntry(d1, {3, "Смелов"});
        Dictionary::AddEntry(d1, {4, "Урбанович"});
        Dictionary::AddEntry(d1, {5, "Кузнецов"});
        Dictionary::AddEntry(d1, {6, "Петров"});
        Dictionary::AddEntry(d1, {7, "Сидоров"});
        
        Dictionary::Print(d1);
        
        Dictionary::Instance d2 = Dictionary::Create("Студенты", 7);
        
        Dictionary::AddEntry(d2, {1, "Иванов"});
        Dictionary::AddEntry(d2, {2, "Петров"});
        Dictionary::AddEntry(d2, {3, "Сидоров"});
        Dictionary::AddEntry(d2, {4, "Козлов"});
        Dictionary::AddEntry(d2, {5, "Новиков"});
        Dictionary::AddEntry(d2, {6, "Морозов"});
        Dictionary::AddEntry(d2, {7, "Волков"});
        
        Dictionary::UpdEntry(d2, 3, {3, "Николаев"});
        
        Dictionary::Print(d2);
        
        Dictionary::Delete(d1);
        Dictionary::Delete(d2);
        #endif
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
    
    return 0;
}
