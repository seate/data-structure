#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *parent = NULL, *left = NULL, *right = NULL;
};

class BinarySearchTree{
private:
    Node *root;

public:
    BinarySearchTree(){root = NULL;}

    bool isroot(){return root != NULL;}
    Node *getroot(){return root;}

    void add(int data){
        Node *newNode = new Node();
        newNode->data = data;

        if (!isroot()){root = newNode;}
        else{
            Node *curNode = root;

            while(true){
                if(data < curNode->data){
                    if(curNode->left != NULL){curNode = curNode->left;}
                    else{
                        curNode->left = newNode;
                        newNode->parent = curNode;
                        break;
                    }
                }
                else{
                    if(curNode->right != NULL){curNode = curNode->right;}
                    else{
                        curNode->right = newNode;
                        newNode->parent = curNode;
                        break;
                    }
                }

            }
        }
    }

    void pop(int data){
        if (!isroot()){
            cout << "binary_search_tree is empty\n";
            return;
        }

        Node *curNode = root;
        
        if(curNode->data == data){
            if(curNode->left !=  NULL && curNode->right != NULL){
                curNode = curNode->left;
                while(curNode->right != NULL) curNode = curNode->right;
                
                if (curNode->left != NULL){
                    curNode->left->parent = curNode->parent;
                    curNode->parent->left = curNode->left;
                }
                else curNode->parent->right = NULL;

                root->data = curNode->data;
            }
            else if(curNode->left != NULL){
                curNode->left->parent = NULL;
                root = curNode->left;
            }
            else if(curNode->right != NULL){
                curNode->right->parent = NULL;
                root = curNode->right;
            }
            else{root = NULL;}

            return;
        }
        
        while(true){
            if(curNode->data == data){
                if(curNode->left !=  NULL && curNode->right != NULL){
                    Node *leaf = curNode->left;
                    while(leaf->right != NULL) leaf = leaf->right;
                    
                    if (leaf->left != NULL){
                        leaf->left->parent = leaf->parent;
                        leaf->parent->right = leaf->left;
                    }
                    else leaf->parent->right = NULL;

                    curNode->data = leaf->data;
                }
                else if(curNode->left != NULL){
                    curNode->left->parent = curNode->parent;
                    curNode->parent->left = curNode->left;
                }
                else if(curNode->right != NULL){
                    curNode->right->parent = curNode->parent;
                    curNode->parent->right = curNode->right;
                }
                else{
                    if(curNode->data < curNode->parent->data) curNode->parent->left = NULL;
                    else curNode->parent->right = NULL;
                }

                break;
            }
            else if(data < curNode->data) curNode = curNode->left;
            else curNode = curNode->right;
        }
    }

    void preorder(Node *curNode){
        cout << curNode->data << " ";
        if (curNode->left != NULL) preorder(curNode->left);
        if (curNode->right != NULL) preorder(curNode->right);
    }

    void inorder(Node *curNode){
        if (curNode->left != NULL) inorder(curNode->left);
        cout << curNode->data << " ";
        if (curNode->right != NULL) inorder(curNode->right);
    }

    void postorder(Node *curNode){
        if (curNode->left != NULL) postorder(curNode->left);
        if (curNode->right != NULL) postorder(curNode->right);
        cout << curNode->data << " ";
    }
};

int main(){
    BinarySearchTree bst;

    bst.add(3);
    bst.add(8);
    bst.add(6);
    bst.add(7);
    bst.add(4);
    bst.add(5);
    bst.add(9);
    bst.add(2);
    bst.add(1);

    bst.preorder(bst.getroot());
    cout << "\n";
    bst.pop(8);
    bst.preorder(bst.getroot());
    cout << "\n";
}