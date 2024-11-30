In this file we will discuss about Deque (Doubly Ended Queue) Data Structure. 
Perform Basic STL functions On the deque. 
Definition-: A deque is a sequence container in C++ that allows insertion and deletion of elements from both the front and the back. It is part of the Standard Template Library (STL).

Key Features-: Dynamic Resizing:
Automatically resizes as elements are added or removed.

Efficient Operations-: O(1) for push and pop operations at both ends.
Random access is O(1), similar to std::vector.

Underlying Implementation-: Implemented as a dynamic array of pointers to arrays.

Advantages -:
Supports both stack and queue operations.
Better than std::vector for frequent insertions/removals at both ends.

Use Cases -:
Sliding Window Problems: Efficient for finding max/min in a sliding window.
Palindrome Checking: Supports two-pointer technique for checking palindromes.
Implementing Stacks/Queues: Can be used as a stack or queue
