#include <stdio.h>

typedef struct Node{
 int data;
 struct Node *next;
}Node;

int len(Node *start){
    Node *ptr = start;
    int count = 0;

    while(ptr != NULL){
        count += 1;
        ptr = ptr->next;
    }
    return count;
}

void display(Node *start){
    Node *temp=start;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");

}

Node* insertAtStart(Node *start, int value){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data=value;
    n->next=start;
    return n;
}

Node* deleteAtStart(Node *start){
Node *ptr = start;
start = ptr->next;
free(ptr);
return start;
}

Node* insertEnd(Node *start , int value){
Node *ptr = start;
Node *n = (Node *)malloc(sizeof(Node));
n->data = value;
while(ptr->next !=NULL){
    ptr=ptr->next;
}
ptr->next=n;
n->next=NULL;
return start;

}

Node* deleteEnd(Node *start){
if(len(start)==1){
    start=deleteAtStart(start);
    return start;
}
else if(len(start)>1){
Node *ptr = start;
Node *p;
    while(ptr->next != NULL)
    {
         p=ptr;
         ptr = ptr->next;
    }
p->next=NULL;
free(ptr);
return start;
}
printf("Nothing to delete\n");
return start;

}

Node* insertAtPos(Node *start , int value , int pos){

if(pos>len(start)){
    printf("position out of range\n");
    return start;
}else{
    Node *ptr = start;
    int i =1;
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;

    while(i<pos-1){
        ptr=ptr->next;
        i++;
    }

    n->next=ptr->next;
    ptr->next=n;
    return start;
}


}

Node* deletAtPos(Node *start , int pos){

if(pos>len(start)){
    printf("position out of range\n");
    return start;
}else if(pos==len(start)){
    start=deleteEnd(start);
    return start;
}
else if(pos==1){
    start=deleteAtStart(start);
    return start;
}
else{
    Node *ptr = start;
    Node *temp;
    int i = 1;

    while(i!=pos-1){
        ptr=ptr->next;
        i++;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return start;
}


}

Node* sort(Node *start){
 Node *ptr = start;
 Node *i;
 if(len(start)==0 || len(start)==1){
    return start;
 }else{
   int a;

    Node *temp1;
    Node *temp2;

    for(temp1=start; temp1!=NULL; temp1=temp1->next)
      {
        for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
          {
            if(temp2->data < temp1->data)
              {
                a = temp1->data;
                temp1->data = temp2->data;
                temp2->data = a;
              }
           }
       }
    return start;
}
}

int min(Node *start)
{
    Node *ptr = start;
	int min=ptr->data;
	while(ptr!=NULL)
	{
		if(ptr->data < min)
		   min = ptr->data;
		ptr=ptr->next;
	}
	return min;
}


void main(){
    Node *start = NULL;
    int ch,val,pos;
    do{
        printf("1. Insert at start\n2. Insert at pos\n3. Delete at start\n4. Insert at end\n5. Delete at pos\n6. Length of LL\n7. Delete at end\n8. Sort\n9. Display \n10. Find Minimum \nEnter your choice : ");
        scanf("%d" , &ch);
        switch(ch){
        case 1:
            printf("Enter Value: ");
            scanf("%d" , &val);
            start=insertAtStart(start , val);
            display(start);
            break;
        case 2:
            printf("Enter position : ");
            scanf("%d" , &pos);
            printf("Enter value :");
            scanf("%d" , &val);
            start=insertAtPos(start , val , pos);
            display(start);
            break;
        case 3:
            start=deleteAtStart(start);
            display(start);
            break;
        case 4:
            printf("Enter value :");
            scanf("%d" , &val);
            start=insertEnd(start , val);
            display(start);
            break;
        case 5:
            printf("Enter position : ");
            scanf("%d" , &pos);
            start=deletAtPos(start , pos);
            display(start);
            break;
        case 6:
            printf("Length of linked list is : %d " , len(start));
            break;
        case 7:
            start=deleteEnd(start);
            display(start);
            break;
        case 8:
            start=sort(start);
            display(start);
            break;
        case 9:
            display(start);
            break;
        case 10:
            printf("Minimum is %d \n" , min(start));
        }
    }while(ch!=11);



}
