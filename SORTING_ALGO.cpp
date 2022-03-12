#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int *a,int n)
{      
       for(int j=n-1;j>0;j--)
	   {
       for(int i=0;i<j;i++)
       {
       	if(a[i]>a[i+1])
       		swap(a[i],a[i+1]);
       }
       }

       for(int i=0;i<n;i++)
       {
       	cout<<a[i];
       }

       cout<<endl;
       return ;
}

void insertion_sort(int *a,int n)
{
      if(n==1)
      {
      	return;
      }
 
      for(int i=1;i<n;i++)
      {
      	int key;
      	key=a[i];

        for(int j=i-1;j>=0;j--)
        {
        	if(a[j]>a[j+1])
        		swap(a[j],a[j+1]);
        	else 
        		break;
        }
      }

      return;
}

void selection_sort(int *a,int n)
{
	if(n==1)
	{
		return;
	}

	for(int i=0;i<n-1;i++)
	{
		int k=i;
         
        for(int j=i+1;j<n;j++)
        {
              if(a[j]<a[k])
              {
              	k=j;
              }
        }

        swap(a[i],a[k]);
	}
}

int partition(int *a,int low,int high)
{
	int pivot=a[high];

	int j=high-1,i1=low;
	for(int i=low;i<=j;i++)
	{
		if(a[i]<pivot)
		{
			swap(a[i],a[i1]);
			i1++;
		}
		else
		{
		       	swap(a[i],a[j--]);
			
		}
	}

	swap(a[i1],a[high]);
	return i1;
}

void quick_sort(int *a ,int low,int high)
{
	if(low<high)
	{
      int pi;
      pi=partition(a,low,high);
      
      quick_sort(a,low,pi-1);
      quick_sort(a,pi+1,high);
	}
	return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    
    //selection_sort(a,n);
    quick_sort(a,0,n-1);
    // cout<<partition(a,1,n-1)<<endl;

    for(int i=0;i<n;i++)
    {
    	cout<<a[i];
    }

    return 0;
}
