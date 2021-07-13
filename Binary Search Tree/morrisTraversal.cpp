#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};

struct node *insert(node *root, int value){
	if(root==NULL) return new node(value);
	else{
		if(root->data<value) root->right = insert(root->right,value);
		else root->left = insert(root->left,value);
	}
	return root;
}

// InOrder

void inorder(node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void morrisInorder(node *root){
	node *pre, *current;
	current = root;
	while(current!=NULL){
		// if current's left is NULL means
        // it is the leftmost node thus print it
        // and go to its right child
        if(current->left==NULL){
			cout<<current->data<<" ";
			current = current->right;
		}
		else{
            // pre will store the inorder predecessor
            // of the current node
            // starting from the left child of the current
			pre = current->left;
            // keep traversing to the right child of each node
            // until its right is NULL
            // we also check if the last right's right child
            // isn't the current(this will occur when a thread
            // has been established between the predecessor
            // and the current node)
			while(pre->right!=NULL and pre->right!=current)
				pre = pre->right;
            // if the predecessor's right is NULL means this hasn't
            // been connected to its succesor(i.e. current node)
            // thus we join them and go to the current's left child
			if(pre->right==NULL){
				pre->right = current;
				current = current->left;
			}
			// this instance is reached when the child's
			// right isn't NULL meaning this has been already
			// visited once before and printed too,
			// and now is visited for the second time
			// thus we cut the thread joining it to its succesor
			// printing the succesor and going to the right child
			// of the successor
			else{
                pre->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
			}
		}
	}
}

// PreOrder

void preorder(node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void morrisPreorder(node*root){
	node *pre, *current;
	current = root;
    // same as inorder just we print the nodes
    // while going down instead of while going
    // up
	while(current){
		if(!current->left){
			cout<<current->data<<" ";
			current = current->right;
		}
		else{
			pre = current->left;
            while(pre->right and pre->right!=current)
                pre = pre->right;
            if(!pre->right){
                cout<<current->data<<" ";
                pre->right = current;
                current = current->left;
			}
			else{
				pre->right = NULL;
				current = current->right;
			}
		}
	}
}

void postorder(node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void morrisPostorder(node *root){
	node *pre, *current;
	current = root;
	while(current){
		if(!current->left){
			cout<<current->data<<" ";
			current = current->right;
		}
		else{
			pre = current->left;
            while(pre->right and pre->right!=current)
                pre = pre->right;
            if(!pre->right){
                pre->right = current;
                current = current->left;
			}
			else{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
}


int main(){
	node *root = NULL;
	root = insert(root,10);
	int arr[] = {5,30,-2,6,40,2,8,-1};
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		insert(root,arr[i]);

	cout<<"INORDER:"<<endl<<"Recursive Inorder:"<<endl;
	inorder(root);
	cout<<endl<<"Morris Inorder:"<<endl;;
	morrisInorder(root);
	cout<<endl<<endl;
	
	cout<<"PREORDER:"<<endl<<"Recursive Preorder:"<<endl;
	preorder(root);
	cout<<endl<<"Morris Preorder:"<<endl;
	morrisPreorder(root);
	cout<<endl<<endl;

	cout<<"POSTORDER:"<<endl<<"Recursive Postorder:"<<endl;
    postorder(root);
    cout<<endl;
	//morrisPostorder(root);
    return 0;
}
