#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node {
	T data;
	node<T> *left, *right;
public:
	node(T data = 0) {
		this->data = data;
		left = right = NULL;
	}
	T getData() {return this->data;}
	template<typename U>
	friend void createTree(node<U>*);
	template<typename U>
	friend void levelwise(node<U>*);
	template<typename U>
	friend void inorderRec(node<U>*);
	template<typename U>
	friend void inorderWithoutRec(node<U>*);
	template<typename U>
	friend void delnode(node<U>*, U);
	template<typename U>
	friend void morisTraversal(node<U>*);
	template<typename U>
	friend node<U>* lca(node<U>*, U, U);
	template<typename U>
	friend void levelLinewise(node<U>*);
	template<typename U>
	friend void replacewith(node<U>*);
	template<typename U>
	friend void inorderNode(vector<node<U>*>&, node<U>*);
	template<typename U>
	friend void inorderNodeSum(vector<U>&, node<U>*, int&);
	template<typename U>
	friend void replacewith(node<T>*);
};
template<typename T>
void createTree(node<T> *root) {
	T data; cin >> data;
	if(data == -1) return;
	root->data = data;
	queue<node<T>*> S;
	S.push(root);
	while(!S.empty()) {
		T left, right;
		node<T> *p = S.front();
		S.pop();
		cin >> left >> right;
		if(left != -1) {
			p->left = new node<T>(left);
			S.push(p->left);
		}
		if(right != -1) {
			p->right = new node<T>(right);
			S.push(p->right);
		}
	}
}
template<typename T>
void  levelwise(node<T> *root) {
	queue<node<T>*> q;
	q.push(root);
	while(!q.empty()) {
		cout << q.front()->data << " ";
		if(q.front()->left) q.push(q.front()->left);
		if(q.front()->right) q.push(q.front()->right);
		q.pop();
	}
	cout << endl;
}
template<typename T>
void inorderRec(node<T> *root) {
	if(!root) return;
	inorderRec(root->left);
	cout << root->data << " ";
	inorderRec(root->right);
}