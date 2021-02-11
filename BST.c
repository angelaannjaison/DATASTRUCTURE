#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};

struct node *root=NULL;//globally declared root pointer

struct node* createnode(int);
struct node* insert(struct node*,int);
struct node* delete(struct node*,int);//function returns address of node where the root pointer points to
struct node* search(struct node*,int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
struct node* minvalue(struct node*);


void main()
{
	int data,ch;
	struct node *node;
	printf("\n BINARY SEARCH TREE IMPLEMENTATION \n");
	printf("\n1.CREATE NEWNODE\n2.INSERTION \n3.DELETION \n4.SEARCH \n5.PREORDER TRAVERSAL \n6.INORDER TRAVERSAL \n7.POSTORDER TRAVERSAL \n8.EXIT \n");
	do
	{
		printf("\n enter a choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter the data to be inserted: ");
				scanf("%d",&data);
				root=createnode(data);
				break;
			case 2:
				printf("\n Enter the data to be inserted: ");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 3:
				printf("\n enter the data to be deleted: ");
				scanf("%d",&data);
				root=delete(root,data);
				break;
			case 4:
				printf("\n enter the data to be searched: ");
				scanf("%d",&data);
				node=search(root,data);
				break;	
				
			case 5:
				printf("\n preorder root \n");
				preorder(root);
				break;
			case 6:
				printf("\n inorder traversal \n");
				inorder(root);	
				break;
			case 7:
				printf("\n postorder traversal \n");
				postorder(root);
				break;
			case 8:
				printf("\n************************exit****************************\n");
				break;	
			default:
				printf("\n invalid choice \n");
				break;		  
		}
	}while(ch!=8);
}



struct node* createnode(int data)
{
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;//address of newnode is passed to newnode() function
}

struct node* insert(struct node *root,int data) //locally declared root variable inside insert fuction
{
  if(root == NULL)//empty tree
  {
  	root=createnode(data);//recurrsive function
  	return root;
  }
  
  else if(data>(root->data))
  {
  	root->right = insert(root->right,data);
  
  }
  
  else if(data<(root->data))
  {
  	root->left = insert(root->left,data);//resurrsive fn: address of left node after execution of insert() will be passed and assigned to root->left & thus a link is created btw prev node and new node
  }
  
  	return root;			//local root prt containing address of newly created node is retured to global root ptr
}

struct node* minvalue(struct node *root)
{
	if(root!=NULL)
	return minvalue(root->left);
	return root; 
}

struct node* delete(struct node *root,int data)
{
	

	if(root==NULL)
	 return NULL;//return node is also correct since node=NULL
	 
	if(data>root->data)
	 root->right=delete(root->right,data);//calls delete function again
	 
	else if(data<root->data)
	 root->left=delete(root->left,data);
	 
	else 
	{
	//if no child
	if(root->right==NULL && root->left==NULL)
	{
		free(root);
		return NULL;
	}
	//one child
	else if(root->left==NULL || root->right==NULL)
	{
		struct node *temp=root;//data to be de
		if(root->left==NULL)
		{
		    root=root->right;
		   free(temp);
		   return root; 
		}
		   
		else
		{
		   root=root->right;
		   free(temp);
		   return root; 
		}
		  
		   
	}
	
	//two child
	else
	{
		struct node *temp=minvalue(root->right);//inorder successor:finding the min value in rt subtree + temp=address in minval
		root->data=temp->data;//current node  is overwrighted with min value,iecurrent node,s data=minval
		root->right=delete(root->right,temp->data);//now we have 2 minvals..so the minval in rt subtree is deleted
	}return root;
	
	}
}

struct node* search(struct node *root, int data) 
{ 
  if (root == NULL) 
    printf("\nNot FOUND!\n"); 
  else if (root->data == data)
    printf("\nFOUND!\n");
  else
  {
	if(data>root->data)
	
	return search(root->right,data);
	
	else
	return search(root->left,data);     
  }
  	
}



void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}


