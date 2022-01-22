#include<stdio.h>

typedef struct Node{
   int data;
   struct Node * left;
   struct Node * right;
}Node;

int count =0 , leaf=0 , deg1=0 , deg2=0;

Node *createBT(){
    Node *p;
    int val;
    printf("Enter -1 for null data : ");
    scanf("%d",&val);
    if(val==-1)
    return NULL;
    p=(Node*)malloc(sizeof(Node));
    p->data=val;
    printf("Enter left child of %d:\n",val);
    p->left=createBT();

    printf("Enter right child of %d:\n",val);
    p->right=createBT();
    return p;
}


Node *copy(Node *root){
  if(root == NULL){
     return root;
  }
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = root->data;
  temp->left = copy(root->left);
  temp->right = copy(root->right);
  return temp;
}

Node *reverseBT(Node * root){
    Node * p = root;
    Node * temp = root->right;
    root->right = root->left;
    root->left=temp;
    if(p->left!=NULL){
        p->left=reverseBT(p->left);

    }else if(p->right!=NULL){
     p->right=reverseBT(p->right);
     }
    return p;
}

void countNodes(Node *root){
    Node * ptr = root;
    if(ptr!=NULL){
        countNodes(ptr->left);
        count++;
        countNodes(ptr->right);
    }
}

void countLeaf(Node *root){
    Node * ptr = root;
    if(ptr!=NULL){
        countLeaf(ptr->left);
        if(ptr->right==NULL && ptr->left==NULL){
            leaf++;
        }
        countLeaf(ptr->right);
    }
}

void countDeg1(Node *root){
    Node * ptr = root;
    if(ptr!=NULL){
        countDeg1(ptr->left);
        if((ptr->right==NULL && ptr->left!=NULL) || (ptr->left==NULL && ptr->right!=NULL)){
            deg1++;
        }
        countDeg1(ptr->right);
    }
}

void countDeg2(Node *root){
    Node * ptr = root;
    if(ptr!=NULL){
        if(ptr->right!=NULL && ptr->left!=NULL){
            deg2++;
        }
        countDeg2(ptr->left);
        countDeg2(ptr->right);
    }
}

int height(Node * root){
    if(root==NULL){
        return 0;
    }else{
        int lh = height(root->left);
        int rh= height(root->right);
        if(lh>rh) return lh+1;
        return rh+1;
    }
}

void preorder(Node * root){
    Node * ptr = root;
    if(ptr!=NULL){
        printf("%d " , ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(Node * root){
    Node * ptr = root;
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d " , ptr->data);
    }
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
    int ch=0 , h=0;
    printf("**** Creation of binary tree ****\n");
    Node * root = createBT();
    do{
        printf("\n1. Count nodes\n2. Count nodes of degree (1)\n3. Count nodes of degree (2)\n4. Count leaf nodes\n5. Copy tree\n6. Mirror tree\n7. Height\n8. PreOrder\n9. InOrder\n10. PostOrder\nEnter your choice : ");
        scanf("%d" , &ch);
        switch (ch){
        case 1:
            count=0;
            countNodes(root);
            printf("No of nodes are : %d " , count);
            break;
        case 2:
            deg1=0;
            countDeg1(root);
            printf("No of nodes with degree 1 are : %d " , deg1);
            break;
        case 3:
            deg2=0;
            countDeg2(root);
            printf("No of nodes with degree 2 are : %d " , deg2);
            break;
        case 4:
            leaf=0;
            countLeaf(root);
            printf("No of leaf nodes are : %d " , leaf);
            break;
        case 5:
            root = copy(root);
            printf("Copied tree's inorder is :");
            inorder(root);
            break;
            break;
        case 6:
            root=reverseBT(root);
            break;
        case 7:
            h = height(root);
            printf("Height of Binary tree is : %d" , h);
            break;
        case 8:
            printf("Preorder : ");
            preorder(root);
            break;
        case 9:
            printf("Inorder : ");
            inorder(root);
            break;
        case 10:
            printf("Postorder : ");
            postorder(root);
            break;

        }
    }while(ch!=11);
}
