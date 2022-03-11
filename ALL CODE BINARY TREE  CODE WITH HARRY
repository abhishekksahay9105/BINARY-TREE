#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
      data=val;
      left=NULL;
      right=NULL;
    }

};

struct node* CreateNode(int data)
{
  struct node* n=new node(data);
 
  return n;
}

void inorder(struct node* root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(struct node* root)
{
  if(root==NULL)
  {
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node* root)
{
 if(root==NULL)
 {
  return;
 } 

 postorder(root->left);
 postorder(root->right);
 cout<<root->data<<" "; 
}

bool isBST(struct node* root)
{
      static struct node* prev=NULL;

      if(root==NULL)
        return true;
      
      if(!isBST(root->left))
        return false;
      if(prev!=NULL&&(prev->data)>(root->data))
      {
            return false;
      }
      prev=root;
      if(!isBST(root->right))
        return false;

      return true;
}

struct node* search(struct node* root,int val)
{
  if(root==NULL)
    return NULL;

  if(root->data==val)
  {
    return root;
  }

  if(root->data>val)
    search(root->left,val);
  else
    search(root->right,val);

}

struct node* searchit(struct node* root,int val)
{
  while(root!=NULL)
  {
    if(root->data==val)
    {
      return root;
    }
    else if(root->data>val)
    {
      root=root->left;
    }
    else
    {
      root=root->right;
    }
  }

  return NULL;
}

void insert(struct node* root, int val)
{
  struct node* prev=root;
  while(root!=NULL)
  { 
    prev=root;
    if(root->data>val)
    {
      root=root->left;
    }
    else if(root->data<val)
    {
      root=root->right;
    }
  }

  struct node* new_node=new node(val);
  if(prev->data>val)
  {
    prev->left=new_node;
  }
  else
  {
    prev->right=new_node;
  }
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

  struct node* n=new node(5);
  struct node* nl=new node(3);
  struct node* nr=new node(6);
  struct node* nll=new node(1);
  struct node* nlr=new node(4);

  n->left=nl;
  n->right=nr;
  nl->left=nll;
  nl->right=nlr;

 insert(n,10);
 insert(n,9);
 insert(n,11);

 inorder(n);

  return 0;
}
