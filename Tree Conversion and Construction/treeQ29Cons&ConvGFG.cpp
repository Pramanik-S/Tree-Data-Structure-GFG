/*Convert a Binary Tree into Doubly Linked List in spiral fashion*/
#include "build.cpp"
void ConvertSpiralDoublyList(node *root, node **head, node **tail) {
	stack<node*> left, right;
	left.push(root);
	while(!left.empty() or !right.empty()) {
		while(!left.empty()) {
			if(left.top()->right) right.push(left.top()->right);
			if(left.top()->left)  right.push(left.top()->left);
			if(!(*head)) {
				(*head) = left.top();
				left.top()->left = NULL;
				(*tail) = left.top();
			}
			else {
				(*tail)->right = left.top(); 
				(*tail) = left.top();
			}
			left.pop();
		}
		while(!right.empty()) {
			if(right.top()->left)  left.push(right.top()->left);
			if(right.top()->right) left.push(right.top()->right);
			if(!(*head)) {
				(*head) = right.top();
				right.top()->left = NULL;
				(*tail) = right.top();
			}
			else {
				(*tail)->right = right.top(); 
				(*tail) = right.top();
			}
			right.pop();
		}
	}
} 
void displayList(node *head) {
	while(head) {
		cout << head->data << " ";
		head = head->right;
	}
}
int main() {
	node *root = new node;
	createTree(root);
	node *head = NULL, *tail = NULL;
	ConvertSpiralDoublyList(root, &head, &tail);
	displayList(head);
}