/*Iterative diagonal traversal of binary tree*/
#include "build.cpp"
void printDiagonal(node *root) {
	if(!root) return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			node *temp = q.front();
			q.pop();
			while(temp) {
				cout << temp->data << " ";
				if(temp->left) q.push(temp->left);
				temp = temp->right;
			}
		}
		cout << endl;
	}
}
int main() {
	node *root = new node;
	createTree(root);
	printDiagonal(root);
}