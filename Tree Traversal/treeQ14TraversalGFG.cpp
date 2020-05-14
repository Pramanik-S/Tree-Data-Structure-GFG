/*Print level order traversal line by line*/
#include "build.cpp"
void levelwiseLine(node *root) {
	if(!root) return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			cout << q.front()->data << " ";
			if(q.front()->left) q.push(q.front()->left);
			if(q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		cout << endl;
	}
}
int main() {
	node root;
	createTree(&root);
	levelwiseLine(&root);
}