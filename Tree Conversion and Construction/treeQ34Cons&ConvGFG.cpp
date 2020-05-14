/*Flip Binary Tree*/
#include "build.cpp"
node* flipTree(node *root) {
	if(!root || (!root->left and !root->right)) return root;
	node *temp = flipTree(root->left);
	root->left->left = root->right;
	root->left->right = root;
	root->left = NULL;
	root->right = NULL;
	return temp;
}
int main() {
	node *root = new node;
	createTree(root);
	levelwise(root);
	root = flipTree(root);
	levelwise(root);
}