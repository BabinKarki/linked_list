//Program to implement linked list with the function to deletr first node
//Name: Babin Karki 
//Roll no:505
//Reference: Data Structure Book and Internet

 
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>
 
 struct node {
 	int info;
 	struct node *next;
 };
 
 typedef struct node *nodeptr;
 nodeptr getnode();
 int check_underflow(nodeptr *);
 int deletefromfirst(nodeptr *);
 void freenode(nodeptr);
 void insertatfirst(nodeptr *, int);
 void displaylist(nodeptr);
 
 int main () {
 	nodeptr list;//list of 4 different node
 	list = NULL;
 	insertatfirst(&list, 4);
 	insertatfirst(&list, 3);
 	insertatfirst(&list, 2);
 	insertatfirst(&list, 1);
 	
 	displaylist(list);
 	printf ("\ndeleting first node = %d \n", deletefromfirst(&list));
 	printf ("deleting second node = %d \n", deletefromfirst(&list));
 	printf ("deleting third node = %d \n", deletefromfirst(&list));
 	printf ("deleting fourth node = %d \n", deletefromfirst(&list));
 	printf ("deleting fifth node = %d \n", deletefromfirst(&list));//this node does not exist

 	getch();
 	return 0;
 }
 
 nodeptr getnode() {
 	return (nodeptr)malloc(sizeof(struct node));
 }
 
 void freenode(nodeptr p) {
 	free (p);
 }
 
 void insertatfirst(nodeptr *p, int x) {
 	nodeptr q;
 	q = getnode();
 	q->info = x;
 	q->next = *p;
 	*p = q;
 }
 
 void displaylist(nodeptr p) {
 	nodeptr ptr = p;
 	while(ptr != NULL) {
		printf ("%d \t", ptr->info);
 ptr = ptr->next;
 	}
 }
int deletefromfirst (nodeptr *p) {
	if (check_underflow(p)) {
 		printf (" underflow \n");
		getch();
 		exit(1);
	  } 
	else {
		int x;
		nodeptr q;
 		q = *p;
 		*p = q->next;
 		x = q->info;
 		return x;
 		freenode(q);
 	}
 }
 
 int check_underflow(nodeptr *p){
 	return (*p == NULL);
 }

