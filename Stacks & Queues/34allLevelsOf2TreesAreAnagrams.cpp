#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *right, *left;
	Node(int value){
		data = value;
		right = left = NULL;
	}
}nd;

bool isAnagram(nd *root1, nd *root2){
	// base condition
	if(root1==NULL and root2==NULL) return true;
	if(root1==NULL or root2==NULL) return false;

	queue<nd*> q1,q2;
	q1.push(root1);
	q2.push(root2);

	// while either one is empty loop breaks
	while(!q1.empty() and !q2.empty()){
		int n1 = q1.size(), n2 = q2.size();

		// if number of nodes are different return false
		if(n1!=n2) return false;

		// store elements of tree 1 and 2
		vector<int> curLvl1, curLvl2;

		while(n1--){
			nd *temp = q1.front();
			q1.pop();
			if(temp->left) q1.push(temp->left);
			if(temp->right) q1.push(temp->right);
			curLvl1.push_back(temp->data);

			temp = q2.front();
			q2.pop();
			if(temp->left) q2.push(temp->left);
			if(temp->right) q2.push(temp->right);
			curLvl2.push_back(temp->data);
		}

		// check anagram or not
		sort(curLvl1.begin(), curLvl1.end());
		sort(curLvl2.begin(), curLvl2.end());
		if(curLvl1!=curLvl2) return false;
	}
	// if both queue empty now then return true else false
	return (q1.empty() and q2.empty())?true:false;
}

int main()
{
    // Constructing both the trees.
    nd* root1 = new nd(1);
    root1->left = new nd(3);
    root1->right = new nd(2);
    root1->right->left = new nd(5);
    root1->right->right = new nd(4);

    nd* root2 = new nd(1);
    root2->left = new nd(2);
    root2->right = new nd(3);
    root2->left->left = new nd(4);
    root2->left->right = new nd(5);

    isAnagram(root1,root2)?cout<<"Yes":cout<<"No";
    return 0;
}
