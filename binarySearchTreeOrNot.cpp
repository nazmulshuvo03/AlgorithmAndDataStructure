#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

/***************************************************

// Longer Process

bool IsSubtreeLesser(Node* root, int value){
    if(root == NULL) return true;

    if(root->data <= value
        && IsSubtreeLesser(root->left, value)
        && IsSubtreeLesser(root->right, value))
        return true;
    else return false;
}

bool IsSubtreeGreater(Node* root, int value){
        if(root == NULL) return true;

    if(root->data > value
        && IsSubtreeGreater(root->left, value)
        && IsSubtreeGreater(root->right, value))
        return true;
    else return false;
}

bool IsBinarySearchTree(Node* root) {
    if(root == NULL) return true;

    if(IsSubtreeLesser(root->left, root->data)
        && IsSubtreeGreater(root->right, root->data)
        && IsBinarySearchTree(root->left)
        && IsBinarySearchTree(root->right))
        return true;
    else return false;
}

*************************************************************/

// Efficient Process

bool IsBstUtil(Node* root, int minValue, int maxValue) {
    if(root == NULL) return true;

    if(root->data > minValue
        && root->data < maxValue
        && IsBinarySearchTree(root->left, minValue, root->data)
        && IsBinarySearchTree(root->right, root->data, maxValue))
        return true;
    else return false;
}

bool IsBinarySearchTree(Node* root) {
    return IsBstUtil(root, INT_MAX, INT_MIN);
}

int main() {
    //pass
}
