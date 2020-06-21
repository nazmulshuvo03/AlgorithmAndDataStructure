#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

int FindHeight (BstNode* root) {
    if(root == NULL)
        return -1;

    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    // (*newNode).data = data;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
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
	BstNode* root = NULL;	// creating an empty tree
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	cout << FindHeight(root) << endl;
}
