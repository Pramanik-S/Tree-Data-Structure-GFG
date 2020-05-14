/*Boundary Traversal of binary tree*/
#include "build.cpp"
void leafnode(node *root, queue<node*> &q) {
	if(!root) return;
	if(!root->left and !root->right) q.push(root);
	leafnode(root->left, q);
	leafnode(root->right, q);
}
void printBoundary(node *root) {
	if(!root) return;
	queue<node*> q;
	node *temp = root;
	while(temp->left) {
		q.push(temp);
		temp = temp->left;
	}
	leafnode(root, q);
	temp = root;
	stack<node*> s;
	while(temp->right) {
		s.push(temp);
		temp = temp->right;
	}
	while(!q.empty()) {
		cout << q.front()->data << " ";
		q.pop();
	}
	while(s.size() > 1) {
		cout << s.top()->data << " ";
		s.pop();
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	printBoundary(root);
}