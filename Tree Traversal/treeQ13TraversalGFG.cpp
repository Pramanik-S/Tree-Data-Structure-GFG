/*Level order traversal in spiral form*/
#include "build.cpp"
void spiralorder(node *root) {
	stack<node*> left, right;
	if(!root) return;
	left.push(root);
	while(!left.empty() or !right.empty()) {
		while(!left.empty()) {
			cout << left.top()->data << " ";
			if(left.top()->right) right.push(left.top()->right);
			if(left.top()->left) right.push(left.top()->left);
			left.pop();
		}
		while(!right.empty()) {
			cout << right.top()->data << " ";
			if(right.top()->left) left.push(right.top()->left);
			if(right.top()->right) left.push(right.top()->right);
			right.pop();
		}
	}
}
int main() {
	node root;
	createTree(&root);
	spiralorder(&root);
}