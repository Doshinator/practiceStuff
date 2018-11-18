#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Node{
    int val;
    Node *next;
    Node(int n): val(n), next(NULL) { };
};
Node *concat(Node *a, Node *b);
int howManyNodes(Node *head);
void append(Node **head, int data);
void printList(Node *a);
vector <Node*> splitListToParts(Node *root, int k);
void printVectorofNodes(vector<Node*> v);

// class Solution {
// public:
//     vector<Node*> splitListToParts(Node* root, int k) { // Node * root with value k
        
//     }
// };

int main(){
    // testing the print, append, and concat functionality
    if(0){
        Node *head = new Node(1);
        append(&head, 2);
        append(&head, 3);
        append(&head, 4);

        Node *head2 = new Node(5);
        append(&head2, 6);
        append(&head2, 7);
        append(&head2, 8);
        printList(head);
        cout << endl;
        printList(head2);
        cout << endl;

        printList(concat(head, head2));
    }
    // this is just testing to see if i can actually split a linked list into a vector
    // it does!
    if(1){
        Node *head = new Node(20);
        append(&head, 10);
        append(&head, 15);
        append(&head, 19);
        append(&head, 1);
        append(&head, 7);
        append(&head, 9);
        append(&head, 7);
        append(&head, 11);
        append(&head, 40);
        append(&head, 50);
        append(&head, 100);
        
        // append(&head, 7);
        // currently : node count = 4
        int k = 5;
        vector<Node*> v = splitListToParts(head , k);
        printVectorofNodes(v);
        
    }





    return 0;
}


int howManyNodes(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// vector <Node*> splitListToParts(Node *root, int k){

// }

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

Node *concat(Node *a, Node *b){
    Node *temp = a;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = b;
    return a;
}


void printList(Node *a){
    Node *temp = a;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
}
vector <Node*> splitListToParts(Node *root, int k){
    vector<Node*> v;
    Node *curr = root;
    Node *next = NULL;
    int nodeCount = howManyNodes(curr);
    
    if(nodeCount <= k){
        for(int i = 0; i < nodeCount ; i++){
            next = curr->next;
            curr->next = NULL;
            v.push_back(curr);
            curr = next; 
        }
        //rest of the nodes is not there (they are null);
    }else if((nodeCount % k) == 0){
        int pieces = 0;       
        pieces = nodeCount / k;
        // 4 / 2 = 2 -> {[] [] , [] []}
        for(int j = 0; j < k; j++){
            curr = root;
            for(int i = 0; i < pieces - 1; i++){
                curr = curr->next;
            }
            next = curr->next;
            curr->next = NULL;
            v.push_back(root);
            root = next;
        }
    }else{
        cout << "Implment the case where nodeCount % k != 0 .. ex : 10/3 -> {[1][2][3][4],[5][6][7],[8][9][10]}" << endl;
    }

    return v;
}

void printVectorofNodes(vector<Node*> v){
    cout <<  "{ ";
        for(unsigned int i = 0; i < v.size(); i++){
            cout << "[";
            while(v[i]){
                cout << v[i]->val << " ,";
                v[i] = v[i]->next;
            }
            cout << "]";
        }
    cout <<  "}" << endl;
}