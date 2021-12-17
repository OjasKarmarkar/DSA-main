#include <stdio.h>

typedef struct Node{
 int data;
 struct Node *next;
}Node;



void showElements(Node *head){
    Node *temp=head;
    printf("Linked list is : ");
    while(temp != NULL)
    {
         printf("%d , ", temp->data);
         temp = temp->next;
    }

}

Node* insert_at_top(Node *head, int value){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data=value;
    n->next=head;
    return n;
}

Node* delete_top(Node *head){
Node *travPtr = head;
head = travPtr->next;
free(travPtr);
return head;
}

Node* insert_end(Node *head , int value){
Node *travPtr = head;
Node *n = (Node *)malloc(sizeof(Node));
n->data = value;
while(travPtr->next !=NULL){
    travPtr=travPtr->next;
}
travPtr->next=n;
n->next=NULL;
return head;

}

Node* delete_end(Node *head){
Node *travPtr = head;
Node *p;
    while(travPtr->next != NULL)
    {
         p=travPtr;
         travPtr = travPtr->next;
    }
p->next=NULL;
free(travPtr);
return head;
}


Node* insertAt(Node *head , int value , int pos){

    Node *travPtr = head;
    int i =1;
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;

    while(i<pos-1){
        travPtr=travPtr->next;
        i++;
    }

    n->next=travPtr->next;
    travPtr->next=n;
    return head;



}

Node* dltAt(Node *head , int pos){

    Node *travPtr = head;
    Node *temp;
    int i = 1;

    while(i!=pos-1){
        travPtr=travPtr->next;
        i++;
    }
    temp=travPtr->next;
    travPtr->next=temp->next;
    free(temp);
    return head;
}

Node* insert_after(int num, int prev_num, Node *head) {
  Node *current_node = head;
  Node *new_node;
  while ( current_node->data != prev_num) {
      current_node = current_node->next;
  }
  new_node = (Node *) malloc(sizeof(Node));
  new_node->data = num;
  new_node->next= current_node->next;
  current_node->next = new_node;
return head;
}

int min(Node *head)
{
    Node *travPtr = head;
	int min=travPtr->data;
	while(travPtr!=NULL)
	{
		if(travPtr->data < min)
		   min = travPtr->data;
		travPtr=travPtr->next;
	}
	return min;
}

int max(Node *head)
{
    Node *travPtr = head;
	int max=travPtr->data;
	while(travPtr!=NULL)
	{
		if(travPtr->data > max)
		   max = travPtr->data;
		travPtr=travPtr->next;
	}
	return max;
}


void main(){
    Node *head = NULL;
    int ch,val,pos;
    do{
        printf("\n1. Insert at top , 2. Insert at pos , 3. Delete at head , 4. Insert at end , 5. Delete at pos , 6. Find Maximum , 7. Delete at end , 8. Insert after , 9. showElements , 10. Find Minimum , 11. Exit \n Enter (1-10) : ");
        scanf("%d" , &ch);
        switch(ch){
        case 1:
            printf("data: ");
            scanf("%d" , &val);
            head=insert_at_top(head , val);
            showElements(head);
            break;
        case 2:
            printf("pos : ");
            scanf("%d" , &pos);
            printf("data :");
            scanf("%d" , &val);
            head=insertAt(head , val , pos);
            showElements(head);
            break;
        case 3:
            head=delete_top(head);
            showElements(head);
            break;
        case 4:
            printf("data :");
            scanf("%d" , &val);
            head=insert_end(head , val);
            showElements(head);
            break;
        case 5:
            printf("pos : ");
            scanf("%d" , &pos);
            head=dltAt(head , pos);
            showElements(head);
            break;
        case 6:
            printf("Maximum is %d \n" , max(head));
            break;
        case 7:
            head=delete_end(head);
            showElements(head);
            break;
        case 8:
            printf("Enter value , element after which it needs to be inserted ");
            int a , b;
            scanf("%d %d" , a , b);
            head=insert_after(a,b , head);
            showElements(head);
            break;
        case 9:
            showElements(head);
            break;
        case 10:
            printf("Minimum is %d \n" , min(head));
        }
    }while(ch!=11);



}
