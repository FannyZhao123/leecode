/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.
*/


//2 stacks
//Runtime: 52 ms, faster than 20.25% of C++ online submissions for Min Stack.
//Memory Usage: 16.1 MB, less than 100.00% of C++ online submissions for Min Stack.
class MinStack {
private:
    stack <int> s;
    stack <int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        //nothing
    }
    void push(int x) {
        if (min.empty() ||x <= min.top()){
            min.push(x);
        }
        s.push(x);
    }
    void pop() {
        if(s.top() == min.top()){
            min.pop();
        }
        s.pop();
    }
    int top() {
        return s.top(); 
    }
    int getMin() {
        return min.top();
    }
};



