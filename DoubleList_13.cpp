// DoubleList_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int data;
};

class List {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    List() {}
    List(List const& list);

    void AddNode(int data);
    void DeleteNode(Node* node);
    void ShowList() const;
    Node* FindNode(int data) const;
    void AddNodeAfter(Node* node, int data);
    void ClearList(); // free heap memory in list

    ~List();
};



int main()
{
    const int sizeList = 5;
    List l1;
    for (int i = 0; i < sizeList; i++) // Fill list
    {
        //AddNode(i);
        l1.AddNode(i + 1);
    }
    List l2(l1);
    l1.ShowList();
    std::cout << "\n";
    l2.ShowList();
}

void List::AddNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = tail;
    ++size;

    if (size == 1) // case when list is empty!
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::DeleteNode(Node* node)
{
    if (node == nullptr) // It isn't needed to delete nulptr node!
    {
        return;
    }
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    //prevNode->next = nextNode;
    //nextNode->prev = prevNode;

    if (node == head && node == tail) // case : There is one Node in list
    {
        head = tail = nullptr;
    }
    else if (node == head) // case : delete head
    {
        head = nextNode;
    }
    else if (node == tail) // case : delete tail
    {
        tail = prevNode;
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
    --size;
}

void List::ShowList() const
{
    using namespace std;
    Node* cur = head;
    for (int i = 0; i < size; i++, cur = cur->next)
    {
        cout << i << "#\t" << cur->data << endl;
    }
}

Node* List::FindNode(int data) const
{
    Node* cur = head;
    for (int i = 0; i < size; i++, cur = cur->next)
    {
        if (cur->data == data)
        {
            return cur;
        }
    }
    return nullptr;
}

void List::AddNodeAfter(Node* node, int data)
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

    if (node == tail) // case when we add after tail
    {
        tail = newNode;
    }
    else
    {
        nextNode->prev = newNode;
    }
   
    ++size;
}

void List::ClearList()
{
    if (size == 0) // It was needed to use this one only in case where lis.size not empty
    {
        return;
    }
    Node* prev = nullptr;
    for (Node* cur = head->next; cur != nullptr; cur = cur->next)
    {
        prev = cur->prev;
        delete prev;
        prev = nullptr;
    }
    delete tail; // delete tail
    tail = nullptr;
    size = 0;
}

List::List(List const& list)
{
    Node* cur = list.head;
    for (size_t i = 0; i < list.size; i++, cur = cur->next)
    {
        int val = cur->data;
        AddNode(val);
    }
}

List::~List()
{
    ClearList();
}
