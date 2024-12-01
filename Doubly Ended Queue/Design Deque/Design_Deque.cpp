//  Deque -> design using -> Doubly Linked List.

#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Deque
{
public:
    Node *head;
    Node *tail;
    int size;
    Deque()
    {
        head = tail = NULL;
        size = 0;
    }

    // InsertAtTail function -: Queue me push hota h back/tail se

    void pushback(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // InsertAtHead function -: Queue me head hmara front hota h
    // Insert means Push karna

    void pushfront(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    // DeleteAtHead function -:Queue me delete/pop front se hota h

    void popfront()
    {
        if (size == 0)
        {
            cout << "List is empty ! ";
            return;
        }
        else
        {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            if (head == NULL)
                tail = NULL;
            size--;
        }
    }

    // DeleteAtTail function -: Queue tail back hota h
    // Delete means pop

    void popback()
    {
        if (size == 0)
        {
            cout << "List is empty ! ";
            return;
        }
        else if (size == 1)
        {
            popfront();
            return;
        }
        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty " << endl;
            return -1;
        }
        return head->val;
    }

    int back()
    {
        if (size == 0)
        {
            cout << "Queue is empty " << endl;
            return -1;
        }
        return tail->val;
    }

    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    // Display function -:

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque dq;

    dq.pushback(10);
    dq.pushback(20);
    dq.pushback(30);
    dq.pushback(40);
    dq.display();

    dq.popback();
    dq.display();

    dq.popfront();
    dq.display();

    dq.pushfront(50);
    dq.display();
    
    cout << dq.front();
    cout << endl;
    cout << dq.back();
}


// 10 20 30 40
// 10 20 30
// 20 30
// 50 20 30
// 50
// 30