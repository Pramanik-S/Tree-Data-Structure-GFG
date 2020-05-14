/*Number of Binary Trees for given Preorder Sequence length*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll countTree(int n) {
	ll DP[n+1];
	memset(DP, 0, sizeof(DP));
	DP[0] = DP[1] = 1;
	for(int i = 2; i <= n; i++) for(int j = 0; j < i; j++) DP[i] += DP[j]*DP[i-j-1];
	return DP[n];
}
int main() {
	int n; cin >> n;
	cout << countTree(n) << endl;
}