#include<bits/stdc++.h>
using namespace std;

struct stack2
{
	int data;
	struct stack2* next;
};

bool isEmpty(struct stack2* s)
{
	if(s==NULL)
		return true;
	return false;
}

bool isFull(struct stack2* s)
{
	struct stack2* p=(struct stack2*)malloc(sizeof(struct stack2));
	if(p==NULL)
		return true;
	else 
		return false;
}

void push(struct stack2** s,int val)
{
	if(isFull(*s))
	{
		cout<<"stack overflow";
		return;
	}

	struct stack2* new_node=(struct stack2*)malloc(sizeof(struct stack2));
	new_node->data=val;
	new_node->next=*s;
	*s=new_node;
    return;
}

void pop(struct stack2 **head)
{
      if(isEmpty(*head))
      {
      	cout<<"stack is empty";
      	return;
      }
      struct stack2* temp=NULL;
      temp=*head;
      *head=temp->next;
      free(temp);
      return;
}

int top(struct stack2* head)
{
	if(isEmpty(head))
	{
		cout<<"stack is empty";
		return -1;
	}

	return head->data;
}


int main()
{
	struct stack2* head=NULL;
	push(&head,3);
	push(&head,5);
	push(&head,1);
	push(&head,8);
	push(&head,5);
	push(&head,10);

        cout<<top(head);
	



}
