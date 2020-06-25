#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

void Preorder (Node *root) {
    if (root == NULL) return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder (Node *root) {
    if (root == NULL) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder (Node *root) {
    if (root == NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    // (*newNode).data = data;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){
    if(root == NULL) {
        // empty tree
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main() {
	Node* root = NULL;	// creating an empty tree
	root = Insert(root,'M');
	root = Insert(root,'B');
	root = Insert(root,'Q');
	root = Insert(root,'Z');
	root = Insert(root,'A');
	root = Insert(root,'C');

	Inorder(root);
}

