/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
*/


SOLUTION :
-----------
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long int>s;
    int mn=INT_MAX;
    MinStack() 
    {
        
        
    }
    
    void push(int x) 
    {
        if(s.size()==0)
        {
            s.push(x);
            mn=x;
        }
        else
        {
            if(x>=mn)s.push(x);
            else if(x<mn)
            {
                s.push(2*(long long)x-mn);
                mn=x;
            }
        }
    }
    
    void pop() 
    {
        if(s.size()==0)return ;
        else
        {
            if(s.top()>=mn)s.pop();
            else if(s.top()<mn)
            {
                mn=2*(long long)mn-s.top();
                s.pop();
            }
        }
        
    }
    
    int top() 
    {
       if(s.size()==0)return -1;
       else
       {
           if(s.top()>=mn)return s.top();
           
       }
        return mn;
        
    }
    
    int getMin() 
    {
        if(s.size()==0)return -1;
        return mn;
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
