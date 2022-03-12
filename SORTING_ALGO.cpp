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
	for(int i=low;i<=j;j++)
	{
		if(a[i]<pivot)
		{
			swap(a[i],a[i1++]);
		}
	}

	swap(a[i1],a[high]);
	return i1;
}

void quick_sort(int *a ,int low,int high)
{
	while(low<high)
	{
      int pi;
      pi=partition(a,low,high);

      quick_sort(a,low,pi-1);
      quick_sort(a,pi+1,high);
	}
}


void merge_sort(int *a,int low,int high)
{

	if(low>=high)
		return;
	int mid;
	mid=high+(low-high)/2;


	merge_sort(a,low,mid-1);
	merge_sort(a,mid,high);

	int arr[high-low+1];
        int i=0,i1=low,j1=mid;

    while(i1<mid&&j1<=high)
    {
    	if(a[i1]<a[j1])
           {
           	arr[i]=a[i1];
           	i1++;
           }
        else
           {
            arr[i]=a[j1];
            j1++;
           }
           i++;
    }
   
    while(i1<mid)
    	{
    		arr[i]=a[i1];
    		i++;
    		i1++;
    	}
    
    while(j1<=high)
    {
    	arr[i]=a[j1];
    	i++;
    	j1++;
    }

    for(int i=low;i<=high;i++)
    {
        a[i]=arr[i-low];
    }
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
    merge_sort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
    	cout<<a[i];
    }

    return 0;
}
