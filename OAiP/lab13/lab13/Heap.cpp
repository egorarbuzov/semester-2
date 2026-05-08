#include "Heap.h"
#include <iostream>
#include <iomanip>

void AAA::print()
{	std::cout << x; }
namespace heap
{	Heap create(int maxsize, CMP(*f)(void*, void*))
	{	return *(new Heap(maxsize, f));	}
	int Heap::left(int ix)
	{	return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1); }
	int Heap::right(int ix)
	{	return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); }
	int Heap::parent(int ix)
	{ 	return (ix + 1) / 2 - 1;  }
	void Heap::swap(int i, int j)
	{	void* buf = storage[i];   
		storage[i] = storage[j];  
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{	int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{	if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{ 	swap(ix, irl);	
				heapify(irl); 
			}
		}
	}

    void Heap::heapifyUp(int ix) {
        while(ix > 0 && isLess(storage[parent(ix)], storage[ix])) {
                swap(parent(ix), ix);
                ix = parent(ix);
            }
    }

	void Heap::insert(void* x)
	{	int i;
		if (!isFull())
		{	storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{	swap(parent(i), i);	
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{	void* rc=nullptr;
		if (!isEmpty())
		{	rc = storage[0];	
			storage[0] = storage[size - 1];
			size--;	
			heapify(0);
		} return rc;
	}

// удаление минимума
void* Heap::extractMin() {
    void* rc = nullptr;
    if (!isEmpty()) {
        int minIndex = size / 2;
        for (int i = size / 2; i < size; i++) {
            if (isLess(storage[i], storage[minIndex])) {
                minIndex = i;
            }
        }
        rc = storage[minIndex];
        storage[minIndex] = storage[size - 1];
        size--;
        if (minIndex < size) {
            if (minIndex > 0 && isLess(storage[parent(minIndex)], storage[minIndex])) {
                heapifyUp(minIndex);
            }
            heapify(minIndex);
        }
    }
    return rc;
}

// удаление по i
void* Heap::extractI(int index) {
    void* rc = nullptr;
    if (!isEmpty()) {
        storage[index] = storage[index - 1];
        size--;
        if (index < size) {
            if (index > 0 && isLess(storage[parent(index)], storage[index])) {
                heapifyUp(index);
            } else {
                heapify(index);
            }
        }
    }
    return rc;
}
// обхединение куч
void unionHeaps(Heap& h1, Heap& h2, Heap& result)
{
    while(!result.isEmpty()) {
        delete (AAA*)result.extractMax();
    }

    for (int i = 0; i < h1.size; i++)
    {
        AAA* newElem = new AAA;
        newElem->x = ((AAA*)h1.storage[i])->x;
        result.insert(newElem);
    }

    for (int i = 0; i < h2.size; i++)
    {
        AAA* newElem = new AAA;
        newElem->x = ((AAA*)h2.storage[i])->x;
        result.insert(newElem);
    }
}

	void Heap::scan(int i) const
	{	int probel = 20;	
		std::cout << '\n';
		if (size == 0)  
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{	std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{    std::cout << '\n'; 
				if (y == 0) 
					y = 2;  
				else 
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}

// доп функция
    int Heap::getHeight() {
        int h = 0;
        int n = size;
        while (n > 0) {
            n /= 2;
            h++;
        }
        return h;
    }
}

