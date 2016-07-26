#include "MyHeader.h"
struct tree
{
	int data;
	tree *left,*right;
};
class BTree
{
	static int n;
	static int m;
public:
	tree *root;
	BTree(){
		root=NULL;
	}
	void createBtree(int);
	void preOrder(tree *);
	void inOrder(tree *);
	void poOrder(tree *);
	void displayPre(){preOrder(root);cout<<endl;}
	void displayIn(){inOrder(root);cout<<endl;}
	void displayPo(){poOrder(root);cout<<endl;}
	int count(tree *);
	int findLeaf(tree *);
	int findNode(tree *);
};
int BTree::n=0;
int BTree::m=0;
void BTree::createBtree(int x){
	tree *newNode=new tree;
	newNode->data=x;
	newNode->right=newNode->left=NULL;
	if(root==NULL){
		root=newNode;
	}else{
		tree *back;
		tree *current=root;
		while(current!=NULL){
			back=current;
			if(current->data>x){
				current=current->left;
			}else{
				current=current->right;
			}
		}
		if(back->data>x){
			back->left=newNode;
		}else{
			back->right=newNode;
		}
	}
}
int BTree::count(tree *p){
	if(p==NULL){
		return 0;
	}else{
		return count(p->left)+count(p->right)+1;
	}
}
void BTree::preOrder(tree *temp){
	if(temp!=NULL){
		cout<<temp->data<<" ";
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
void BTree::inOrder(tree *temp){
	if(temp!=NULL){
		inOrder(temp->left);
		cout<<temp->data<<" ";
		inOrder(temp->right);
	}
}
void BTree::poOrder(tree *temp){
	if(temp!=NULL){
		poOrder(temp->left);
		poOrder(temp->right);
		cout<<temp->data<<" ";
	}
}
int BTree::findLeaf(tree *temp){
	if(temp==NULL){
		return 0;
	}else{
		if(temp->left==NULL&&temp->right==NULL){
			return n+=1;
		}else{
			findLeaf(temp->left);
			findLeaf(temp->right);
		}
		return n;
	}
}
int BTree::findNode(tree *temp){
	if(temp==NULL)return 0;
	else{
		if(temp->left!=NULL&&temp->right!=NULL){
			findNode(temp->left);
			findNode(temp->right);
		}
		if(temp->left!=NULL&&temp->right==NULL){
			m+=1;
			findNode(temp->left);
		}
		if(temp->left==NULL&&temp->right!=NULL){
			m+=1;
			findNode(temp->right);
		}
	}
	return m;
}
int main()
{
	BTree A;
	int array[]={7,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
	int k;
	k=sizeof(array)/sizeof(array[0]);
	cout<<"建立排序二叉树顺序："<<endl;
	for (int i = 0; i < k; ++i)
	{
		cout<<array[i]<<"	";
		A.createBtree(array[i]);
		A.displayPre();
		cout<<endl;
		/* code */
	}
	cout<<endl;
	cout<<"二叉树节点个数： "<<A.count(A.root)<<endl;
	cout<<"二叉树叶子个数："<<A.findLeaf(A.root)<<endl;
	cout<<"二叉树中度数为1的结点的数量为："<<A.findNode(A.root)<<endl;
	cout<<endl<<"先序遍历序列: "<<endl;
	A.displayPre();
	cout<<endl<<"中序遍历序列: "<<endl;
	A.displayIn();
	cout<<endl<<"后序遍历序列: "<<endl;
	A.displayPo();
	return 0;
}