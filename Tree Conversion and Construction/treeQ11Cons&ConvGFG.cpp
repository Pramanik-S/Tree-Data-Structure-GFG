/*Construct Binary Tree from given Parent Array representation*/
#include "build.cpp"
node* Construct(vector<int> arr, int n) {
	vector<node*> NODE(n);
	for(int i = 0; i < n; i++) NODE[i] = new node(i);
	node *root;
	for(int i = 0; i < n; i++) {
		if(arr[i] != -1) {
			if(!NODE[arr[i]]->left) NODE[arr[i]]->left = NODE[i];
			else NODE[arr[i]]->right = NODE[i];
		}
		else root = NODE[i];
	}
	return root;
}
int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	node *root = Construct(arr, n);
	levelwise(root);
	inorder(root); cout << endl;
}