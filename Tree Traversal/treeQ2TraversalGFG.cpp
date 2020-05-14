/*Inorder Tree Traversal without Recursion*/
#include<bits/stdc++.h>
#include "buildTree.cpp"
using namespace std;
int main() {
	node<int> root;
	createTree(&root);
	levelwise(&root);
	inorderRec(&root); cout << endl;
	inorderWithoutRec(&root);
}
template<typename T>
void inorderWithoutRec(node<T> *root) {
	node<T> *curr = root;
	stack<node<T>*> S;
	while(true) {
		if(!curr && S.empty()) break;
		if(curr) while(curr) {
			S.push(curr);
			curr = curr->left;
		}
		else {
			cout << S.top()->data << " ";
			curr = S.top()->right;
			S.pop();
		}
	}
	cout << endl;
}
