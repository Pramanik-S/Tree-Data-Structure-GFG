/*Diagonal Traversal of Binary Tree*/
#include "build.cpp"
void helper(node *root, int d, map<int, vector<int>> &Diagonal) {
	if(!root) return;
	Diagonal[d].push_back(root->data);
	helper(root->left, d+1, Diagonal);
	helper(root->right, d, Diagonal);
}
void printDiagonal(node *root) {
	map<int, vector<int>> Diagonal;
	helper(root, 0, Diagonal);
	for(auto i:Diagonal) {
		for(auto v:i.second) cout << v << " ";
		cout << endl;
	}
}
int main() {
	node *root = new node;
	createTree(root);
	printDiagonal(root);
}