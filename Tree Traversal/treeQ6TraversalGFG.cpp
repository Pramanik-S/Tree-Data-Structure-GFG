/*Find all possible binary trees with given Inorder Traversal*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct node
{
	T data;
	node<T> *left, *right;
	node(T data = 0) {
		this->data = data;
		this->left = this->right = 0;
	}
};
template<typename T>
vector<node<T>*> allpreorder(vector<T> &in, int start, int end) {
	vector<node<T>*> tree;
	if(start > end) {
		tree.push_back(NULL);
		return tree;
	}
	for(int i = start; i <= end; i++) {
		vector<node<T>*> ltree = allpreorder(in, start, i-1);
		vector<node<T>*> rtree = allpreorder(in, i+1, end);
		for(int j = 0; j < ltree.size(); j++) {
			for(int k = 0; k < rtree.size(); k++) {
				node<T> *root = new node<T>(in[i]);
				root->left = ltree[j];
				root->right = rtree[k];
				tree.push_back(root);
			}
		}
	}
	return tree;
}
template<typename T>
void preorder(node<T> *root) {
	if(!root) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int n; cin >> n;
	vector<char> in(n);
	for(int i = 0; i < n; i++) cin >> in[i];
	vector<node<char>*> tree = allpreorder(in, 0, n-1);
	
	for(int i = 0; i < tree.size(); i++) {
		preorder(tree[i]);
		cout << endl;
	}
	return 0;
}
