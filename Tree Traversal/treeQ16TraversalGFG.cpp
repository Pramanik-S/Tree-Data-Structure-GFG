/*Reverse Level Order Traversal*/
#include "build.cpp"
void revLevelwise(node *root) {
	if(!root) return;
	queue<node*> q;
	stack<node*> s;
	q.push(root);
	s.push(root);
	while(!q.empty()) {
		node *temp = q.front();
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) {
			q.push(temp->right);
			s.push(temp->right);
		}
		if(temp->left) s.push(temp->left);
	}
	while(!s.empty()) {
		cout << s.top()->data << " ";
		s.pop();
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	revLevelwise(root);
}