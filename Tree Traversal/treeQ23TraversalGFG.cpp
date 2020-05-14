/*Iterative Postorder Traversal | Set 1 (Using Two Stacks)*/
#include "build.cpp"
void iterativePO(node *root) {
	if(!root) return;
	stack<node*> s1, s2;
	s1.push(root);
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
		if(s2.top()->left) s1.push(s2.top()->left);
		if(s2.top()->right) s1.push(s2.top()->right);
	}
	while(!s2.empty()) {
		cout << s2.top()->data << " ";
		s2.pop();
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	postorder(root); cout << endl;
	iterativePO(root);
}