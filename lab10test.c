#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if (n != NULL) {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    static struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node* search(struct node* root, int key){
    if(root == NULL){
        printf("Tree is empty\n");
        return NULL;
    }
    else if(root->data == key){
        return root;
    }
    else{
        if(root->data > key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
}

int main(){
    struct node *p = createNode(6);
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(8);
    struct node *p4 = createNode(15);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(14);
    struct node *p7 = createNode(24);

    p->left = p1;
    p->right = p2;
    p2->left = p3;
    p2->right = p4;
    p4->left = p6;
    p4->right = p7;
    p3->left = p5;

    printf("Enter your choice for:\n");
    printf("a. Check if the binary tree is a binary search tree\n");
    printf("b. Inorder traversal\n");
    printf("c. Preorder traversal\n");
    printf("d. Postorder traversal\n");
    printf("e. Search for a given element (KEY) in the BST\n");
    printf("f. Exit\n");

    char choice;
    scanf(" %c", &choice); // Notice the space before %c to consume the newline character

    switch(choice){
        case 'a':
            if(isBST(p))
                printf("The binary tree is a binary search tree.\n");
            else
                printf("The binary tree is not a binary search tree.\n");
            break;
        
        case 'b':
            printf("The inorder traversal is: ");
            inOrder(p);
            printf("\n");
            break;
        
        case 'c':
            printf("The preorder traversal is: ");
            preOrder(p);
            printf("\n");
            break;
        
        case 'd':
            printf("The postorder traversal is: ");
            postOrder(p);
            printf("\n");
            break;

        case 'e':
            printf("Enter the key to search: ");
            int key;
            scanf("%d", &key);
            struct node* result = search(p, key);
            if(result != NULL)
                printf("Element %d found in the BST.\n", result->data);
            else
                printf("Element not found in the BST.\n");
            break;

        case 'f':
            return 0;
        
        default:
            printf("Wrong choice\n");
    }

    return 0;
}
