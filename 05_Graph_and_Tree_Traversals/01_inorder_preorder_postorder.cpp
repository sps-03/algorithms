/*
TREE TRAVERSALS : INORDER - PREORDER - POSTORDER:
    These are different types of Tree Traversals (DFS).
    
    visiting order:
        INORDER    : left -> root -> right
        PREORDER   : root -> left -> right
        POSTORDER  : left -> right -> root 

    Time Complexity          : O(V)         // we need to visit all vertices.
    Auxiliary Space          : O(1)         // without considering space for tree and stack.

    A tree can be represented using array or linkedlist.
    Here we are using linkedlist implementation.
*/

#include <iostream>
using namespace std;


// structure to represent a node in a binary tree
struct Node {
    int val;
    Node *left, *right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root) {
    if(root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    /* Make a Tree
                        3
                       / \
                      /   \
                     7    10
                    / \   / \
                   21 13 17  6
                      /
                     20
    */
    Node *root = new Node(3);
    root->left = new Node(7);
    root->right = new Node(10);
    root->left->left = new Node(21);
    root->left->right = new Node(13);
    root->right->left = new Node(17);
    root->right->right = new Node(6);
    root->left->right->left = new Node(20);

    cout << "PreOrder traversal : ";
    preorder(root);
    cout << "\n\nInOrder traversal : ";
    inorder(root);
    cout << "\n\nPostOrder traversal : ";
    postorder(root);
    cout << "\n\n";

    return 0;
}