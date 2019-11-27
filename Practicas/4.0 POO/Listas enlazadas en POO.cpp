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
    //function to check whether the list is empty
    bool isEmpty() 
    {
        if(head == NULL) { return 1; }
        else { return 0; }
    }
    //function to add Node at the end
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

    //function to get the last Node
    Node* getLastNode() 
    {
        Node* ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        
        return ptr;
    }

    //function to search a value
    Node* search(int k) 
    {
        Node *ptr = head;
        while(ptr != NULL && ptr->data != k) 
            ptr = ptr->next;
        
        return ptr;
    }

    //function to delete any Node
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

    //function to print the list Nodes
    void printList() 
    {
        Node *ptr = head;

        while(ptr != NULL) 
        {
            cout << ptr->data<<" -> ";
            ptr = ptr->next;
        }
    }

    LinkedList() 
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