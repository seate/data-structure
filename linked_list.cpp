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

    void Print(){
        Node<T> *temp = head;
        
        for (int i = 0; i < size; i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }


};

int main(){
    LinkedList<int> ll;

    cout << "ll.isEmpty(): " << ll.isEmpty() << "\n";
    ll.add(123, 0);
    ll.Print();

    ll.add(456, 0);
    ll.Print();
    
    ll.add(789, 2);
    ll.Print();

    cout << ll.pop(1) << "\n";
    cout << ll.pop(1) << "\n";
}