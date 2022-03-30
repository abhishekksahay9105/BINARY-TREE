#include <bits/stdc++.h>
using namespace std;

class trie
{
  private:
    char c;
    trie* address[26];
    int count;
  public:
    trie();
    trie(char);
    void insert(trie*, string);
    bool search(trie*, string);
};

trie::trie()
{
     char c=0;
     for(int i=0;i<26;i++)
     {
      address[i]=NULL;
     }
     count=0;
}

trie:: trie(char val)
{
  c=val;
  for(int i=0;i<26;i++)
  {
    address[i]=NULL;
  }
}

void trie:: insert(trie* root,string s)
{ 

     int n=s.size();
     for(int i=0;i<n;i++)
     {
      int index=s[i]-'a';
      if(root->address[index]==NULL)
      {
        root->address[index]=new trie(s[i]);
        root->c=s[i];
        root=root->address[index];
      }
      else
      {
        root=root->address[index];
      }
     }
     root->count+=1;
}

bool trie:: search(trie* root, string s)
{
  int n=s.size();

  for(int i=0;i<n;i++)
  {
       int index=s[i]-'a';
       if(root->address[index]==NULL)
       {
        return false;
       }
       else
       {
        root=root->address[index];
       }
  }
   
  return true;
  
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout);
  #endif

  int t;
  cin>>t;
  
  while(t--)
  {
     trie b,*root=NULL;
     root=new trie(0);

     int n;
     cin>>n;
     
     for(int i=0;i<n;i++)
     {
        string s;
        cin>>s;
        b.insert(root,s);
        
     }
     
     string s;
     cin>>s;
    
     
     if(b.search(root,s))
     {
      cout<<"YES";
     }
     else
     {
      cout<<"NO";
     }

  }

  return 0;
}
