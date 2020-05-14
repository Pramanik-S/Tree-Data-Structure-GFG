/*Construct tree from ancestor matrix*/
#include "build.cpp"
node* Construct(vector<bool> mat[], int n) {
	vector<bool> ischild(n, false); //this boolean array check a node is a child node or not
	vector<node*> NODE(n, 0); //store address of all node
	for(int i = 0; i < n; i++) NODE[i] = new node(i); //contructing all node
	multimap<int, int> mm;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) sum += mat[i][j];
		mm.insert({sum, i});
	}
	for(auto p:mm) {
		if(p.first) {
			for(int i = 0; i < n; i++) {
				if(mat[p.second][i] and !ischild[i]) {
					if(!NODE[p.second]->left) NODE[p.second]->left = NODE[i];
					else if(!NODE[p.second]->right) NODE[p.second]->right = NODE[i];
					ischild[i] = true;
				}
			}
		}
	}
	return NODE[mm.rbegin()->second];
}
int main() {
	int n; cin >> n;
	vector<bool> mat[n];
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) {
		int x; cin >> x;
		mat[i].push_back(x);
	}
	node *root = Construct(mat, n);
	levelwise(root);
}