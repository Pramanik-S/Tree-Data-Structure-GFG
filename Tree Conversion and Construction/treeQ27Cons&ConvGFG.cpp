/*Change a Binary Tree so that every node stores sum of all nodes in left subtree*/
#include "build.cpp"
int Convert(node *root) {
	if(!root) return 0;
	int l = Convert(root->left);
	int r = Convert(root->right);
	root->data += l;
	return root->data+r;
} 
int main() {
	node *root = new node;
	createTree(root);
	Convert(root);
	levelwise(root);
}