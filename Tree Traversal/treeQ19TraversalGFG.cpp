/*Perfect Binary Tree Specific Level Order Traversal | Set 2*/
#include "build.cpp"
void specificLevelwise(node *root) {
	if(!root) return;
	queue<node*> q;
	stack<node*> s;
	s.push(root);
	if(root->left) {
		q.push(root->right);
		q.push(root->left);
	}
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size/2; i++) {
			node *left = q.front(); q.pop();
			node *right = q.front(); q.pop();
			s.push(left);
			s.push(right);
			if(left->left) {
				q.push(left->left);
				q.push(right->right);
				q.push(left->right);
				q.push(right->left);
			}
		}
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
	specificLevelwise(root);
}