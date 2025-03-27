#include<iostream>
#include<stack>

using namespace std;


class SortedStack{
public:
	stack<int> s;
	void sort();
};


/* The below method sorts the stack s 
you are required to complete the below method */


void insert(stack<int> &s, int temp){
    if (s.empty() || temp > s.top()){
        s.push(temp);
        return;
    }
    
    int ele = s.top();
    s.pop();
    insert(s,temp);
    s.push(ele);
    
}



void SortedStack :: sort()
{
    
   if (s.empty()){
       return;
   }
   int temp = s.top();
   s.pop();
   sort();
   insert(s, temp);
}





// iterative approach

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();

        // while temporary stack is not empty and top
        // of stack is lesser than temp
        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in temporary of stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

// main function
int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    // This is the temporary stack
    stack<int> tmpStack = sortStack(input);
    while (!tmpStack.empty())
    {
        cout << tmpStack.top()<< " ";
        tmpStack.pop();
    }
}