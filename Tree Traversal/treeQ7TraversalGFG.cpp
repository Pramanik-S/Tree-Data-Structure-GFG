/*Replace each node in binary tree with the sum of its inorder predecessor and successor*/
#include<bits/stdc++.h>
#include "build.cpp"
using namespace std;
void inorderNode(vector<int> &in, node *root) {
	if(!root) return;
	inorderNode(in, root->left);
	in.push_back(root->data);
	inorderNode(in, root->right);
}
void inorderNodeSum(vector<int> &in, node *root, int &index) {
	if(!root) return;
	inorderNodeSum(in, root->left, index);
	root->data = in[index-1] + in[index+1];
	index++;
	inorderNodeSum(in, root->right, index);
}
void replacewith(node *root) {
	vector<int> in; in.push_back(0);
	inorderNode(in, root); in.push_back(0);
	int index = 1;
	inorderNodeSum(in, root, index);
}
int main() {
	node root;
	createTree(&root);
	preorder(&root); cout << endl;
	replacewith(&root);
	preorder(&root); cout << endl;
}