#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

void LevelOrder(Node *root) {
    if (root == NULL) return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* current = Q.front();
        Q.pop(); //removing the element at front
        cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
    }
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

	LevelOrder(root);
}
