/*Convert Ternary Expression to a Binary Tree*/
#include<bits/stdc++.h>
using namespace std;
struct node {
	char data;
	node *left, *right;
	node(char data = 0) {
		this->data = data;
		this->left = this->right = NULL;
	}
};
node* Construct(string exp, int &index) {
	if(index >= exp.length()) return NULL;
	node *temp = new node(exp[index++]);
	if(exp[index] == '?') temp->left = Construct(exp, ++index);
	else temp->right = Construct(exp, ++index);
	return temp;
}
void preorder(node *root) {
	if(!root) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	string exp; cin >> exp;
	int index = 0;
	node *root = Construct(exp, index);
	preorder(root);
}