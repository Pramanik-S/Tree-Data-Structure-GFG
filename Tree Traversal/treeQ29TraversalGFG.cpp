/*Density of Binary Tree in One Traversal*/
#include "build.cpp"
pair<int, int> helper(node *root) {
	if(!root) return {0, 0};
	pair<int, int> t1 = helper(root->left), t2 = helper(root->right);
	return {t1.first+t2.first+1, max(t1.second, t2.second)+1};
}
double density(node *root) {
	if(!root) return 0.0;
	pair<int, int> CH = helper(root);
	return CH.first/(double)CH.second;
}
int main() {
	node *root = new node;
	createTree(root);
	cout << density(root) << endl;
}