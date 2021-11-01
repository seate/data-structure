#include <iostream>
using namespace std;

template<typename T>
class Stack{
private:
    int MaxSize;
    int _top;
    T *stack;

public:
    Stack(int size){
        MaxSize = size;
        _top = -1;
        stack = new T[MaxSize];
    }

    bool isFull() {return (MaxSize - 1 <= _top);}

    bool isEmpty() {return (_top == -1);}

    void push(T data){
        if (isFull()) printf("Stack is FULL\n");
        else stack[++_top] = data;
    }

    T pop(){
        if (isEmpty()) printf("stack is Empty\n");
        else return stack[_top--];
    }

    T top(){
        if (isEmpty()) printf("stack is Empty\n");
        else return stack[_top];
    }

    void Print(){
        for (int i = 0; i <= _top; i++) cout << i << " ";
        cout << "\n";
    }
};

int main(){
    Stack<int> st(5);
    
    cout << st.isEmpty() << "\n";
    cout << st.isFull() << "\n";
    cout << st.top() << "\n";
    cout << st.pop() << "\n";
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.isEmpty() << "\n";
    cout << st.isFull() << "\n";
    cout << st.top() << "\n";
    cout << st.pop() << "\n";
    st.Print();
}