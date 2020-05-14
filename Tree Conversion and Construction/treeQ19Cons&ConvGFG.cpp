/*Linked complete binary tree & its creation*/
#include "build.cpp"
void Construct(node *root, int n) {
	if(n <= 0) return;
	int data; cin >> data;
	root->data = data;
	queue<node*> q;
	q.push(root);
	for(int i = 1; i < n;) {
		node *temp = q.front();
		if(!temp->left) {
			cin >> data;
			temp->left = new node(data);
			q.push(temp->left);
			i++;
		}
		else if(!temp->right) {
			cin >> data;
			temp->right = new node(data);
			q.push(temp->right);
			i++;
		}
		else q.pop();
	}
}
int main() {
	node *root = new node;
	int n; cin >> n;
	Construct(root, n);
	preorder(root); cout << endl;
	inorder(root); cout << endl;
}