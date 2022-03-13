#include<bits/stdc++.h>
using namespace std;

struct stack1
{
     int size;
     int top;
     int *arr;
};

bool isEmpty(struct stack1 *s)
{
	if(s->top==-1)
		return true;
	return false;
}

bool isFull(struct stack1 *s)
{
    if(s->top+1==s->size)
    	return true;
    return false;
}

int top(struct stack1 *s)
{
	if(s->top==-1)
	{
		cout<<"stack is empty";
		return 0;
	}

	return s->arr[s->top];
}

void push(struct stack1 *s,int val)
{
	if(isFull(s))
	{
		cout<<"overflow";
		return;
	}

	s->top++;
	s->arr[s->top]=val;
}


void pop(struct stack1 *s)
{
	if(isEmpty(s))
	{
		cout<<"stack is Empty!";
		return;
	}
    
    s->top=s->top-1;	
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    struct stack1 *s=(struct stack1*)malloc(sizeof(struct stack1));
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc((s->size)*sizeof(int));

    cout<<s->size<<endl;
    
    push(s,8);
    push(s,10);
    cout<<top(s)<<endl;
    pop(s);
    cout<<top(s)<<endl;
    pop(s);
    cout<<top(s);
    

    return 0;
}
