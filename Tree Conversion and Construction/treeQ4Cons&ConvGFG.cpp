/*Construct a complete binary tree from given array in level order fashion*/
#include "build.cpp"
void construct(node *root, vector<int> lev) {
	int index = 0;
	root->data = lev[index++];
	queue<node*> q;
	q.push(root);
	while(index < lev.size()) {
		q.front()->left = new node(lev[index++]);
		q.push(q.front()->left);
		if(index < lev.size()) {
			q.front()->right = new node(lev[index++]);
			q.push(q.front()->right);
		}
		q.pop();
	}
}
//Method 2
node* cons2(int index, vector<int> lev) {
	if(index >= lev.size()) return NULL;
	node *temp = new node(lev[index]);
	temp->left = cons2(2*index+1, lev);
	temp->right = cons2(2*index+2, lev);
	return temp;
}
int main() {
	int n; cin >> n;
	vector<int> lev(n);
	for(int i = 0; i < n; i++) cin >> lev[i];
	//node *root = new node;
	//construct(root, lev);
	node *root = cons2(0, lev);
	levelwise(root);
}