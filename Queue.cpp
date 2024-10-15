#include <iostream>
using namespace std;

class Node
{

private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }

    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
};

class Queue
{

private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }

    void enqueue(int data)
    {
        Node *n = new Node(data);
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->setNext(n);
            rear = n;
        }
    }

    void dequeue()
    {
        Node *temp = front;
        if (front == NULL)
        {
            cout << "no list ";
            return;
        }
        else
        {
            front = front->getNext();
            delete temp;
        }
    }

    void print()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    return 0;
}