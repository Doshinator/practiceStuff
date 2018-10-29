#include <iostream>

using namespace std;

/*
Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4, 5
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
rotate 5 steps to the right: 1->2->0->NULL

Input: 0->1->NULL, k = 7
Output: 1->0->NULL

Explenation:
rotate 1 steps to the right: 1->0->NULL
rotate 2 steps to the right: 0->1->NULL
rotate 3 steps to the right: 1->0->NULL
rotate 4 steps to the right: 0->1->NULL
rotate 5 steps to the right: 1->0->NULL
rotate 6 steps to the right: 0->1->NULL
rotate 7 steps to the right: 1->0->NULL

rotate  = # of nodes % k 
*/



struct Node{
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) { };
};

int numOfRotation(Node *n, int k);
void concat(Node *a, Node *b);
void print(Node *a);
int nodeCount(Node *n);
Node * rotate_list(Node *head, int k);
void append(Node **head, int data);

int main(){

    {
        int k = 2;
        Node *head = new Node(1);
        append(&head, 2);
        append(&head, 3);
        append(&head, 4);
        append(&head, 5);
        
    
        // cout << nodeCount(head);
        // cout << numOfRotation(head, k);
        auto example = rotate_list(head, numOfRotation(head, k));
        print(example);
        cout << endl;
    }
    {
        int k = 4;
        Node *head = new Node(0);
        append(&head, 1);
        append(&head, 2);
        
    
        // cout << nodeCount(head);
        // cout << numOfRotation(head, k);
        auto example = rotate_list(head, numOfRotation(head, k));
        print(example);
        cout << endl;
    }

   

    return 0;
}
Node * rotate_list(Node *head, int k){
    int count = nodeCount(head);
    if(k == 0){
        return head;
    }
    Node *tail = head;
    Node *b = NULL;

    for(int i = 0; i < count - k - 1; i++){
        tail = tail->next;
    }
    b = tail->next;
    tail->next = NULL;
    concat(b, head);
    // int count = nodeCount(head);
    // tail = for(int i = 0; i < count(#ofnodes) - k - 1 = tail ; i++){
    //          tail = tail->next; // tail should be at the cut off point of rotation
    //          }
    
    /*
    Input: 1->2->3->4->5->NULL, 
    Output: 4->5->1->2->3->NULL
    Explanation:
    rotate 1 steps to the right: 5->1->2->3->4->NULL
    rotate 2 steps to the right: 4->5->1->2->3->NULL
    */
   return b;
}

int numOfRotation(Node *n, int k){
    int count = 0;
    Node *temp = n;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return k % count;
}

void concat(Node *a, Node *b){
    Node *temp = a;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = b;
}
void print(Node *a){
    Node *temp = a;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
}

int nodeCount(Node *n){
    int count = 0;
    Node *temp = n;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
void append(Node **head, int data){
    Node *temp = new Node(data);
    Node *last = *head;
    if(*head == NULL){
        *head = temp;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = temp; 
    return;
}