/*Construct Special Binary Tree from given Inorder traversal*/
#include "build.cpp"
node* Construct(vector<int> in, int start, int end) {
	if(start > end) return NULL;
	int mAX = INT_MIN;
	int index;
	for(int i = start; i <= end; i++) {
		if(in[i] > mAX) {
			mAX = in[i];
			index = i;
		}
	}
	node *temp = new node(mAX);
	if(start == end) return temp;
	temp->left = Construct(in, start, index-1);
	temp->right = Construct(in, index+1, end);
	return temp;
}
int main() {
	int n; cin >> n;
	vector<int> in(n);
	for(int i = 0; i < n; i++) cin >> in[i];
	node *root = Construct(in, 0, n-1);
	inorder(root); cout << endl;
	levelwise(root);
}