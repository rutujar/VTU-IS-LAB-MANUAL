#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct BST 
{
   int data;
   struct BST *lchild, *rchild;
}node;
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node* search(node *, int);
node* deleteNode(node* , int);
void main() 
{
   int choice,n,i;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   parent = NULL;
   root = NULL;
   printf("\n Program For Binary Search Tree ");
   do 
   {
      printf("\n1.Create");
      printf("\n2.Recursive Traversals");
      printf("\n3.Search");
	  printf("\n4.Delete");
      printf("\n5.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
      switch (choice) 
	  {
      case 1:printf("\n How many nodes you want to enter : ");
		  scanf("%d",&n);
		  printf("\nEnter The %d Elements :  ",n);
		  for(i=0;i<n;i++)
          {
            new_node = get_node();
            scanf("%d", &new_node->data);
             if (root == NULL) // Tree is not Created 
               root = new_node;
            else
               insert(root, new_node);
          } 
         break;
      case 2:if (root == NULL)
            printf("Tree Is Not Created");
         else 
		 {
            printf("\nThe Inorder display : ");
            inorder(root);
            printf("\nThe Preorder display : ");
            preorder(root);
            printf("\nThe Postorder display : ");
            postorder(root);
         }
                  break;
       case 3:		  
		  printf("\nEnter Element to be searched :");
         scanf("%d", &key);
          tmp = search(root, key);
		 if(tmp)
		 	 printf("\nThe %d Element is Present", tmp->data);
		 	 else
			printf("\n The Key %d is not present in the BST",key);
         break;
	  case 4:
		  printf("\n Enter the element to be deleted : ");
		  scanf("%d",&key);
			parent=NULL;
			root = deleteNode(root,key);
			break;
	  default:
		  printf("\n Terminating");
		  exit(0);
      }
   } while (choice != 5);
}
// Get new Node
 node *get_node()
 {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
// This function is for creating a binary search tree
 void insert(node *root, node *new_node) 
{
   if (new_node->data < root->data)
   {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }
    if (new_node->data > root->data)
   {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
   if(new_node->data == root->data)
	   printf("\n %d is a duplicate node , can't insert",new_node->data);
}
// This function is for searching the node from binary Search Tree
 node *search(node *root, int key)
{
   node *temp;
   temp = root;
   if(root == NULL)
   {
	   printf("\n BST is Empty ");
	   return root;
   }
   while (temp != NULL) 
   {
      if (temp->data == key) 
	     return temp;
      if (key < temp->data)
         temp = temp->lchild;
      else
         temp = temp->rchild;
   }
   return NULL;
}
 // This function displays the tree in inorder fashion
 void inorder(node *temp) 
 {
   if (temp != NULL) 
   {
      inorder(temp->lchild);
      printf("%d , ", temp->data);
      inorder(temp->rchild);
   }
}
// This function displays the tree in preorder fashion
 void preorder(node *temp)
 {
   if (temp != NULL) 
   {
      printf("%d , ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
// This function displays the tree in postorder fashion
void postorder(node *temp) 
{
   if (temp != NULL)
   {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d , ", temp->data);
   }
}
node* deleteNode(node* root, int key)
{
    node *temp;
	// base case
    if (root == NULL) 
		return root;
     temp = search(root, key); // search for the key to delete
	if(temp==NULL)
	{
		printf("\n Key is not present in BST , Can't delete !!!");
		return root;
	}
	// If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->data)
	    root->lchild = deleteNode(root->lchild, key);//,root);
	    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->data)
	    root->rchild = deleteNode(root->rchild, key);//,root);
	     // if key is same as root's key, then This is the node to be deleted
    else
    {
        // node with only one child or no child 
	  if (root->lchild == NULL )
        {
           	temp = root->rchild;
		free(root);
            return temp;
        }
	  else if (root->rchild == NULL )
        {
            temp = root->lchild;
			free(root);
            return temp;
        }
			// node with two children: Get the inorder successor (smallest in the right subtree)
        temp=root->rchild;
		while (temp->lchild != NULL)
			temp = temp->lchild;
 		        // Copy the inorder successor's content to this node
        root->data = temp->data;
         // Delete the inorder successor
       root->rchild = deleteNode(root->rchild, temp->data);
		    }
    return root;
}
