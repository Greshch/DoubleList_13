// DoubleList_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    Node* next;
    Node* prev;
    int data;
};

struct List {
    Node* head;
    Node* tail;
    int size;
} list;

void AddNode(int data);
void DeleteNode(Node* node);
void ShowList();
Node* FindNode(int data);
void AddNodeAfter(Node* node, int data);

int main()
{
    std::cout << "Hello World!\n";
}

void ShowList()
{
    using namespace std;
    Node* cur = list.head;
    for (int i = 0; i < list.size; i++, cur = cur->next)
    {
        cout << i << "#\t" << cur->data << endl;
    }
}
