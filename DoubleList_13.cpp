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

    ShowList(); // show list

    // Test FindNode and DeleteNode
    std::cout << "Type data(int) for found and delete : ";
    int findData = 0;
    std::cin >> findData;
    Node* isFound = FindNode(findData);
    if (isFound)
    {
        std::cout << findData << " was founded\n";
        DeleteNode(isFound);
    }

    // show list
    std::cout << "\n\n";
    ShowList();

    // Test FindNode and AddNodeAfter
    std::cout << "Type data(int) for found : ";
    findData = 0;
    std::cin >> findData;
    isFound = FindNode(findData);
    if (isFound)
    {
        std::cout << findData << " was founded\n";
        int newData = 0;
        std::cout << "Type new int for add : ";
        std::cin >> newData;
        AddNodeAfter(isFound, newData);
    }


    // show list
    std::cout << "\n\n";
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

void DeleteNode(Node* node)
{
    if (node == nullptr) // It isn't needed to delete nulptr node!
    {
        return;
    }
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    //prevNode->next = nextNode;
    //nextNode->prev = prevNode;

    if (node == list.head && node == list.tail) // case : There is one Node in list
    {
        list.head = list.tail = nullptr;
    }
    else if (node == list.head) // case : delete head
    {
        list.head = nextNode;
    }
    else if (node == list.tail) // case : delete tail
    {
        list.tail = prevNode;
    }

    if (prevNode != nullptr)
    {
        prevNode->next = nextNode;
    }
    
    if (nextNode != nullptr)
    {
        nextNode->prev = prevNode;
    }

    delete node;
    --list.size;
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

Node* FindNode(int data)
{
    Node* cur = list.head;
    for (int i = 0; i < list.size; i++, cur = cur->next)
    {
        if (cur->data == data)
        {
            return cur;
        }
    }
    return nullptr;
}

void AddNodeAfter(Node* node, int data)
{
    if (node == nullptr) // It isn't needed to add after nulptr node!
    {
        return;
    }

    Node* nextNode = node->next;

    Node* newNode = new Node;
    newNode->data = data;

    node->next = newNode;
    newNode->prev = node;

    newNode->next = nextNode;
    //nextNode->prev = newNode;

    if (node == list.tail) // case when we add after tail
    {
        list.tail = newNode;
    }
    else
    {
        nextNode->prev = newNode;
    }
   
    ++list.size;
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
