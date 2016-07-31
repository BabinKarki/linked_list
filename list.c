/*Name: Babin Karki
Roll number: 505
Reference: Data and Structure book, www.geeksforgeeks.org
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
 
void deleteNode(struct node *list, struct node *n)
{
    if(list == n)//deleting from first
    {
        if(list == NULL)
        {
            printf("Underflow");
            
            return;
        }
 
        list->data = list->next->data;
 
        //store address of next node
        n = list->next;
        list->next = list->next->next;//remove the address of next node
 
        // free memory
        free(n);
 
        return;
    }
 
 
    // find the previous node
    struct node *prev = list;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
 
    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        printf("\n node is not present in Linked List");
        return;
    }
 
    // Remove node from Linked List
    prev->next = prev->next->next;
    free(n);
 
    return; 
}
 
/* Utility function to insert a node at the begining */
void push(struct node **list_ref, int new_data)
{
    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *list_ref;
    *list_ref = new_node;
}
 
void printList(struct node *list)
{
    while(list!=NULL)
    {
        printf("%d ",list->data);
        list=list->next;
    }
    printf("\n");
}
int main()//making list
{
    struct node *list = NULL;
 
    push(&list,5);
    push(&list,4);
    push(&list,3);
    push(&list,2);
    push(&list,1);
 
 
    printf("The link list created is: ");
    printList(list);
 
    printf("Deleting first node \n");//deleting first node
    deleteNode(list, list);
    printList(list);
 
 printf("Deleting second node \n");//deleting second node
    deleteNode(list, list);
    printList(list);

 printf("Deleting Third node \n");//deleting third node
    deleteNode(list, list);
    printList(list);
	
	 printf("Deleting Fourth node \n");//deleting fourth node
    deleteNode(list, list);
    printList(list);
    
     printf("Deleting Fifth node \n");//deleting fifth node
    deleteNode(list, list);
   printList(list);
   
    printf("Deleting Sixth node \n");//deleting fifth node
    deleteNode(list, list);
   printList(list);
    
    getchar();
    return 0;
}
