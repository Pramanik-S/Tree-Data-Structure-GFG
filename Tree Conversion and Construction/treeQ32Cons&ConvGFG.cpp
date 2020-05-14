/*Convert a given Binary tree to a tree that holds Logical AND property*/
#include "build.cpp"
void ConvertAndTree(node *root) {
	if(!root) return;
	ConvertAndTree(root->left);
	ConvertAndTree(root->right);
	if(root->left and root->right) root->data = root->left->data & root->right->data;
}
int main() {
	node *root = new node;
	createTree(root);
	ConvertAndTree(root);
	levelwise(root);
}