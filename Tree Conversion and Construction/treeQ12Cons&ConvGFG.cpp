/*Construct a Binary Tree from Postorder and Inorder*/
#include "build.cpp"
node* Construct(unordered_map<int, int> in, int start, int end, vector<int> post, int &pos) {
	if(start > end) return NULL;
	node *temp = new node(post[pos--]);
	if(start == end) return temp;
	int index = pos+1;
	temp->right = Construct(in, in[post[index]]+1, end, post, pos);
	temp->left = Construct(in, start, in[post[index]]-1, post, pos);
	return temp;
}
int main() {
	int n; cin >> n;
	unordered_map<int, int> in;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		in[x] = i;
	}
	vector<int> post(n);
	for(int i = 0; i < n; i++) cin >> post[i];
	int pos = n-1;
	node *root = Construct(in, 0, n-1, post, pos);
	levelwise(root);
	inorder(root); cout << endl;
	postorder(root); cout << endl;
}