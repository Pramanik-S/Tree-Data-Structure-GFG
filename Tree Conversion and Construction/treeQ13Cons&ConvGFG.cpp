/*Create a Doubly Linked List from a Ternary Tree*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left, *middle, *right;
	node(int data = 0) {
		this->data = data;
		this->left = NULL;
		this->middle = NULL;
		this->right = NULL;
	}
};
void createTree(node *root) {
	queue<node*> q;
	int data; cin >> data;
	if(data == -1) return;
	root->data = data;
	q.push(root);
	while(!q.empty()) {
		node *temp = q.front(); q.pop();
		int l, m, r; cin >> l >> m >> r;
		if(l != -1) {
			temp->left = new node(l);
			q.push(temp->left);
		}
		if(m != -1) {
			temp->middle = new node(m);
			q.push(temp->middle);
		}
		if(r != -1) {
			temp->right = new node(r);
			q.push(temp->right);
		}
	}
}
void createList(node *root, node **head, node **tail) {
	if(!root) return;
	node *left = root->left;
	node *middle = root->middle;
	node *right = root->right;
	if(!(*head)) {
		(*head) = root;
		(*head)->left = (*head)->middle = (*head)->right = NULL;
		(*tail) = (*head);
	}
	else {
		(*tail)->right = root;
		root->left = (*tail);
		root->middle = root->right = NULL;
		(*tail) = root;
	}
	createList(left, head, tail);
	createList(middle, head, tail);
	createList(right, head, tail);

}
void displayList(node *head) {
	while(head) {
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	node *head = NULL, *tail = NULL;
	createList(root, &head, &tail);
	displayList(head);
}