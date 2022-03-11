#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* CreateNode(int val)
{
  struct node* n=(struct node*)malloc(sizeof(struct node));
  n->data=val;
  n->left=NULL;
  n->right=NULL;
  n->height=1;
  return n;
}

int getheight(struct node* n)
{
  if(n==NULL)
  {
    return 0;
  }

  return n->height;
}

int getbalancefactor(struct node* n)
{
  if(n==NULL)
  {
    return 0;
  }
  return getheight(n->left)-getheight(n->right);
}

struct node* rightrotate(struct node* y)
{
 struct node* x=y->left;
 struct node* T2=x->right;

 x->left=y;
 y->left=T2;

 x->height=max(getheight(x->left),getheight(x->right))+1;
 y->height=max(getheight(y->left),getheight(y->right))+1;

 return x;

}

struct node* leftrotate(struct node* x)
{
       struct node* y=x->right;
       struct node* T2=y->left;

       y->left=x;
       x->right=T2;

       y->height=max(getheight(y->left),getheight(y->right))+1;
       x->height=max(getheight(y->right),getheight(x->left))+1;
       return y;

}

struct node* insert(struct node* n,int val)
{
  if(n==NULL)
  {
    return CreateNode(val);
  }

  if(n->data<val)
  {
    n->right=insert(n->right,val);
  }
  else
  {
    n->left=insert(n->left,val);
  }

  n->height=max(getheight(n->left),getheight(n->right))+1;

  int bf=getbalancefactor(n);
  //Left Left Case
  if(bf>1 && val < n->left->data)
  {
      return rightrotate(n);
  }
  //Right right Case
  if(bf>-1 && val > n->right->data)
  {
    return leftrotate(n);
  }
  //Left Right Case
  if(bf>1 && val > n->left->data)
  {
    n->left=leftrotate(n->left);
    return rightrotate(n);
  }
  //Right left Case
  if(bf<-1 && val < n->right->data)
  {
    n->right=rightrotate(n->right);
    return leftrotate(n);
  }

  return n;

}


int main()
{

    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    struct node* root=NULL;
    root=insert(root,5);
    insert(root,51);
    insert(root,98);
    insert(root,50);
    insert(root,25);
    insert(root,15);
    insert(root,50);

    cout<<"Abhishek Sahay";



  return 0;
}
