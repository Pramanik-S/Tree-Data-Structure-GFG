/*Postorder traversal of Binary Tree without recursion and without stack*/
#include "build.cpp"
void iterativePO(node *root) {
	if(!root) return;
	unordered_map<node*, bool> visited;
	node *curr = root;
	while(curr and !visited[curr]) {
		if(curr->left and !visited[curr->left]) {
			curr = curr->left;
		} else if(curr->right and !visited[curr->right]) {
			curr = curr->right;
		} else {
			cout << curr->data << " ";
			visited[curr] = true;
			curr = root;
		}
	}
	cout << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	postorder(root); cout << endl;
	iterativePO(root);
}