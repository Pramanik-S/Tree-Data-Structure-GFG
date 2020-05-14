/*Construct Ancestor Matrix from a Given Binary Tree*/
#include "build.cpp"
#define SizE 10
void buildMatrix(vector<vector<int>> &mat, node *root) {
	if(!root) return;
	buildMatrix(mat, root->left);
	buildMatrix(mat, root->right);
	if(root->left) {
		for(int i = 0; i < SizE; i++) if(mat[root->left->data][i]) mat[root->data][i] = mat[root->left->data][i];
		mat[root->data][root->left->data] = 1;
	}
	if(root->right) {
		for(int i = 0; i < SizE; i++) if(mat[root->right->data][i]) mat[root->data][i] = mat[root->right->data][i];
		mat[root->data][root->right->data] = 1;
	}
}
int main() {
	node *root = new node;
	createTree(root);
	vector<vector<int>> mat;
	for(int i = 0; i < SizE; i++) {
		vector<int> temp;
		for(int j = 0; j < SizE; j++)
			temp.push_back(0);
		mat.push_back(temp);
	}
	buildMatrix(mat, root);
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
}