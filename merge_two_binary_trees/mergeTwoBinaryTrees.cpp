#include <iostream>
#include <stdlib.h>
#include <stack>

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int data) : val(data), left(NULL) , right(NULL) {};
};

/**
    Given two binary trees and imagine that when you put one of them to cover the other, some 
    nodes of the two trees are overlapped while the others are not.

    You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then 
    sum node values up as the new value of the merged node. Otherwise, the NOT null node will be 
    used as the node of new tree.

    Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7


 * 
 */


Node *mergeTree(Node *t1, Node *t2);
void insert(Node **leaf, int val);
Node *N(int data);
void print(Node *root);

int main(){
    Node *t1 = NULL;
    
    insert(&t1, 1); 
    insert(&t1->left , 3);
    insert(&t1->left->left , 5);
    insert(&t1->right , 2);
    // printf("\n%p[%d]\n", root, root->val);
    // insert(&t1->left->left , 5);

    Node *t2 = NULL;
    insert(&t2, 2);
    insert(&t2->left, 1);
    insert(&t2->left->right, 4);
    insert(&t2->right, 3);
    insert(&t2->right->right, 7);

    // printf("%d\n", root->val);

    print(mergeTree(t1, t2));


    free(t1);
    free(t2);
    return 0;
}


// **leaf holds an address of which that address holds an address which holds a node

// xleaf[x64]~~>x64[x720]~~~>x720[Node]


/*
    --------------------------------------------------------------
    IMPORTANT NOTES | Passing reference vs Passing copy https://stackoverflow.com/questions/46066466/passing-null-pointer-in-function
    --------------------------------------------------------------
// you are passing in a COPY of the current address, NULL to be changed, which doesn't change
void insert(Node *leaf, int val){

    //everything inside here that is changed is just a change of the copy, not the actual refrence because you are passing in a copy.
    if(leaf == NULL){
        leaf = (Node*)malloc(sizeof(Node));  // here you change the address of the copy variable
        leaf->val = val;                    //  changed value at addressed by head pointer and change in data will be reflected.
        leaf->left = NULL;
        leaf->right = NULL;
        // printf("%d\n", leaf->val);
    }
}
*/

void insert(Node **root, int val){
    
    if((*root) == NULL){
        *root = (Node*)malloc(sizeof(Node));
        (*root) = N(val);
    } else {
        std::cout << "There already exists a node at that memory location." << std::endl;
    }

}

Node *N(int data) {
    return (new Node(data));
}

void print(Node *root){
    if(root != NULL){
        print(root->left);
        printf("%d ", root->val);
        print(root->right);
    }
}

Node *mergeTree(Node *t1, Node *t2){
    if(!t1 && !t2){
        return nullptr;
    }
    // extract val
    int val1 = t1 ? t1->val : 0;
    int val2 = t2 ? t2->val : 0;

    //merging to a new tree
    Node *t = N(val1+val2);
    t->left = mergeTree(t1 ? t1->left : nullptr , t2 ? t2->left : nullptr);
    t->right = mergeTree(t1 ? t1->right : nullptr , t2 ? t2->right : nullptr);

    return t;
}