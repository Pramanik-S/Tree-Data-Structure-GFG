/*Convert a tree to forest of even nodes*/
#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int> tree[], vector<bool> &visited, int &ans, int curr) {
	visited[curr] = true;
	int nOn = 0; // number of node of curr subtree
	for(int i = 0; i < tree[curr].size(); i++) {
		if(!visited[tree[curr][i]]) {
			int temp = dfs(tree, visited, ans, tree[curr][i]);
			if(temp%2) nOn += temp;
			else ans++;
		}
	}
	return nOn+1;
}
int main() {
	int n; cin >> n;
	vector<int> tree[n+1];
	for(int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int ans = 0;
	vector<bool> visited(n+1, false);
	dfs(tree, visited, ans, 1);
	cout << ans << endl;
}