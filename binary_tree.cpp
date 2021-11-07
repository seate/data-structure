#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T> *parent, *left, *right;
};

template<typename T>
class BinaryTree{
private:
    Node<T> *root;
    Node<T> *curNode;

public:
    BinaryTree(){root = NULL;}

    Node<T> *getroot(){return root;}
    Node<T> *getcurNode(){return curNode;}

    void goroot(){
        if (root != NULL) curNode = root;
        else cout << "root is NULL\n";
    }

    void goparent(){
        if (curNode->parent != NULL) curNode = curNode ->parent;
        else cout << "parent is NULL\n";
    }
    
    void goleft(){
        if (curNode->left != NULL) curNode = curNode->left;
        else cout << "left is NULL\n";
    }
    void goright(){
        if (curNode->right != NULL) curNode = curNode->right;
        else cout << "right is NULL\n";
    }

    void setroot(T data){
        Node<T> *newroot = new Node<T>();
        newroot->data = data;
        curNode = root = newroot;
    }

    void setchild(T leftdata, T rightdata){
        if (leftdata != NULL){
            Node<T> *newleft = new Node<T>();
            newleft->data = leftdata;
            curNode->left = newleft;
            newleft->parent = curNode;
        }
        if (rightdata != NULL){
            Node<T> *newright = new Node<T>();
            newright->data = rightdata;
            curNode->right = newright;
            newright->parent = curNode;
        }
    }

    void preorder(Node<T> *presentNode){
        cout << presentNode->data << " ";
        if (presentNode->left != NULL) preorder(presentNode->left);
        if (presentNode->right != NULL) preorder(presentNode->right);
    }

    void inorder(Node<T> *presentNode){
        if (presentNode->left != NULL) inorder(presentNode->left);
        cout << presentNode->data << " ";
        if (presentNode->right != NULL) inorder(presentNode->right);
    }

    void postorder(Node<T> *presentNode){
        if (presentNode->left != NULL) postorder(presentNode->left);
        if (presentNode->right != NULL) postorder(presentNode->right);
        cout << presentNode->data << " ";
    }
};

int main(){
    BinaryTree<int> bt;
    bt.setroot(1);

    bt.setchild(2, 3);
    bt.goleft();
    bt.setchild(4, 5);
    bt.goparent();
    bt.goright();
    bt.setchild(6, 7);

    bt.preorder(bt.getroot());
    cout << "\n";
    bt.inorder(bt.getroot());
    cout << "\n";
    bt.postorder(bt.getroot());
    cout << "\n";
}