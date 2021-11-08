#include <iostream>
using namespace std;

template<typename T>
class Priority_queue{
private:
    int cursize;
    int Maxsize;
    pair<int, T> *priority_queue;

public:
    Priority_queue(int size){
        T temp;
        cursize = 0;
        Maxsize = size;
        priority_queue = new pair<int, T>[Maxsize + 1];
        priority_queue[0] = make_pair(-(1 << 9), temp);
    }

    void add(int priority, T data){
        if(Maxsize <= cursize) cout << "priority_queue is full\n";
        else{
            int curidx = cursize + 1;
            priority_queue[curidx] = make_pair(priority, data);
            while(priority_queue[curidx / 2].first > priority_queue[curidx].first){
                priority_queue[curidx] = priority_queue[curidx / 2];
                curidx /= 2;
            }
            priority_queue[curidx] = make_pair(priority, data);
            cursize++;
        }
    }

    T pop(){
        if (cursize <= 0) cout << "priority_queue is Empty\n";
        else{
            T for_return = priority_queue[1].second;
            pair<int, T> now = priority_queue[1] = priority_queue[cursize--];
            int curidx = 1;
            while(curidx * 2 + 1 <= cursize){
                int nextidx = curidx * 2;
                nextidx += (priority_queue[nextidx].first > priority_queue[nextidx + 1].first);
                pair<int, T> smaller = priority_queue[nextidx];

                if(smaller.first < now.first){
                    priority_queue[curidx] = smaller;
                    curidx = nextidx;
                }
                else{
                    priority_queue[curidx] = now;
                    break;
                }
            }
            if (curidx * 2 <= cursize && priority_queue[curidx * 2].first < now.first){
                priority_queue[curidx] = priority_queue[curidx * 2];
                priority_queue[curidx * 2] = now;
            }
            else priority_queue[curidx] = now;

            return for_return;
        }
    }

    void Print(){
        for (int i = 1; i < cursize + 1; i++) cout << priority_queue[i].second << " ";
        cout << "\n";
    }
};

int main(){
    Priority_queue<int> pq(5);
    pq.add(1, 123);
    pq.add(28342, 456);
    pq.add(2, 123034);
    pq.add(7, 22);
    pq.add(11, 76);
    pq.add(0, 95);

    pq.Print();

    cout << "pop: " << pq.pop() << "\n";
    cout << "pop: " << pq.pop() << "\n";
    cout << "pop: " << pq.pop() << "\n";
    cout << "pop: " << pq.pop() << "\n";
    cout << "pop: " << pq.pop() << "\n";
    cout << "pop: " << pq.pop() << "\n";
}