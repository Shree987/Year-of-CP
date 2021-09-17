/*
Author : Shreeraksha R Aithal
Problem name : Design Circular Deque
Problem link : https://leetcode.com/problems/design-circular-deque/
Difficulty : Medium
Tags : Array, Design, Linked List, Queue
*/

class MyCircularDeque {
public:
    vector<int> q;
    int front, rear, len;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        len = k;
        rear = front = -1;
        q.resize(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())   return false;
        if(isEmpty()){
            rear = front = 0;
            q[0] = value;
            return true;
        }
        front = (front+len-1)%len;
        q[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())   return false;
        if(isEmpty()){
            rear = front = 0;
            q[0] = value;
            return true;
        }
        rear = (rear+1)%len;
        q[rear] = value;
        return true;        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())   return false;
        if(rear == front){
            front = rear = -1;
            return true;
        }
        front = (front + 1)%len;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())   return false;
        if(rear == front){
            front = rear = -1;
            return true;
        }
        rear = (rear+len-1)%len;
        return true;        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())    return -1;
        return q[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())    return -1;
        return q[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (front == -1);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear+1)%len == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */