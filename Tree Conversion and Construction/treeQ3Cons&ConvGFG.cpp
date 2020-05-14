/*Construct Complete Binary Tree from its Linked List Representation*/
#include "build.cpp"
struct lnode {
	int data;
	lnode *next;
	lnode(int data = 0) {
		this->data = data;
		this->next = NULL;
	}
};
void createList(lnode *head) {
	lnode *tail = head;
	while(true) {
		int x; cin >> x;
		if(x == -1) break;
		if(!head->next) head->next = new lnode(x);
		else tail->next = new lnode(x);
		tail = tail->next;
	}
}
void display(lnode *head) {
	lnode *temp = head->next;
	while(temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void listToTree(node *root, lnode *head) {
	lnode *temp = head->next;
	root->data = temp->data;
	queue<node*> q;
	q.push(root);
	temp = temp->next;
	while(temp) {
		q.front()->left = new node(temp->data);
		q.push(q.front()->left);
		temp = temp->next;
		if(temp) {
			q.front()->right = new node(temp->data);
			q.push(q.front()->right);
			temp = temp->next;
		}
		q.pop();
	}
}
int main() {
	lnode *head = new lnode;
	node *root = new node;
	createList(head);
	display(head);
	listToTree(root, head);
	levelwise(root);
}