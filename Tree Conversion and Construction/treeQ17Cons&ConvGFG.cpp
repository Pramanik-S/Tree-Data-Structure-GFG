/*Construct the full k-ary tree from its preorder traversal*/
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	vector<node*> child;
	node(int data = 0) {
		this->data = data;
	}
};
void preorder(node *root) {
	if(!root) return;
	cout << root->data << " ";
	for(int i = 0; i < root->child.size(); i++) {
		preorder(root->child[i]);
	}
}
void postorder(node *root) {
	if(!root) return;
	for(int i = 0; i < root->child.size(); i++) {
		postorder(root->child[i]);
	}
	cout << root->data << " ";
}
int height(int n, int k) {
	return ceil(log((double)n*(k-1)+1)/log((double)k));
}
node* construct(vector<int> pre, int n, int k, int h, int &index) {
	node *temp = new node(pre[index]);
	for(int i = 0; i < k; i++) {
		if(index < n-1 && h > 1) {
			index++;
			temp->child.push_back(construct(pre, n, k, h-1, index));
		} else temp->child.push_back(NULL);
	}
	return temp;
}
int main() {
	int n, k; cin >> n >> k;
	vector<int> pre(n);
	for(int i = 0; i < n; i++) cin >> pre[i];
	int index = 0;
	//cout << height(n, k) << endl;
	node *root = construct(pre, n, k, height(n, k), index);
	preorder(root); cout << endl;
	postorder(root); cout << endl;
}