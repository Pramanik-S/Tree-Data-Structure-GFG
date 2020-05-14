/*Construct a tree from Inorder and Level order traversals*/
#include "build.cpp"
node* construct(vector<int> level, int n, vector<int> in, int start, int end) {
	if(start > end) return NULL;
	node *temp = new node(level[0]);
	if(start == end) return temp;
	unordered_set<int> lt;
	int index;
	for(index = start; index <= end; index++) {
		if(in[index] == level[0]) break;
		lt.insert(in[index]);
	}
	vector<int> llevel, rlevel;
	for(int i = 1; i < n; i++) {
		if(lt.find(level[i]) != lt.end()) llevel.push_back(level[i]);
		else rlevel.push_back(level[i]);
	}
	temp->left = construct(llevel, llevel.size(), in, start, index-1);
	temp->right = construct(rlevel, rlevel.size(), in, index+1, end);
	return temp;
}
int main() {
	int n; cin >> n;
	vector<int> lev(n), in(n);
	for(int i = 0; i < n; i++) cin >> in[i];
	for(int i = 0; i < n; i++) cin >> lev[i];
	node *root = construct(lev, n, in, 0, n-1);
	inorder(root); cout << endl;
	levelwise(root);
}