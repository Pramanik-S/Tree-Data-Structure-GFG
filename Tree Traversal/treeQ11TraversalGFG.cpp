/*Find n-th node in Postorder traversal of a Binary Tree*/
#include "build.cpp"
void postNthSuccessor(node *root, int n) {
	if(!root) return;
	postNthSuccessor(root->left, n);
	postNthSuccessor(root->right, n);
	static int c = 1;
	if(c == n) {
		cout << root->data << endl;
	}
	c++;
}
int main() {
	node root;
	createTree(&root);
	postorder(&root); cout << endl;
	int n; cin >> n;
	postNthSuccessor(&root, n);
}