/*Iterative Postorder Traversal | Set 2 (Using One Stack)*/
#include "build.cpp"
void iterativePO(node *root) {
	if(!root) return;
	stack<node*> s;
	do {
		while(root) {
			if(root->right) s.push(root->right);
			s.push(root);
			root = root->left;
		}
		root = s.top(); s.pop();
		if(root->right and !s.empty() and root->right == s.top()) {
			s.pop();
			s.push(root);
			root = root->right;
		} else {
			cout << root->data << " ";
			root = NULL;
		}
	}while(!s.empty());
}
int main() {
	node *root = new node;
	createTree(root);
	postorder(root); cout << endl;
	iterativePO(root);
}