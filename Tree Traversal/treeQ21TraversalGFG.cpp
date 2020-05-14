/*Morris traversal for Preorder*/
#include "build.cpp"
void preorderMoris(node *root) {
	node *curr = root;
	while(curr) {
		if(!curr->left) {
			cout << curr->data << " ";
			curr = curr->right;
		}
		else {
			node *pre = curr->left;
			while(pre->right and pre->right != curr) pre = pre->right;
			if(!pre->right) {
				cout << curr->data << " ";
				pre->right = curr;
				curr = curr->left;
			}
			else {
				pre->right = NULL;
				curr = curr->right;
			}
		}
	}
}
int main() {
	node *root = new node;
	createTree(root);
	preorder(root); cout << endl;
	preorderMoris(root);
}