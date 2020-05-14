/*Find postorder traversal of BST from preorder traversal*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void BSTpreTopost(vector<T> &pre, int low, int high) {
	if(low > high) return;
	int left  = low+1;
	while(left <= high && pre[left] < pre[0]) left++;
	BSTpreTopost(pre, low+1, left-1);
	BSTpreTopost(pre, left, high);
	cout << pre[low] << " ";

}
int main() {
	int n; cin >> n;
	vector<int> pre(n);
	for(int i = 0; i < n; i++) cin >> pre[i];
	BSTpreTopost(pre, 0, n-1);
}
