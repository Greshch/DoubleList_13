// DoubleList_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int data;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
} list;

void AddNode(int data);
void DeleteNode(Node* node);
void ShowList();
Node* FindNode(int data);
void AddNodeAfter(Node* node, int data);

void ClearList(); // free heap memory in list

int main()
{
    const int sizeList = 5;
    for (int i = 0; i < sizeList; i++) // Fill list
    {
        AddNode(i);
    }

    ShowList();

    ClearList(); // Free memory's list
}

void AddNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = list.tail;
    ++list.size;

    if (list.size == 1) // case when list is empty!
    {
        list.head = newNode;
        list.tail = list.head;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
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

void ClearList()
{
    if (list.size == 0) // It was needed to use this one only in case where lis.size not empty
    {
        return;
    }
    Node* prev = nullptr;
    for (Node* cur = list.head->next; cur != nullptr; cur = cur->next)
    {
        prev = cur->prev;
        delete prev;
        prev = nullptr;
    }
    delete list.tail; // delete tail
    list.tail = nullptr;
    list.size = 0;
}
