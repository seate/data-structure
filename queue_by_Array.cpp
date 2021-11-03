#include <iostream>
using namespace std;

template<typename T>
class Queue{
private:
    int Maxsize;
    int idx;
    T *queue;

public:
    Queue(int Maxsize){
        idx = -1;
        queue = new T[Maxsize];
    }

    bool isEmpty(){return (idx == -1);}

    bool isFull(){return (idx == Maxsize - 1);}

    void add(T data){
        if (isFull()) cout << "queue is Full\n";
        else queue[++idx] = data;
    }

    T pop(){
        if (isEmpty()) cout << "queue is Empty\n";
        else return queue[idx--];
    }
};

int main(){
    Queue<int> q(5);

    cout << "q.isEmpty(): " << q.isEmpty() << "\n";
    cout << "q.isFull(): " << q.isFull() << "\n";
    cout << "q.pop(): " << q.pop() << "\n";

    q.add(123);
    q.add(234);
    q.add(345);
    q.add(456);
    q.add(567);
    q.add(678);

    cout << "q.isEmpty(): " << q.isEmpty() << "\n";
    cout << "q.isFull(): " << q.isFull() << "\n";
    cout << "q.pop(): " << q.pop() << "\n";
}