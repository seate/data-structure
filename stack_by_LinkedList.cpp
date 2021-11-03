#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;
};

template<typename T>
class LinkedList{
private:
    int size;
    Node<T> *head, *tail;

public:
    LinkedList(){
        size = 0;
        head = tail = NULL;
    }

    bool isEmpty(){return (size == 0);}

    void add(T data, int idx){
        if (size < idx){
            cout << "Index error\n";
            return;
        }

        Node<T> *newNode = new Node<T>();
        newNode->data = data;

        if (isEmpty()) head = tail = newNode;
        else if (idx == 0){
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (idx == size){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else{
            Node<T> *temp;
            for (int i = 0; i < idx; i++) temp = temp->next;
            temp->prev->next = newNode;
            temp->next->prev = newNode;
        }
        size++;
    }

    T pop(int idx){
        if (size <= idx) cout << "Index error\n";
        else{
            Node<T> *temp;

            if (idx == 0){
                if (size == 1) head = tail = NULL;
                else{
                    temp = head;
                    head = head->next;
                    head->prev = NULL;
                }
            }
            else if (idx == size - 1){
                temp = tail;
                tail = tail->prev;
                tail->next = NULL;
            }
            else{
                temp = head;
                for (int i = 0; i < idx; i++) temp = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            
            size--;
            return temp->data;
        }
    }

    Node<T> *operator[](int idx){
        Node<T> *temp = head;
        for (int i = 0; i < idx; i++) temp = temp->next;
        return temp;
    }

    void Print(){
        Node<T> *temp = head;
        
        for (int i = 0; i < size; i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

template<typename T>
class Stack{
private:
    int _top;
    LinkedList<T> stack;

public:
    Stack(){_top = -1;}

    bool isEmpty() {return (_top == -1);}

    void push(T data){
        stack.add(data, ++_top);
    }

    T pop(){
        if (isEmpty()) cout << "stack is Empty\n";
        else return stack.pop(_top--);
    }

    T top(){
        if (isEmpty()) printf("stack is Empty\n");
        else return stack[_top]->data;
    }

    void Print(){
        for (int i = 0; i <= _top; i++) cout << i << " ";
        cout << "\n";
    }
};

int main(){
    Stack<int> st;
    
    cout << st.isEmpty() << "\n";
    cout << st.top() << "\n";
    cout << st.pop() << "\n";
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.isEmpty() << "\n";
    cout << st.top() << "\n";
    cout << st.pop() << "\n";
    st.Print();
}