/************************** Menu driven for TREE*******************/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int data;
	struct Node* right;
	
}Node;
Node* insert(Node* root,int data)
{
	if(root==NULL)// ROOT(each time create new root)
	{
		Node* temp=(Node*)malloc(sizeof (Node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;


	}
	else //root is present insert by its position
	{
			if(data<root->data)
			{
				root->left=insert(root->left,data);
							
			}
			else if(data>root->data)
			{
				root->right=insert(root->right,data);
			}
	}
return root;
}
void inorder(Node* root)//LPR
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}

}

void preorder(Node* root)//PLR
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);		
		preorder(root->left);
		preorder(root->right);
	}

}

void postorder(Node* root)//LRP
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}

}
Node* search(Node* root,int data)
{
	if(root==NULL || root->data==data)//root==NULL  first and last node condition,
						// root->data==data  found data at same position

		return root;				 												
	if(data<root->data)
		search(root->left,data);
	else
		search(root->right,data);

}

int getMinValue(Node* root)//left is min
{
	while(root->left)
		root=root->left;

	return root->data;
}

int getMaxValue(Node* root)//right is max
{
	while(root->right)
		root=root->right;

	return root->data;
}
Node* delete(Node* root, int data)
{
	if(root == NULL)//first
	{
		return NULL;				
	}
	else if (data < root->data)//only 1 element at left
	{
		root->left = delete(root->left, data);
	}
	else if (data > root->data)//only 1 element at right
	{
		root->right = delete(root->right, data);	
	}
	else
	{
		//we reached at the node to delete...
		// Now check the scenarios..
		if(root->left == NULL )//only right tree is present
		{
			Node *ret = root->right;
			free(root);
			return ret;
		}
		else if(root->right == NULL)//only left tree is present
		{	
			Node *ret = root->left;
			free(root);
			return ret;
						
		}
		else//left and right are present
		{
			root->data = getMinValue(root->right);
			root->right=delete(root->right, root->data);
			
		}
		
	}
	return root;
}


int main()
{
	Node* root=NULL;
	int ch;
	Node* t;
	printf("\n1.Insertion in Tree");
	printf("\n2.Serching in Tree");
	printf("\n3.Deletion in Tree");
	printf("\n4.Minimum element in Tree");
	printf("\n5.Maximum element in Tree");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
	//while(ch<=5)
	//{
	switch(ch)
	{
		case 1:
			root=insert(root,2);
			insert(root,7);
			insert(root,1);
			insert(root,12);
			insert(root,20);
			insert(root,5);
			insert(root,4);
			printf("\n--------------------------------------------------------------\n");
			printf("\ninorder of tree:\n ");
			inorder(root);

			printf("\npreorder of tree:\n ");
			preorder(root);
	
			printf("\npostorder of tree:\n ");
			postorder(root);
			break;
		case 2:
			root=insert(root,2);
			insert(root,7);
			insert(root,1);
			insert(root,12);
			insert(root,20);
			insert(root,5);
			insert(root,4);
			t=search(root,12);
			if(t)//nonzero =found
			{
				printf("\nElement Found(t->data):%d",t->data);	
			}
			else
				printf("\n SORRY Element not found");
			break;
		case 3:
			root=insert(root,2);
			insert(root,7);
			insert(root,1);
			insert(root,12);
			insert(root,20);
			insert(root,5);
			insert(root,4);
			root=delete(root,4);
			inorder(root);
			break;
		case 4:
			root=insert(root,2);
			insert(root,7);
			insert(root,1);
			insert(root,12);
			insert(root,20);
			insert(root,5);
			insert(root,4);
			
			root=delete(root,4);
			inorder(root);
			printf("\nMin element=%d",getMinValue(root));
			break;

		case 5:
			root=insert(root,2);
			insert(root,7);
			insert(root,1);
			insert(root,12);
			insert(root,20);
			insert(root,5);
			insert(root,4);
			
			root=delete(root,4);
			inorder(root);
			printf("\nMax element=%d",getMaxValue(root));
			
			break;
			
		default:
			printf("\n Invalid choice");
			break;
			
			
	}
	
	//}
	
return 0;	
}
