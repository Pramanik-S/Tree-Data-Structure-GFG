/*Construct Tree from given Inorder and Preorder traversals*/
#include "build.cpp"
node* construct(int in[], int pre[], int start, int end, int &pos) {
	if(start > end) return NULL;
	node *temp = new node(pre[pos++]);
	if(start == end) return temp;
	//Searching index of element from inorder
	int i;
	for(i = start; i <= end; i++) if(pre[pos-1] == in[i]) break;
	temp->left = construct(in, pre, start, i-1, pos);
	temp->right = construct(in, pre, i+1, end, pos);
	return temp;

}
node* constructEff(int pre[], int start, int end, int &pos, unordered_map<int, int> &hash) {
	if(start > end) return NULL;
	node *temp = new node(pre[pos++]);
	if(start == end) return temp;
	temp->left = constructEff(pre, start, hash[temp->data]-1, pos, hash);
	temp->right = constructEff(pre, hash[temp->data]+1, end, pos, hash);
	return temp;
}
int main() {
	int n; cin >> n;
	int in[n], pre[n];
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++) {
		cin >> in[i];
		hash[in[i]] = i;
	}
	for(int i = 0; i < n; i++) cin >> pre[i];
	int pos = 0, pos1 = 0;
	node *root = construct(in, pre, 0, n-1, pos);
	node *root1 = constructEff(pre, 0, n-1, pos1, hash);
	inorder(root); cout << endl;
	levelwise(root);
	inorder(root1); cout << endl;
	levelwise(root1);
}