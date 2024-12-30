Ques.1. Implement a Min/Max Sliding Window Using Deque -: 

  
Problem:
Given an array of integers and a window size k, 
find the maximum (or minimum) in every sliding window of size k.

  
Example Input:
nums = [1,3,-1,-3,5,3,6,7], k = 3
Output (Maximums):
[3, 3, 5, 5, 6, 7]

  
Key Concept:
Use a deque to efficiently maintain indices of potential 
maximum (or minimum) values within the current sliding window.



1. Max Sliding Window Using Deque -: 

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Store indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices of elements not in the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices of smaller elements as they are useless
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the max of the current window to the result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
}





Ques.2. Implement a Deque from Scratch -: 

  
Problem:
Design and implement a custom doubly-ended queue (deque) with the following operations:


pushFront(): Insert an element at the front.
pushBack(): Insert an element at the back.
popFront(): Remove an element from the front.
popBack(): Remove an element from the back.
isEmpty(): Check if the deque is empty.
getFront(): Get the element at the front.
getBack(): Get the element at the back.




Code -: 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* back;

public:
    Deque() : front(nullptr), back(nullptr) {}

    void pushFront(int x) {
        Node* newNode = new Node(x);
        if (!front) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pushBack(int x) {
        Node* newNode = new Node(x);
        if (!back) {
            front = back = newNode;
        } else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
    }

    void popFront() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else back = nullptr;
        delete temp;
    }

    void popBack() {
        if (!back) return;
        Node* temp = back;
        back = back->prev;
        if (back) back->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    int getFront() {
        return front ? front->data : -1;
    }

    int getBack() {
        return back ? back->data : -1;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Deque dq;
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    cout << dq.getFront() << " "; // 5
    cout << dq.getBack() << " ";  // 20
    dq.popFront();
    cout << dq.getFront() << " "; // 10
    return 0;
}







Q3. Validate a Palindrome Using Deque -: 
  
  
Problem:
Check if a given string is a palindrome by using a deque. The string may contain 
alphanumeric characters and can ignore case sensitivity and non-alphanumeric characters.

  
Example Input:
"A man, a plan, a canal: Panama"
Output:
true

  
Key Concept:
Use the deque to compare characters from the front and back iteratively to validate the palindrome.



#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    deque<char> dq;

    for (char c : s) {
        if (isalnum(c)) {
            dq.push_back(tolower(c));
        }
    }

    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            return false;
        }
        dq.pop_front();
        dq.pop_back();
    }

    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}



These implementations cover:

Efficient sliding window maximum using deque.
Manual implementation of deque using a doubly linked list.
Palindrome validation using deque for comparison.


