// We have also present build-in deque
// Implementation of deque using dll 
// deque using dll -> 


#include<iostream>
#include<deque> // this is our build-in deque
using namespace std;
int main()
{

    deque<int>dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);

    cout<<dq.size()<<endl;
    dq.pop_back();
    dq.pop_back();
    cout<<dq.size()<<endl;
    
    dq.pop_front();
    dq.pop_front();
    cout<<dq.size()<<endl;
   

}