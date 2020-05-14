/*Inorder Tree Traversal without recursion and without stack!*/
#include<bits/stdc++.h>
#include "buildTree.cpp"
using namespace std;
int main() {
	node<int> root;
	createTree(&root);
	cout << "Levelwise: ";
	levelwise(&root);
	cout << "Inorder Recurssion: ";
	inorderRec(&root);
	cout << endl << "Inorder Moris: ";
	morisTraversal(&root);
	cout << endl;
}
template<typename T>
void morisTraversal(node<T> *root) {
	if(!root) return;
	node<T> *curr = root;
	while(curr) {
		if(!curr->left) {
			cout << curr->data << " ";
			curr = curr->right;
		}
		else {
			//Finding inorder predecesor of curr and make curr as right child of inorder predecessor
			node<T> *pre = curr->left;
			while(pre->right && pre->right != curr) pre = pre->right;
			if(!pre->right) { //If predecesor's right is null connect it to curr
				pre->right = curr;
				curr = curr->left;
			}
			else { //Else print curr and disconnect curr from its predecessor then move curr right
				pre->right = NULL;
				cout << curr->data << " ";
				curr = curr->right;
			} 
		}
	}
}
