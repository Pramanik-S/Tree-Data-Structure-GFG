/*Reverse tree path*/
#include "build.cpp"
bool helper(node *root, unordered_map<int, int> &temp, int level, int &pos, int x) {
	if(!root) return false;
	if(root->data == x) {
		temp[level] = root->data;
		root->data = temp[pos];
		pos++;
		return true;
	}
	temp[level] = root->data;
	bool left, right = helper(root->right, temp, level+1, pos, x);
	if(!right) left = helper(root->left, temp, level+1, pos, x);
	if(left || right) {
		root->data = temp[pos];
		pos++;
		return true;
	}
	return false;
}
void revTreepath(node *root, int x) {
	unordered_map<int, int> temp;
	int pos = 0;
	if(!helper(root, temp, 0, pos, x)) cout << "Error" << endl;
}
int main() {
	node *root = new node;
	createTree(root);
	levelwise(root);
	int x; cin >> x;
	revTreepath(root, x);
	levelwise(root);
}