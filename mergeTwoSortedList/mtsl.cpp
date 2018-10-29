#include <iostream>
using namespace std;
/*
    Merge two sorted list
    1->2->4 , 1->3->4
    1->1->2->3->4->4
 */

/*
class List{
    public:
    virtual List *MergeSortedList(List *l, List *r) = 0;

};
class LMt : public List{
    public:
    LMt () { };
    List *MergeSortedList(List *l, List *r ) { return l; }

};
class LOne : public List{
    public:
    int n;
    List *d;
    List *MergeSortedList(List *l, List *r) { return this->d->MergeSortedList( new LOne(n , r), new LMt());}
    LOne(int n, List *d): n(n) , d(d) { };
};

class MergeSortedList : public List{
    public:
    List *l, *r;
    MergeSortedList(List *l, List *r) : l(l), r(r) { };
    

};

void printList(List *l) {
    cout << "have no idea what im doing" << endl;
}
int main(){
    
    auto example = new LOne(1 , new LOne(2 , new LOne(3 , new LMt ())));
    printList(example);
    
    return 0;
}*/

struct Node{
    int val;
    Node *next;
    Node(int n) : val(n) , next(NULL) { };
};

Node *mergeList(Node *a, Node *b);
void append(Node **head, int data);
void printList(Node *a);
Node *concat(Node *h1, Node *h2);

int main(){
    Node *a = new Node(1);
    append(&a, 3);
    append(&a, 4);
    Node *b = new Node(1);
    append(&b, 2);
    append(&b, 4);
   
    auto example = mergeList(a, b);
    printList(example);
    
    return 0;
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

Node *concat(Node *h1, Node *h2){
    Node *temp = h1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = h2;
    return h1;
}
// say Node *b = NULL;
// then b is holding adress of a NULL Node object, containing nothing
// so b->val & b->next is seg fault because there is nothing inside b
Node *mergeList(Node *a, Node *b){
    // you have to init an empty/NULL list to append to, or else its not going to be NULL, its going to be something else... weird
    Node *temp = NULL;
    
    
    while(1){
        if(a == NULL){
            if(temp == NULL){
                temp = b;
                return temp;
            }
            return concat(temp, b);
        }
        if(b == NULL){
            if(temp == NULL){
                temp = a;
                return temp;
            } 
            return concat(temp, a);
        }
        if(a->val <= b->val){
            append(&temp, a->val);
            a = a->next;
        } else { 
            append(&temp, b->val);
            b = b->next;
        }
    }
}

void printList(Node *a){
    while(a != NULL){
        cout << a->val << "->";
        a = a->next;
    }
    cout << endl;
}
