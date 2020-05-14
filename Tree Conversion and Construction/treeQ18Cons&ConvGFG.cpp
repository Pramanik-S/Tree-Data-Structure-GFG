/*Construct Binary Tree from String with bracket representation*/
#include "build.cpp"
node* Construct(string str, int start, int end) {
	if(start > end) return NULL;
	node *temp = new node(str[start]-48);
	if(start == end) return temp;
	stack<char> s; s.push(str[start+1]);
	int index = start+2;
	while(!s.empty()) {
		if(str[index] == ')') s.pop();
		else if(str[index] == ')') s.push('(');
		index++;
	}
	temp->left = Construct(str, start+2, index-2);
	temp->right = Construct(str, index+1, end-1);
	return temp;
}
int main() {
	string str; cin >> str;
	node *root = Construct(str, 0, str.length()-1);
	preorder(root); cout << endl;
}