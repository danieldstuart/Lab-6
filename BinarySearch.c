# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
 
//sets up the struct used throughout the program
 
typedef struct BinarySearch {
   int data;
   struct BinarySearch *lchild, *rchild;
} node;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
 
//prints out the options for the user and prompts for input
 
void main() {
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;
   clrscr();
 
   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
 
      switch (choice) {
      case 1:
         do {
            new_node = get_node();
            printf("\nEnter: ");
            scanf("%d", &new_node->data);
 
            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);
 
            printf("\nEnter More?(y/n)");
            ans = getch();
         } while (ans == 'y');
         break;
 
      case 2:
         printf("\nWhat to search? :");
         scanf("%d", &key);
 
         tmp = search(root, key, &parent);
         printf("\nParent of node %d is %d", tmp->data, parent->data);
         break;
 
      case 3:
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nInorder display : ");
            inorder(root);
            printf("\nPreorder display : ");
            preorder(root);
            printf("\nPostorder display : ");
            postorder(root);
         }
         break;
      }
   } while (choice != 4);
}