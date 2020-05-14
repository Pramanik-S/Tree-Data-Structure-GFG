/*Inorder Successor of a node in Binary Tree*/
#include "build.cpp"
struct temp
{
	node *next;
};
void helper(node *root, temp &ptr, int x) {
	if(!root) return;
	helper(root->left, ptr, x);
	if(ptr.next && ptr.next->data == x) {
		cout << root->data << endl;
		ptr.next = NULL;
	}
	else ptr.next = root;
	helper(root->right, ptr, x);
}
void inSuccessor(node *root, int x) {
	temp ptr;
	ptr.next = NULL;
	helper(root, ptr, x);
}
int main() {
	node root;
	createTree(&root);
	inorder(&root); cout << endl;
	int x; cin >> x;
	inSuccessor(&root, x);
}