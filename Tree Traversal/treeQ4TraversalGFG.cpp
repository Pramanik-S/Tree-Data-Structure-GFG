/*Print Postorder traversal from given Inorder and Preorder traversals*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
int search(T arr[], T key, int n) {
	for(int i = 0; i < n; i++) if(arr[i] == key) return i;
	return -1;
}
template<typename T>
void printPostorder(T in[], T pre[], int n) {
	int root = search(in, pre[0], n);
	if(root != 0) printPostorder(in, pre+1, root);
	if(root != n-1) printPostorder(in+root+1, pre+root+1, n-root-1);
	cout << pre[0] << " ";
}
int main() {
	int n; cin >> n;
	int in[n], pre[n];
	for(int i = 0; i < n; i++) cin >> in[i];
	for(int i = 0; i < n; i++) cin >> pre[i];
	printPostorder(in, pre, n);
	cout << endl;
}
