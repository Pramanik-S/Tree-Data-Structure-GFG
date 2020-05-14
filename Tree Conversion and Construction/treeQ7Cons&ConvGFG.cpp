/*Construct a special tree from given preorder traversal*/
#include "build.cpp"
node* Construct(vector<int> pre, unordered_map<int, char> mp, int &index) {
	if(index >= pre.size()) return NULL;
	node *temp = new node(pre[index++]);
	if(mp[temp->data] == 'L') return temp;
	temp->left = Construct(pre, mp, index);
	temp->right = Construct(pre, mp, index);
	return temp;
}
int main() {
	int n; cin >> n;
	vector<int> pre(n);
	for(int i = 0; i < n; i++) cin >> pre[i];
	unordered_map<int, char> mp;
	for(int i = 0; i < n; i++) {
		char ch; cin >> ch;
		mp[pre[i]] = ch;
	}
	int index = 0;
	node *root = Construct(pre, mp, index);
	levelwise(root);
	preorder(root); cout << endl;
}