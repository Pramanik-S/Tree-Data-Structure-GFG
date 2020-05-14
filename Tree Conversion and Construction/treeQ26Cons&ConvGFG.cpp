/*Convert a given tree to its Sum Tree*/
#include "build.cpp"
int Convert(node *root) {
	if(!root) return 0;
	int temp = root->data;
	root->data = Convert(root->left) + Convert(root->right);
	return temp + root->data;
} 
int main() {
	node *root = new node;
	createTree(root);
	Convert(root);
	levelwise(root);
}