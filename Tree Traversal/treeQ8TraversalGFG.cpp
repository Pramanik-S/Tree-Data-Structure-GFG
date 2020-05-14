/*Populate Inorder Successor for all nodes*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left, *right, *next;
	node(int data = 0) {this->data = data; this->left = this->right = this->next = NULL;}
};
void createTree(node *root) {
	int data, left, right;
	cin >> data;
	if(data == -1) return;
	root->data = data;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node *p = q.front();
		q.pop();
		cin >> left >> right;
		if(left != -1) {
			p->left = new node(left);
			q.push(p->left);
		}
		if(right != -1) {
			p->right = new node(right);
		}
	}
}
void connectInorderSuccessor(node *root, node &next) {
	if(!root) return;
	connectInorderSuccessor(root->left, next);
	if(next.next) {
		next.next->next = root;
	} 
	next.next = root;
	connectInorderSuccessor(root->right, next);
}
void populateInorder(node *root) {
	node next;
	next.next = NULL;
	connectInorderSuccessor(root, next);
}
void inorderSuccessor(node *root) {
	if(!root) return;
	inorderSuccessor(root->left);
	cout << root->data << "->";
	if(root->next) cout << root->next->data;
	else cout << "NULL";
	cout << endl;
	inorderSuccessor(root->right);
}
int main() {
	node root;
	createTree(&root);
	populateInorder(&root);
	inorderSuccessor(&root);
	cout << endl;
}