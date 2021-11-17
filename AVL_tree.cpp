#include <iostream>
using namespace std;

struct Node
{
    int data, height = 0;
    Node *parent = NULL, *left = NULL, *right = NULL;

};

class AVLtree{
private:
    Node *root;

public:
    AVLtree(){root = NULL;}

    Node *getroot(){return root;}

    int getHeight(Node *curNode){
        if (curNode == NULL) return -1;
        int Lheight = (curNode->left == NULL) ? -1 : curNode->left->height;
        int Rheight = (curNode->right == NULL) ? -1 : curNode->right->height;

        return 1 + max(Lheight, Rheight);
    }

    int getBalanceFactor(Node *curNode){return (getHeight(curNode->left) - getHeight(curNode->right));}

    void rightrotate(Node *N1){
        Node *N2 = N1->left;

        if(N1->parent != NULL){
            if(N1->data < N1->parent->data) N1->parent->left = N2;
            else N1->parent->right = N2;
        }
        else root = N2;

        N1->left = N2->right;
        N2->parent = N1->parent;
        N1->parent = N2;
        N2->right = N1;

        N1->height = getHeight(N1);
        N2->height = getHeight(N2);
    }

    void leftrotate(Node *N1){
        Node *N2 = N1->right;

        if(N1->parent != NULL){
            if(N1->data < N1->parent->data) N1->parent->left = N2;
            else N1->parent->right = N2;
        }
        else root = N2;

        N1->right = N2->left;
        N2->parent = N1->parent;
        N1->parent = N2;
        N2->left = N1;

        N1->height = getHeight(N1);
        N2->height = getHeight(N2);
    }

    void rebalance(Node *N1){
        Node *N2;
        if(1 < getBalanceFactor(N1)){
            N2 = N1->left;
            if(N1->parent != NULL){
                if(N1->data < N1->parent->data) N1->parent->left = N2;
                else N1->parent->right = N2;
            }

            if(0 < getBalanceFactor(N2)) rightrotate(N1);
            else{
                leftrotate(N2);
                rightrotate(N1);
            }
        }
        else{
            N2 = N1->right;
            if(N1->parent != NULL){
                if(N1->data < N1->parent->data) N1->parent->left = N2;
                else N1->parent->right = N2;
            }

            if(0 < getBalanceFactor(N2)){
                rightrotate(N2);
                leftrotate(N1);
            }
            else leftrotate(N1);
        }
    }

    void add(Node *curNode, int data){
        if(data < curNode->data && curNode->left != NULL) add(curNode->left, data);
        else if(curNode->data < data && curNode->right != NULL) add(curNode->right, data);
        else{
            Node *newNode = new Node();
            newNode->data = data;
            newNode->parent = curNode;
            
            if(data < curNode->data) curNode->left = newNode;
            else curNode->right = newNode;
        }

        curNode->height = getHeight(curNode);
        int BF = getBalanceFactor(curNode);
        if(BF < -1 || 1 < BF) rebalance(curNode);
    }

    void add(int data){
        if(root == NULL){
            Node *newNode = new Node();
            newNode->data = data;
            root = newNode;
        }
        else add(root, data);
    }

    void postorder(Node *curNode){
        cout << curNode->data << " ";
        if(curNode->left != NULL) postorder(curNode->left);
        if(curNode->right != NULL) postorder(curNode->right);
    }
};

int main(){
    AVLtree avl;
    
    avl.add(20);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(15);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(3);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(12);
    avl.postorder(avl.getroot());
    cout << "\n";
    
    avl.add(5);
    avl.postorder(avl.getroot());
    cout << "\n";
    
    avl.add(11);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(6);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(40);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(25);
    avl.postorder(avl.getroot());
    cout << "\n";

    avl.add(18);
    avl.postorder(avl.getroot());
    cout << "\n";
}