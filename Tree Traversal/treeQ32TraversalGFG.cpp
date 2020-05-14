/*Modify a binary tree to get Preorder traversal using right pointers only*/
#include "build.cpp"
void convPre(node *root) {
	if(!root) return;
	stack<node*> s;
	node *pre = NULL;
	s.push(root);
	while(!s.empty()) {
		node *temp = s.top();
		s.pop();
		if(temp->right) s.push(temp->right);
		if(temp->left) s.push(temp->left);
		if(pre) {
			pre->right = temp;
		}
		pre = temp;
	}
}
void printRight(node *root) {
	while(root) {
		cout << root->data << " ";
		root = root->right;
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	preorder(root); cout << endl;
	convPre(root);
	printRight(root);
}