#include <iostream>
using namespace std;

#define MAX (1 << 9);

class Heap{
private:
    int cursize;
    int Maxsize;
    int *heap;
public:
    Heap(int size){
        cursize = 0;
        Maxsize = size;
        heap = new int[Maxsize + 1];
        heap[0] = -MAX;
    }

    void add(int data){
        if(Maxsize <= cursize) cout << "heap is full\n";
        else{
            int curidx = cursize + 1;
            heap[curidx] = data;
            while(heap[curidx / 2] > heap[curidx]){
                heap[curidx] = heap[curidx / 2];
                curidx /= 2;
            }
            heap[curidx] = data;
            cursize++;
        }
    }

    int pop(){
        if (cursize <= 0) cout << "heap is Empty\n";
        else{
            int for_return = heap[1];
            int now = heap[1] = heap[cursize--];
            int curidx = 1;
            while(curidx * 2 + 1 <= cursize){
                int nextidx = curidx * 2;
                nextidx += (heap[nextidx] > heap[nextidx + 1]);
                int smaller = heap[nextidx];

                if(smaller < now){
                    heap[curidx] = smaller;
                    curidx = nextidx;
                }
                else{
                    heap[curidx] = now;
                    break;
                }
            }
            if (curidx * 2 <= cursize && heap[curidx * 2] < now){
                heap[curidx] = heap[curidx * 2];
                heap[curidx * 2] = now;
            }
            else heap[curidx] = now;

            return for_return;
        }
    }

    void Print(){
        cout << "cursize: " << cursize << "\n";
        for (int i = 1; i < Maxsize + 1; i++) cout << heap[i] << " ";
        cout << "\n\n";
    }
};

int main(){
    Heap h(5);
    h.add(4);
    h.add(3);
    h.add(2);
    h.add(10);
    h.add(123);
    h.add(4444);

    cout << "pop:" << h.pop() << "\n";
    cout << "pop:" << h.pop() << "\n";
    cout << "pop:" << h.pop() << "\n";
    cout << "pop:" << h.pop() << "\n";
    cout << "pop:" << h.pop() << "\n";
    cout << "pop:" << h.pop() << "\n";
}