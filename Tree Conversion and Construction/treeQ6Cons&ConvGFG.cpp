/*Construct Full Binary Tree using its Preorder traversal and Preorder traversal of its mirror tree*/
#include "build.cpp"
node* Construct(vector<int> pre, unordered_map<int, int> mp, int &index, int start, int end) {
	if(index >= pre.size() || start > end) return NULL;
	node *temp = new node(pre[index++]);
	if(start == end) return temp;
	int i = mp[pre[index]];
	temp->left = Construct(pre, mp, index, i, end);
	temp->right = Construct(pre, mp, index, start+1, i-1);
	return temp;
}
int main() {
	int n; cin >> n;
	vector<int> pre(n);
	for(int i = 0; i < n; i++) cin >> pre[i];
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x] = i;
	}
	int index = 0;
	node *root = Construct(pre, mp, index, 0, n-1);
	levelwise(root);
	preorder(root); cout << endl;
}