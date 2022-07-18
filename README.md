Реализовать двухсвязный список 
struct Node {
Node* next;
Node* prev;
int data;
}

struct List {
Node* head;
Node* tail;
int size;
}

И функции:
void AddNode(int data)
void DeleteNode(Node* node)
void ShowList()
Node* FindNode(int data)
void AddNodeAfter(Node* node, int data)