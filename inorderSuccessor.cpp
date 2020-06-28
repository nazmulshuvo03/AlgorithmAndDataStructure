#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

//Function to find some data in the tree
Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
struct Node* FindMin(struct Node* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

//Function to find Inorder Successor in a BST
struct Node* Getsuccessor(struct Node* root, int data) {
	struct Node* current = Find(root, data);
	if(current == NULL) return NULL;

	// Case 1: Node has right subtree
	if(current->right != NULL) {
		return FindMin(current->right);
	}

	// Case 2: No right subtree
	else {
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data){
				successor = ancestor; // this is the deepest node
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	/*Code To Test the logic
	  Creating an example tree
	                    5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node.
	int node = 5;
	struct Node* successor = Getsuccessor(root,node);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor of "<< node <<" is "<<successor->data<<"\n";
}