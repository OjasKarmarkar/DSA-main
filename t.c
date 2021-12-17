#include<stdio.h>

typedef struct Node {
    int coeff , pow;
    struct Node *next;
}Node;

void display(Node *polynomial){
    Node *ptr=polynomial;
    while(ptr!=NULL){
        if(ptr->coeff>=0){
              printf("%dX^%d", ptr->coeff , ptr->pow);
              if (ptr->next != NULL){
                    printf(" + ");
              }

        }else{
              printf("( %dX^%d ) ", ptr->coeff , ptr->pow);
               if (ptr->next != NULL){
                    printf(" + ");
              }
        }

        ptr=ptr->next;
    }
}

int check(Node* p1 , int power){
    Node *ptr = p1;
    while(ptr!=NULL){
          if(power==ptr->pow){
            return 1;
            break;
        }
        ptr=ptr->next;
    }
    return 0;
}

int search(Node *poly , int power){
    Node *ptr = poly;
    while(ptr!=NULL){
        if(power==ptr->pow){
            return ptr->coeff;
            break;
        }
        ptr=ptr->next;
    }
    return 0;
}

Node* add(Node *p1 , Node *p2 , Node * result){
    Node *ptr = p1;
    Node *ptr2 = p2;

    while(ptr!=NULL){
        Node *r=(Node *)malloc(sizeof(Node));
        r->coeff=ptr->coeff+search(p2 , ptr->pow);
        r->pow=ptr->pow;
        if(result==NULL){
            result=r;
            result->next=NULL;
        }else{
            r->next=result;
            result=r;
        }
        ptr=ptr->next;
    }
    while(ptr2!=NULL){
        int x = check(p1,ptr2->pow);
        Node *r=(Node *)malloc(sizeof(Node));
        if(x==0){
        r->coeff=ptr2->coeff;
        r->pow=ptr2->pow;
        r->next=result;
        result=r;
        ptr2=ptr2->next;
        }else{
              ptr2=ptr2->next;
        }

    }
    return result;
}

Node* sub(Node *p1 , Node *p2 , Node * result){
    Node *ptr = p2;
    Node *ptr2 = p1;

    while(ptr!=NULL){
        Node *r=(Node *)malloc(sizeof(Node));
        r->coeff=ptr->coeff-search(p1 , ptr->pow);
        r->pow=ptr->pow;
        if(result==NULL){
            result=r;
            result->next=NULL;
        }else{
            r->next=result;
            result=r;
        }
        ptr=ptr->next;
    }
    while(ptr2!=NULL){
        int x = check(p2,ptr2->pow);
        Node *r=(Node *)malloc(sizeof(Node));
        if(x==0){
        r->coeff=-ptr2->coeff;
        r->pow=ptr2->pow;
        r->next=result;
        result=r;
        ptr2=ptr2->next;
        }else{
              ptr2=ptr2->next;
        }

    }
    return result;
}

Node* addTerms(Node *polynomial , int l){
    int i,cof,power,powExists;
    for(i=0;i<l;i++){
        powExists=0;
        Node *poly = (Node *)malloc(sizeof(Node));
        printf("Enter coeff of term %d : " , i+1);
        scanf("%d" , &cof);
        poly->coeff=cof;
        printf("Enter power of term %d : " , i+1);
        scanf("%d" , &power);
        poly->pow=power;
        if (polynomial == NULL){
		polynomial = poly;
		poly->next = NULL;
        }else{
            Node* temp = polynomial;
            while(temp!=NULL){
                if(temp->pow==power){
                    temp->coeff+=cof;
                    powExists=1;
                }
                temp=temp->next;
            }
            if(powExists==0){
                poly->next=polynomial;
                polynomial=poly;
            }
    }
    }
    return polynomial;

}

void main(){

    int l1,l2;
    Node *result=NULL;
    Node * subResult=NULL;
    Node *poly1=NULL;
    Node *poly2=NULL;
    printf("Enter number of terms in first polynomial : ");
    scanf("%d" , &l1);
    poly1=addTerms(poly1,l1);
    printf("\First polynomial is : ");
    display(poly1);
    printf("\nEnter number of terms in second polynomial : ");
    scanf("%d" , &l2);
    poly2=addTerms(poly2,l2);
    printf("Second polynomial is : ");
    display(poly2);
    result=add(poly1, poly2,result);
    printf("\nAddition is : ");
    display(result);
    subResult=sub(poly1, poly2,subResult);
    printf("\nSubtraction is : ");
    display(subResult);
}
