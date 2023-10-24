#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node *p);
    void Insert(int pos, int x);
    int Delete(int pos);
    Node *getHead() { return head; }
    int Length(Node *p);
    ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int *A, int n)
{

    Node *t;
    Node *tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

void CircularLinkedList::recursiveDisplay(Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}
int CircularLinkedList::Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p!=head);
    return len;
}

void CircularLinkedList::Insert(int pos, int x)
{
    Node *t = new Node;
    Node *p = head;
    if (pos < 0 || pos > Length(head))
        return;
    if (pos==0){ // pos means index
        t->data = x;
        if (head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while (p->next!= head){
                p = p->next;
            }
            t->next = head;
            p->next = t;
            head = t;
        }
    }
    else{
        for (int i =1; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        t->data=x;
        t->next = p->next;
        p->next = t;
    }
}

int CircularLinkedList::Delete(int pos){   //pos means index
    Node *p,*q;
    int x;
    p=head;
    q=new Node;
    if (pos < 0 || pos > Length(head))
        return -1;
    if(pos==0){
        while(p->next!=head){
            p=p->next;
        }
        if(head==p){
            delete head;
            head=NULL;
        }else{
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;

    } 
    return x;  
}
CircularLinkedList::~CircularLinkedList()
{
    Node *p = head;
    Node *q = nullptr;
    while (p->next != head)
    {
        q = p;
        p = p->next;
        delete q;
    }
    if (p == head)
    {
        delete p;
        head = nullptr;
    }

}

int main()
{

    int A[] = {11, 13, 15, 17, 19};

    CircularLinkedList cl(A, 5);
    /* Node *h = cl.getHead();
    cl.recursiveDisplay(h); */

    

    cl.Delete(0);
    cl.Display();
    
    

    return 0;
}
