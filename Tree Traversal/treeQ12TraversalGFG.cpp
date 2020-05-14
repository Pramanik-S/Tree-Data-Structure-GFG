/*Level Order Tree Traversal*/
#include "build.cpp"
void  levelwise(node *root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		cout << q.front()->data << " ";
		if(q.front()->left) q.push(q.front()->left);
		if(q.front()->right) q.push(q.front()->right);
		q.pop();
	}
	cout << endl;
}
int main() {
	node root;
	createTree(&root);
	levelwise(&root);
}