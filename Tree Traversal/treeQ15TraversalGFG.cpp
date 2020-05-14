/*Level order traversal with direction change after every two levels*/
#include "build.cpp"
void twolevelSpiral(node *root) {
	if(!root) return;
	stack<node*> l1;
	queue<node*> l2;
	l1.push(root);
	bool flag = true;
	while(!l1.empty()) {
		if(flag) {
			while(!l1.empty()) {
				cout << l1.top()->data << " ";
				if(l1.top()->left) l2.push(l1.top()->left);
				if(l1.top()->right) l2.push(l1.top()->right);
				l1.pop();
				flag = false;
			}
			cout << endl;
			while(!l2.empty()) {
				cout << l2.front()->data << " ";
				if(l2.front()->left) l1.push(l2.front()->left);
				if(l2.front()->right) l1.push(l2.front()->right);
				l2.pop();
			}
		}
		else {
			while(!l1.empty()) {
				cout << l1.top()->data << " ";
				if(l1.top()->right) l2.push(l1.top()->right);
				if(l1.top()->left) l2.push(l1.top()->left);
				l1.pop();
				flag = true;
			}
			cout << endl;
			while(!l2.empty()) {
				cout << l2.front()->data << " ";
				if(l2.front()->right) l1.push(l2.front()->right);
				if(l2.front()->left) l1.push(l2.front()->left);
				l2.pop();
			}
		}
		cout << endl;
	}
}
int main() {
	node root;
	createTree(&root);
	twolevelSpiral(&root);
}