/*Write an Efficient Function to Convert a Binary Tree into its Mirror Tree*/
#include "build.cpp"
void Convert(node *root) {
	if(!root) return;
	Convert(root->left);
	Convert(root->right);
	swap(root->left, root->right);
} 
int main() {
	node *root = new node;
	createTree(root);
	Convert(root);
	levelwise(root);
}