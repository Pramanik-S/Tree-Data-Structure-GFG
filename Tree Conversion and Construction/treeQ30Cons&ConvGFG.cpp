/*Convert a Binary Tree to a Circular Doubly Link List*/
#include "build.cpp"
void ConvertCircularDoublyList(node *root, node **head) {
	if(!root) return;
	ConvertCircularDoublyList(root->left, head);
	node *t = root->right;
	if(!(*head)) {
		(*head) = root;
		root->left = root->right = root;
	}
	else {
		(*head)->left->right = root;
		root->left = (*head)->left->right;
		(*head)->left = root;
		root->right = (*head);
	}
	ConvertCircularDoublyList(t, head);
}
void displayList(node *head) {
	node *p = head;
	while(p->right != head) {
		cout << p->data << " ";
		p = p->right;
	}
	cout << p->data << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	node *head = NULL;
	ConvertCircularDoublyList(root, &head);
	displayList(head);
}