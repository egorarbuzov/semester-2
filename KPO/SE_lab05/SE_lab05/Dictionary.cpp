#include <iostream>
#include "Dictionary.h"

using namespace std;

namespace Dictionary {
    Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
        if (strlen(name) >= DICTNAMEMAXSIZE) {
            throw THROW01;
        }
        if (size > DICTMAXSIZE) {
            throw THROW02;
        }
        Instance inst;
        strcpy(inst.name, name);
        inst.maxsize = size;
        inst.size = 0;
        inst.dictionary = new Entry[size];
        return inst;
    }
    void AddEntry(Instance &inst, Entry ed) {
        if (inst.size >= inst.maxsize) {
            throw THROW03;
        }
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == ed.id)
                throw THROW04;
        }
        inst.dictionary[inst.size++] = ed;
    }
    void DelEntry(Instance& inst, int id) {
        int index = -1;
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw THROW06;
        }
        for (int i = index; i < inst.size - 1; ++i) {
            inst.dictionary[i] = inst.dictionary[i + 1];
        }
        inst.size--;
    }
    Entry GetEntry(Instance inst, int id) {
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
                return inst.dictionary[i];
        }
        throw THROW05;
    }
    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        int index = -1;
        for (int i = 0; i < inst.size; ++i)
        {
            if (inst.dictionary[i].id == id)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
            throw THROW07;

        for (int i = 0; i < inst.size; ++i)
        {
            if (i != index && inst.dictionary[i].id == new_ed.id)
                throw THROW08;
        }

        inst.dictionary[index] = new_ed;
    }

    void Delete(Instance& d) {
        delete[] d.dictionary;
        d.dictionary = nullptr;
        d.size = 0;
    }

    void Print(Instance d) {
        std::cout << "Dictionary: " << d.name << "\n";
        std::cout << "Max size: " << d.maxsize << "\n";
        std::cout << "Current size: " << d.size << "\n";
        for (int i = 0; i < d.size; ++i)
        {
            std::cout << "ID: " << d.dictionary[i].id
                      << ", Name: " << d.dictionary[i].name << "\n";
        }
        std::cout << "------------------------\n";
    }

}

