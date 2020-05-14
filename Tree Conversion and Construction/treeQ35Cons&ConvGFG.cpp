/*Minimum swap required to convert binary tree to binary search tree*/
#include<bits/stdc++.h>
using namespace std;
void saveInorder(vector<int> &in, vector<int> arr, int index) {
	if(index >= arr.size()) return;
	saveInorder(in, arr, 2*index+1);
	in.push_back(arr[index]);
	saveInorder(in, arr, 2*index+2);
}
int minSwap(vector<int> &in) {
	vector<pair<int, int>> temp;
	for(int i = 0; i < in.size(); i++) temp.push_back({in[i], i});
	int ans = 0;
	for(int i = 0; i < in.size(); i++) {
		if(i != temp[i].second) {
			swap(temp[i], temp[temp[i].second]);
			ans++;
		}
	}
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> in, arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	saveInorder(in, arr, 0);
	for(auto i:in) cout << i << " ";
	cout << endl;
	cout << minSwap(in) << endl;
}