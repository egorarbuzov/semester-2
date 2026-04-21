#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct stackNode {
    int data;
    stackNode* next;
};

struct myStack {
    stackNode* topNode;
    int size;
};

void initStack(myStack* stack);
void pushStack(myStack* stack, int value);
int popStack(myStack* stack);
void printStack(myStack* stack);
void clear(myStack* stack);
void parsePosNeg(myStack* stack, myStack* positivestack, myStack* negativeStack);
void removeThrElements(myStack* stack);
void loadToFile(myStack* stack, const std::string& fname);
void loadFromFile(myStack* stack, const std::string& fname);
