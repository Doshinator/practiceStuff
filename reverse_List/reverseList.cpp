#include <iostream> 
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int n): val(n), next(NULL) { };
};
Node *reverseList(Node *head);
void append(Node **head, int data);
void printList(Node *head);
int main(){
    Node *head = NULL;
    append(&head , 5);
    append(&head , 1);
    append(&head , 3);
    append(&head , 7);
    cout << "before reverse" << endl;
    printList(head);
    auto example = reverseList(head);
    cout << "\nafter reverse\n";
    printList(example);

    return 0;
}


Node *reverseList(Node *head){
    Node *curr = head;
    Node *next, *prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
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
void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
}