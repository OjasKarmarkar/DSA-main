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

Queue *enqueueStart(Queue *q, int value){
Node *p = (Node *)malloc(sizeof(Node));
p->data = value;
if (q->first == NULL){
    p->next = NULL;
	q->first = q->last=p;
	return q;
}

p->next = q->first;
q->first = p;
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

int *dequeueEnd(Queue *q){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp=q->first;
    int dltVal;
    if( q->first == NULL){
        printf("Underflow");
        return -1;
    }

    if (q->first == q->last){
        temp=q->first;
        dltVal= temp->data;
        q->first = q->last = NULL;
        free(temp);
        return dltVal;
    }

    while(temp->next->next != NULL){
         temp = temp->next;
    }
    dltVal = temp->next->data;
    q->last = temp;
    temp = temp->next;
    free(temp);
    q->last->next=NULL;
    return dltVal;
}




void main(){

    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->first=q->last=NULL;
    int val , ch , poppedVal;

    do{
        printf("\n1. enqueue \n2. dqueue \n3. enqueue at start \n4. dqueue at end \n5. Display\n6. Count\n7. Exit\nEnter your choice : ");
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
            printf("Enter Value: ");
            scanf("%d" , &val);
            q=enqueueStart(q , val);
            display(q);
            break;
        case 4:
            poppedVal=dequeueEnd(q);
            if(poppedVal!=-1){
                  printf("%d has been removed from the queue\n" , poppedVal);
                    display(q);
            }
            break;
        case 5:
            display(q);
            break;
        case 6:
            count(q);
            break;
        case 7:
            break;

        }
    }while(ch!=7);

}
