/*Find n-th node of inorder traversal*/
#include "build.cpp"
void inNthSuccessor(node *root, int n) {
	if(!root) return;
	inNthSuccessor(root->left, n);
	static int c = 1;
	if(c == n) {
		cout << root->data << endl;
	}
	c++;
	inNthSuccessor(root->right, n);
}
int main() {
	node root;
	createTree(&root);
	inorder(&root); cout << endl;
	int n; cin >> n;
	inNthSuccessor(&root, n);
}