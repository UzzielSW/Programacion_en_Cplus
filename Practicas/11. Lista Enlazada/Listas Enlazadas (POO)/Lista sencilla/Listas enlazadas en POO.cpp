#include <iostream>
using namespace std;

class Node 
{
    public:
        int data; //data
        Node *next; //pointer
    Node(int x) 
    {
        data = x;
        next = NULL;
    }
};

class LinkedList 
{
    public:
    Node *head;

    //function to add Node at front
    void addAtFront(Node *n) 
    {
        n->next = head;
        head = n;
    }

    //funcion para verificar si la lista esta vacia
    bool isEmpty() 
    {
        if(head == NULL) { return 1; }
        else { return 0; }
    }

    //funcion par agregar un nodo al final
    void addAtEnd(Node *n) 
    {
        if(head == NULL) 
        {
            head = n;
            n->next = NULL;
        }
        else 
        {
            Node *n2 = getLastNode();
            n2->next = n;
        }
    }

    //funcion que retorna el ultimo elemento de la lista
    Node* getLastNode() 
    {
        Node* ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        
        return ptr;
    }

    //funcion para buscar un valor el la lista
    Node* search(int k) 
    {
        Node *ptr = head;
        while(ptr != NULL && ptr->data != k) 
            ptr = ptr->next;
        
        return ptr;
    }

    //funcion para eliminar un nodo de la lista
    Node* deleteNode(int x) 
    {
        Node *n = search(x);
        Node *ptr = head;

        if(ptr == n) 
        {
            head = n->next;
            return n;
        }
        else 
        {
            while(ptr->next != n) 
                ptr = ptr->next;
            
            ptr->next = n->next;

            return n;
        }
    }

    //funcion para imprimir la lista
    void printList() 
    {
        Node *ptr = head;

        while(ptr != NULL) 
        {
            cout << ptr->data<<" -> ";
            ptr = ptr->next;
        }
    }

    LinkedList() //contructor
    {
        head = NULL;
    }
};


int main() 
{
    LinkedList L;
    
    Node *n1 = new Node(5);
    Node *n2 = new Node(8);
    Node *n3 = new Node(12);
    
    L.addAtFront(n1);
    L.addAtFront(n2);
    L.addAtEnd(n3);
    
    L.printList();
    
    delete [] n1;
    delete [] n2;
    delete [] n3;
    
    return 0;
}