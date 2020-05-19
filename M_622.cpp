/*
622. Design Circular Queue
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
 
Note:
All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.
*/

// written by myself, long and shitty..... easier if set begin,end start from -1
//Runtime: 88 ms, faster than 5.80% of C++ online submissions for Design Circular Queue.
//Memory Usage: 16.7 MB, less than 18.18% of C++ online submissions for Design Circular Queue.
class MyCircularQueue {
private:
    vector <int> q;
    int begin, end, used;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        begin = 0;
        end = 0;
        used = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        else if (isEmpty()){
            begin++;
            end++;
            used++;
            q[begin-1] = value; 
            return true;
        }
        else{
            if (end == q.size()){
                end = 1;
                q[end-1] = value;
                used++;
                return true;
            } 
            else{
                end++;
                q[end-1] = value;
                used++;
                return true;
            }
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        else if (used == 1) {
            begin = 0;
            end = 0;
            used = 0;
            return true;
        }
        else{
            if(begin == q.size()){
                begin = 1;
                used--;
                return true;
            }
            else{
                begin+=1;
                used--;
                return true;
            }
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        //if(begin == 0) return q.back();
        return q[begin-1];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        //if (end == 0) return q.back();
        return q[end-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return used == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (used == q.size()) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


//nicer, the answer provided 
class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

//faster than mine
class MyCircularQueue {
private:
    vector<int> arr_;
    int l_, r_;     // scope for [l, r)
    bool empty_;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        assert(k > 0);
        arr_ = vector<int>(k);
        l_ = r_ = 0;
        empty_ = true;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty_;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (empty_)
            return -1;
        else
            return arr_[l_];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (empty_)
            return -1;
        else {
            if (r_ == 0)
                return arr_.back();
            else
                return arr_[r_-1];
        }
    }
	
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return !empty_ && (l_ == r_);
    }

/** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            empty_ = false;
            arr_[r_] = value;
            ++r_;
            if (r_ == arr_.size())
                r_ = 0;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (empty_) {
            return false;
        } else {
            ++l_;
            if (l_ == arr_.size())
                l_ = 0;
            if (l_ == r_)
                empty_ = true;
            return true;
        }
    }
};