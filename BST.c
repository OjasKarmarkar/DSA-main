#include<stdio.h>

typedef struct Node{
   int data;
   struct Node * left;
   struct Node * right;
}Node;

int count =0 , leaf=0 , deg1=0 , deg2=0;

Node *newNode(int data){
 Node * temp = (Node*)malloc(sizeof(Node));
temp->data = data;
temp->right=NULL;
temp->left=NULL;
return temp;
}

Node *AddNode(Node * root , int data){
    Node * ptr = root;
    if(ptr==NULL){
       return newNode(data);
    }
    else if(ptr->data > data){
        ptr->left=AddNode(ptr->left , data);
    }else{
        ptr->right=AddNode(ptr->right , data);
    }
    return root;

}

Node *createBST(){
    Node * p;
    int val;
    printf("Enter root node data : ");
    scanf("%d",&val);
    p=AddNode(p,val);
    while(val!=-1){
    printf("Enter data (-1 to finish inserting) : ");
    scanf("%d",&val);
    if(val==-1){
        break;
    }
    p=AddNode(p,val);
    }
    return p;
}

int min(Node * root){
    Node * ptr = root;
    while(ptr->left!=NULL){
         ptr=ptr->left;
    }

    return ptr->data;
}

int max(Node * root){
    Node * ptr = root;
    while(ptr->right!=NULL){
         ptr=ptr->right;
    }

    return ptr->data;
}




void inorder(Node * root){
    Node * ptr = root;
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%d " , ptr->data);
        inorder(ptr->right);
    }
}

void main(){
    int ch=0 , data , minmax=0;
    Node *temp;
    printf("**** Creation of binary search tree ****\n");
    Node * root = createBST();
    do{
        printf("\n1. Insert\n2. Max\n3. Min\n4. Exit\nEnter your choice : ");
        scanf("%d" , &ch);
        switch (ch){
        case 1:
            printf("Enter data to insert : ");
            scanf("%d" , &data);
            root=AddNode(root , data);
            printf("Binary tree is : ");
            inorder(root);
            break;
        case 2:
            minmax=max(root);
            printf("Maximum value of BST is  : %d " , minmax);
            break;
        case 3:
            minmax=min(root);
            printf("Minimum value of BST is  : %d " , minmax);
            break;
        case 4:
            break;

        }
    }while(ch!=4);
}
