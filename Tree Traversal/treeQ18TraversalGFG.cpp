/*Perfect Binary Tree Specific Level Order Traversal*/
#include "build.cpp"
void specificLevelwise(node *root) {
	queue<node*> sq;
	if(!root) return;
	cout << root->data << " ";
	if(root->left) {
		sq.push(root->left);
		sq.push(root->right);
	}
	while(!sq.empty()) {
		int size = sq.size();
		for(int i = 0; i < size/2; i++) {
			node *left = sq.front(); sq.pop();
			node *right = sq.front(); sq.pop();
			cout << left->data << " " << right->data << " ";
			if(left->left) {
				sq.push(left->left);
				sq.push(right->right);
				sq.push(left->right);
				sq.push(right->left);
			}
		}
	}
}
int main() {
	node *root = new node;
	createTree(root);
	specificLevelwise(root);
}