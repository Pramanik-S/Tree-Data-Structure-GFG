/*Calculate depth of a full Binary tree from Preorder*/
#include<bits/stdc++.h>
using namespace std;
int depth(string pre, int &index) {
	if(index >= pre.length() || pre[index] == 'l') return 0;
	index++;
	int left = depth(pre, index);
	index++;
	int right = depth(pre, index);
	return max(left, right)+1;
}
int main() {
	string pre; cin >> pre;
	int index = 0;
	cout << depth(pre, index) << endl;
}