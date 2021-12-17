#include<stdio.h>

typedef struct Node {
    struct Node *next;
    int data;
}Node;

typedef struct Queue{
    Node *first;
    Node *last;
}Queue;

void display(Queue *q){
Node *ptr = q->first;
int i=1;

if(q->first==NULL){
    printf("Empty Queue");
}else{
    while(ptr!=NULL){
        printf("%d is at position ( %d ) in Queue\n" , ptr->data , i);
        i++;
        ptr=ptr->next;
    }
}
}

void count(Queue *q){
Node *ptr = q->first;
int i=0;

if(q->first==NULL){
    printf("Empty Queue");
}else{
    while(ptr!=NULL){
        i++;
        ptr=ptr->next;
    }
printf("Total %d elements in the Queue" , i);
}

}

Queue* enq(Queue *q , int data){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data=data;
     p->next=NULL;
    if(q->first==NULL){
    q->first=q->last=p;
    }else{
       q->first->next=q->last;
       q->last->next=p;
        q->last=p;
    }
return q;
}

int deq(Queue *q){
    Node *temp = (Node *)malloc(sizeof(Node));
    int dltVal;
    if(q->first==NULL){
    printf("Underflow");
    return -1;

    }else{
       temp=q->first;
       dltVal = temp->data;
       if(temp->next!=NULL){
       temp->next=q->first->next;
       q->first=temp->next;
       free(temp);
       return dltVal;
       }else{
            free(temp);
            q->first=q->last=NULL;
            return dltVal;
       }

    }
}



void main(){

    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->first=q->last=NULL;
    int val , ch , poppedVal;

    do{
        printf("\n1. enqueue \n2. dqueue\n3. Display\n4. Count\n5. Exit\nEnter your choice : ");
        scanf("%d" , &ch);
        switch(ch){
        case 1:
            printf("Enter Value: ");
            scanf("%d" , &val);
            q=enq(q , val);
            display(q);
            break;
        case 2:
            poppedVal=deq(q);
            if(poppedVal!=-1){
                  printf("%d has been removed from the queue\n" , poppedVal);
                   display(q);
            }

            break;
        case 3:
            display(q);
            break;
        case 4:
            count(q);
            break;
        case 5:
            break;

        }
    }while(ch!=5);

}
