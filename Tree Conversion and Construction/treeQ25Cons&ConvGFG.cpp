/*Convert left-right representation of a binary tree to down-right*/
#include "build.cpp"
void ConvertDownRight(node *root) {
	if(!root) return;
	ConvertDownRight(root->left);
	ConvertDownRight(root->right);
	if(root->left and root->right) {
		root->left->right = root->right;
		root->right = NULL;
	}
	else if(!root->left and root->right) {
		root->left = root->right;
		root->right = NULL;
	}
}
void downRightTraversal(node *root) {
	if(!root) return;
	cout << root->data << " ";
	downRightTraversal(root->left);
	downRightTraversal(root->right);
}
int main() {
	node *root = new node;
	createTree(root);
	ConvertDownRight(root);
	downRightTraversal(root);
	return 0;
}