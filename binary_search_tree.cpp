#include<bits/stdc++.h>
using namespace std;

class bst
{
private:
	int data;
	bst* left;
	bst*right;

public:
	bst();
	bst(int);
	bst* insert(bst*,int);
	bst* search(bst*,int);
	void inorder(bst* root);

};

bst:: bst()
{
      data=0;
      left=right=NULL;
}

bst:: bst(int val)
{
	data=val;
	left=right=NULL;
}

bst* bst:: insert(bst* root,int val)
{
	if(root==NULL)
	{
		return new bst(val);
	}
    
	if(root->data>val)
	{
		root->left=insert(root->left,val);
	}

	else if(root->data<val)
	{
		root->right=insert(root->right,val);
	}

	return root;
}

bst* bst::search(bst* root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}

	if(key==root->data)
	{
		return root;
	}
    
    if(key<root->data)
    {
    	return search(root->left,key);
    }
    
    if(key>root->data)
    {
    	return search(root->right,key);
    }

    return NULL;
}


void bst:: inorder(bst* root)
{
	if(root==NULL)
	{
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin);
   freopen("OUTPUT.txt","w",stdout);
   #endif

   int t;
   cin>>t;

  // while(t--)
   {
      bst b,*root=NULL;

      root=b.insert(root,10);
      for(int i=0;i<t;i++)
      {
       int c;
       cin>>c;
       b.insert(root,c);
      }
      b.inorder(root);
   }
   return 0;
}
