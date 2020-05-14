/*Creating a tree with Left-Child Right-Sibling Representation*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *child, *next;
	node(int data = 0) {
		this->data = data;
		this->child = NULL;
		this->next = NULL;
	}
};
void Construct(node *root) {
	int data; cin >> data;
	if(data == -1)  return;
	root->data = data;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		cout << "Number of child of " << q.front()->data << ": ";
		int n; cin >> n;
		node *temp = q.front(); q.pop();
		if(!n) continue;
		if(temp->child) temp = temp->child;
		else {
			cin >> data;
			temp->child = new node(data);
			q.push(temp->child);
			n--;
			temp = temp->child;
		}
		for(int i = 0; i < n; i++) {
			cin >> data;
			while(temp->next) temp = temp->next;
			temp->next = new node(data);
			q.push(temp->next);
		}
	}
}
void traverse(node *root) {
	while(root) {
		cout << root->data << " ";
		if(root->child) traverse(root->child);
		root = root->next;
	}
}
int main() {
	node *root = new node;
	Construct(root);
	traverse(root); cout << endl;
}