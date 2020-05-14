/*Author:: SUMAN PRAMANIK
github:: github.com/Pramanik-S*/
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *left, *right;
	node(int data = 0) {this->data = data; this->left = this->right = NULL;}
};
void createTree(node *root) {
	queue<node*> q;
	int data; cin >> data;
	if(data == -1) return;
	root->data = data;
	q.push(root);
	while(!q.empty()) {
		node *t = q.front();
		q.pop();
		int left, right;
		cin >> left >> right;
		if(left != -1) {
			t->left = new node(left);
			q.push(t->left);
		}
		if(right != -1) {
			t->right = new node(right);
			q.push(t->right);
		}
	}
}
void postorder(node *root) {
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void inorder(node *root) {
	if(!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preorder(node *root) {
	if(!root) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void levelwise(node *root) {
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
	cout << endl;
}
