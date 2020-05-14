/*Convert an arbitrary Binary Tree to a tree that holds Children Sum Property*/
#include "build.cpp"
void incrementDiff(node *root, int diff) {
	root->data += diff;
	if(!root->left and !root->right) {
		return;
	}
	if(root->left) incrementDiff(root->left, diff);
	else incrementDiff(root->right, diff);

}
void convertSumTree(node *root) {
	if(!root || (!root->left and !root->right)) return;
	convertSumTree(root->left);
	convertSumTree(root->right);
	int diff;
	if(root->left and root->right) diff = root->data-(root->left->data+root->right->data);
	else if(!root->left) diff = root->data-root->right->data;
	else diff = root->data-root->left->data;
	if(diff < 0) root->data += abs(diff);
	else if(diff > 0) {
		if(root->left)	incrementDiff(root->left, diff);
		else incrementDiff(root->right, diff);
	}
}
int main() {
	node *root = new node;
	createTree(root);
	convertSumTree(root);
	levelwise(root);
}