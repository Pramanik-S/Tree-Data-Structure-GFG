/*Construct Full Binary Tree from given preorder and postorder traversals*/
#include "build.cpp"
node* construct(vector<int> pre, unordered_map<int, int> mp, int &index, int start, int end) {
	if(index >= pre.size() || start > end) return NULL;
	node *temp = new node(pre[index++]);
	if(start == end) return temp;
	int i = mp[pre[index]];
	temp->left = construct(pre, mp, index, start, i);
	temp->right = construct(pre, mp, index, i+1, end-1);
	return temp;
}
/* 1 2 4 8 9 5 3 6 7
   8 9 4 5 2 6 7 3 1 */
int main() {
	int n; cin >> n;
	vector<int> pre(n), post(n);
	for(int i = 0; i < n; i++) cin >> pre[i];
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) {
		cin >> post[i];
		mp[post[i]] = i;
	}
	int index = 0;
	node *root = construct(pre, mp, index, 0, n-1);
	levelwise(root);
	preorder(root); cout << endl;
	postorder(root); cout << endl;
}