// Deque means doubly ended queue that is we perform all the operation like push,pop in the both the size
// of the queue 

// Implementation of the deque using doubly Linked list 
// by using dll we implement our deque.

#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};


class Deque
{
    public:
    int size;
    Node* head;
    Node* tail;

    Deque()
    {
        size=0;
        head=tail=NULL;
    }


void pushatfront(int val)
{
    Node* temp=new Node(val);
    if(size==0)
    {
        head=tail=temp;
        tail->next=head;
        size++;
    }
    else
    {
        temp->next=head;
        temp->prev=tail;
        head->prev=temp;
        tail->next=temp;
        head=temp;
        size++;
    }
}


void pushatback(int val)
{
    Node* temp=new Node(val);
    {
        if(size==0)
        {
            head=tail=temp;
            tail->next=head;
            size++;
        }
        else
        {
            tail->next=temp;
            temp->next=head;
            temp->prev=tail;
            head->prev=temp;
            tail=temp;
            size++;
        }
    }
}


void popatfront()
{
    if(size==0)
    {
        cout<<"Deque is empty ! Underflow !"<<endl;
        return ;
    }
    else
    {
        head=head->next;
        tail->next=head;
        head->prev=tail;
        size--;
    }
}


void popatback()
{
    if(size==0)
    {
        cout<<"Doubly Linked list is empty ! Underflow "<<endl;
        return ;
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        size--;
    }
}


int getatfront()
{
    if(size==0)
    {
        cout<<"Deque is empty ! Underflow "<<endl;
        return -1;
    }
    else
    {
        return head->val;
    }
}

int getatback()
{
    if(size==0)
    {
        cout<<"Doubly Linked List is empty ! Underflow "<<endl;
        return -1;
    }
    else
    {
        return tail->val;
    }
}

int empty()
{
    if(size==0)
    {
        cout<<"Yes, Deque is empty "<<endl;
        return true;
    }
    else
    {
        cout<<"No, Deque is not empty "<<endl;
        return false;
    }
}

// displayfront function:
// This function displays the elements of the doubly linked list
// starting from the head and moving forward through the next pointers.
// This function is suitable for displaying
// the deque elements in the order they were added, starting from the front.

void displayfront()
{
    if(size==0)
    {
        cout<<"List is empty "<<endl;
        return;
    }
    Node* temp=head;
    while(true)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
        if(temp==head) break;
    }
    cout<<endl;
}

// displayback function:
// This function displays the elements of the doubly linked list
// starting from the tail and moving backward through the prev pointers.
// This function is suitable for displaying the 
// deque elements in reverse order, starting from the back.

void displayback()
{
    if(size==0)
    {
        cout<<"List is empty "<<endl;
        return;
    }
    Node* temp=tail;
    while(true)
    {
        cout<<temp->val<<" ";
        temp=temp->prev;
        if(temp==tail) break;
    }
    cout<<endl;
}

// Depending on your use case, you can choose the appropriate function.
// If you want to see the elements in the order they were added, use displayfront. 
// If you want to see the elements in reverse order, use displayback. 
// Both functions correctly handle the case where the list is empty.


};

int main()
{
    Deque dq;

// front se ele. ko push kiya to back se pop(print) karenge -> displayback();
    // dq.pushatfront(10);
    // dq.pushatfront(20);
    // dq.pushatfront(30);
    // dq.pushatfront(40);
    // dq.pushatfront(50);

    // this display function is also correct. 
    // dq.displayback();
    // cout<<dq.size<<endl;


// back se ele. ko push kiya to front se ele. ko pop(print) karenge
    dq.pushatback(100);
    dq.pushatback(200);
    dq.pushatback(300);
    dq.pushatback(400);
    dq.pushatback(500);

    // this display function is also correct 
    dq.displayfront();         
    cout<<dq.size<<endl;




    cout<<dq.getatfront()<<endl;
    cout<<dq.getatback()<<endl;
    cout<<dq.size<<endl;

    dq.popatfront();
    dq.displayfront();

    dq.popatfront();
    dq.displayfront();
    dq.popatfront();
    dq.displayfront();



    cout<<dq.getatfront()<<endl;
    cout<<dq.getatback()<<endl;

    dq.pushatback(600);
    dq.pushatback(700);
    dq.pushatback(800);
    dq.displayfront();


    cout<<dq.size<<endl;
    cout<<dq.getatback()<<endl;
    cout<<dq.getatfront()<<endl;



    dq.popatback();
    dq.displayfront();


    dq.popatback();
    dq.popatback();
    dq.displayfront();




    cout<<dq.getatfront()<<endl;
    cout<<dq.getatback()<<endl;
    cout<<dq.size<<endl;;

    cout<<dq.getatfront()<<endl;
    cout<<dq.getatback()<<endl;

    dq.pushatback(900);
    dq.pushatback(1000);
    dq.displayfront();

}


// // output -:
// // 100 200 300 400 500 
// // 5
// // 100
// // 500
// // 5
// // 200 300 400 500 
// // 300 400 500
// // 400 500
// // 400
// // 500
// // 400 500 600 700 800
// // 5
// // 800
// // 400
// // 400 500 600 700
// // 400 500
// // 400
// // 500
// // 2
// // 400
// // 500
// // 400 500 900 1000


// we implement deque or doubly ended queue using doubly linked list 
// in deque we can perform push or pop operation in both the size front as well as back 
// if we push ele. in the back side of the deque then we pop ele. from front side of the deque
// and if we push ele. in the front side of the dqeue then we pop ele. front back side of the deque
// so we make two different display function function 1- displayfront and 2- displayback
// displayfront display ele. from the front of the deque and another displayback display ele. from the back of the deque 
// Both the function is true. And their different purpose.

// Done 15-02-2024 06:25 PM