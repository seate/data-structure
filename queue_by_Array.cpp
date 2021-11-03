#include <iostream>
using namespace std;

template<typename T>
class Queue{
private:
    int Maxsize;
    int curidx;
    T *queue;

public:
    Queue(int size){
        Maxsize = size;
        curidx = -1;
        queue = new T[Maxsize];
    }

    bool isEmpty(){return (curidx == -1);}

    bool isFull(){return (curidx == Maxsize - 1);}

    void add(T data){
        if (isFull()) cout << "queue is Full\n";
        else queue[++curidx] = data;
    }

    T pop(){
        if (isEmpty()) cout << "queue is Empty\n";
        else{
            T temp = queue[0];
            for (int i = 0; i < curidx; i++) queue[i] = queue[i + 1];
            curidx--;
            return temp;
        }
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
    cout << "q.pop(): " << q.pop() << "\n";
    cout << "q.pop(): " << q.pop() << "\n";
    cout << "q.pop(): " << q.pop() << "\n";
    cout << "q.pop(): " << q.pop() << "\n";
}