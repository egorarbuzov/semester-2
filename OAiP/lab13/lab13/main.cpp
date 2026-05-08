#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void*  a1, void* a2)
{	
#define A1 ((AAA*)a1)
	#define A2 ((AAA*)a2)
		heap::CMP    
		rc = heap::EQUAL;
		if (A1->x  >  A2->x)   
			rc = heap::GREAT;
		else 
                if (A2->x  > A1->x) 
			      rc = heap::LESS;
		return rc;
	#undef A2
	#undef A1 
}

void uniteHeaps(heap::Heap& h1, heap::Heap& h2)
{
    heap::Heap unionHp = heap::create(30, cmpAAA);
    heap::unionHeaps(h1, h2, unionHp);
    cout << "Объединенная куча:"; 
    unionHp.scan(0);
    h2.scan(0);
}

int main()
{	setlocale(LC_ALL, "rus");
	int k, choice, ind;
	heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{	cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент в 1-ую кучу" << endl;
        cout << "3 - добавить элеиент во 2-ую кучу" << endl;
		cout << "4 - удалить максимальный элемент" << endl;
        cout << "5 - удалить минимальный элемент" << endl;
        cout << "6 - удалить элемент по индексу" << endl;
        cout << "7 - объединить две кучи и вывести новую" << endl;
        cout << "8 - (доп) посчитать высоту кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор: " << endl;  cin >> choice;
		switch (choice)
		{	case 0:  exit(0);
		case 1:  h1.scan(0);   
		    break;
		case 2:  {	AAA *a = new AAA;
			cout << "введите ключ: " << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		    }
		    break;
        case 3 : {
            AAA *a = new AAA;
            cout << "введите ключ: " << endl; cin >> k;
            a->x = k;
            h2.insert(a);
        }
        break;
		case 4:   h1.extractMax(); 
			     break;
        case 5: h1.extractMin();
            break;
        case 6:
            cout << "введите индекс i: "; cin >> ind;
            h1.extractI(ind);
            break;
        case 7:
            uniteHeaps(h1, h2);
            break;
        case 8:
            cout << "Высота: " << h1.getHeight() << endl;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}

	} return 0;
}
