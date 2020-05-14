/*Convert a given Binary Tree to Doubly Linked List | Set 1*/
#include "build.cpp"
void createList(node *root, node **head, node **tail) {
	if(!root) return;
	createList(root->left, head, tail);
	if(!(*head)) {
		(*head) = root;
		root->left = NULL;
	}
	else {
		(*tail)->right = root;
		root->left = (*tail);
	}
	(*tail) = root;
	createList(root->right, head, tail);
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