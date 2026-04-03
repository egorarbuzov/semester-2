#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address *next;
    Address *prev;
};

int menu(void)
{
    int c;
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Удаление повторяющихся элементов" << endl;
    cout << "6. Удаление K последних элементов" << endl;
    cout << "7. Выход" << endl;
    cout << endl;
    
    do
    {
        cout << "Ваш выбор: ";
        cin >> c;
        cin.ignore();
    } while (c < 0 || c > 7);
    
    return c;
}

void insert(Address *e, Address **phead, Address **plast)
{
    Address *p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
        return;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}

Address* setElement()
{
    Address* temp = new Address();
    if (!temp)
    {
        cerr << "Ошибка выделения памяти";
        return NULL;
    }
    cout << "Введите имя: ";
    cin.getline(temp->name, NAME_SIZE);
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void outputList(Address **phead, Address **plast)
{
    Address *t = *phead;
    if (!t)
    {
        cout << "Список пуст" << endl;
        return;
    }
    while (t)
    {
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}

void find(char name[NAME_SIZE], Address **phead)
{
    Address *t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name)) break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}

void delet(char name[NAME_SIZE], Address **phead, Address **plast)
{
    struct Address *t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name)) break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено" << endl;
    else
    {
        if (*phead == t)
        {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else
        {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "Элемент удален" << endl;
    }
}

void deleteDouble(Address **phead, Address **plast) {
    if (!*phead) {
        cout << "Список пуст" << endl;
        return;
    }
    
    Address *current = *phead;
    int removedCount = 0;
    
    while (current) {
        Address *runner = current->next;
        
        while (runner) {
            Address *nextRunner = runner->next;
            
            if (strcmp(current->name, runner->name) == 0 ||strcmp(current->city, runner->city) == 0) {
                if (runner->prev)
                    runner->prev->next = runner->next;
                if (runner->next)
                    runner->next->prev = runner->prev;
                
                if (runner == *plast)
                    *plast = runner->prev;
                
                delete runner;
                removedCount++;
            }
            
            runner = nextRunner;
        }
        
        current = current->next;
    }
    
    cout << "Удалено повторяющихся элементов: " << removedCount << endl;
}

void deleteKLast(int k, Address **phead, Address **plast) {
    if (!*phead) {
        cout << "Список пуст" << endl;
        return;
    }
    
    if (k <= 0) {
        cout << "Некорректное значение K. K должно быть больше 0" << endl;
        return;
    }
    
    int count = 0;
    Address *temp = *phead;
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    if (k >= count) {
        cout << "Удаляем все " << count << " элементов" << endl;
        temp = *phead;
        while (temp) {
            Address *next = temp->next;
            delete temp;
            temp = next;
        }
        *phead = NULL;
        *plast = NULL;
        return;
    }
    
    int elementsToKeep = count - k;
    temp = *phead;
    for (int i = 1; i < elementsToKeep; i++)
    {
        temp = temp->next;
    }
    
    Address *toDelete = temp->next;
    temp->next = NULL;
    *plast = temp;
    
    int removedCount = 0;
    while (toDelete)
    {
        Address *next = toDelete->next;
        delete toDelete;
        toDelete = next;
        removedCount++;
    }
    
    cout << "Удалено последних " << removedCount << " элементов" << endl;
}

int main(void)
{
    Address *head = NULL;
    Address *last = NULL;
    
    while(true)
    {
        switch (menu())
        {
            case 1:
                insert(setElement(), &head, &last);
                break;
            case 2:
            {
                char dname[NAME_SIZE];
                cout << "Введите имя: ";
                cin.getline(dname, NAME_SIZE);
                delet(dname, &head, &last);
                break;
            }
            case 3:
                outputList(&head, &last);
                break;
            case 4:
            {
                char fname[NAME_SIZE];
                cout << "Введите имя: ";
                cin.getline(fname, NAME_SIZE);
                find(fname, &head);
                break;
            }
            case 5:
                deleteDouble(&head, &last);
                break;
            case 6:
            {
                int k;
                cout << "Введите количество элементов для удаления (K): ";
                cin >> k;
                cin.ignore();
                deleteKLast(k, &head, &last);
                break;
            }
            case 7:
                exit(0);
            default:
                exit(1);
        }
    }
    return 0;
}
