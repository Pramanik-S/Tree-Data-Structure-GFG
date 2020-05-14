/*Iterative Preorder Traversal*/
#include "build.cpp"
void iterativePreorder(node *root) {
	if(!root) return;
	stack<node*> s;
	s.push(root);
	while(!s.empty()) {
		node *temp = s.top();
		s.pop();
		cout << temp->data << " ";
		if(temp->right) s.push(temp->right);
		if(temp->left) s.push(temp->left);
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	preorder(root); cout << endl;
	iterativePreorder(root);
}