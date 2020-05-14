/*Reverse alternate levels of a perfect binary tree*/
#include "build.cpp"
void reverseAlternateLevel(node *root) {
	if(!root) return;
	vector<node*> v;
	v.push_back(root);
	bool rev = false;
	while(v.size()) {
		if(rev) {
			int size = v.size();
			vector<node*> temp;stack<int> s;
			for(int i = 0; i < size; i++) {
				s.push(v[i]->data);
				if(v[i]->left) temp.push_back(v[i]->left);
				if(v[i]->right) temp.push_back(v[i]->right);
			}
			for(int i = 0; i < size; i++) {
				v[i]->data = s.top();
				s.pop();
			}
			v.clear();
			v = temp;
			rev = false;
		}
		else {
			vector<node*> temp;
			for(int i = 0; i < v.size(); i++) {
				if(v[i]->left) temp.push_back(v[i]->left);
				if(v[i]->right) temp.push_back(v[i]->right);
			}
			v.clear();
			v = temp;
			rev = true;
		}
	}
}
int main() {
	node *root = new node;
	createTree(root);
	levelwise(root); cout << endl;
	reverseAlternateLevel(root);
	levelwise(root); cout << endl;
}