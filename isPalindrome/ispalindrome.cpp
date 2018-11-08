#include <iostream>

using namespace std;
typedef struct Node{
    int val;
    struct Node *next;
    Node(int x) : val(x), next(NULL) {}
}Node;

class Solution{
    private:
        int count = 0;
    public:
        bool isPalindrome(Node *head);
        void append(Node **head, int data);
        void printList(Node *node);
        void traverseHalf(Node *head);

    

};
void insertAfter(Node *prev, int data);


int main(void){
    // Solution *s1 dynamic stack allocation 
    /*Dynamically allocated memory is allocated on Heap and non-static and local variables get memory allocated on Stack*/
    //Solution *s1 = new Solution;
    //Solution s1 allocation on stack
    Solution *s1 = new Solution;
    Node *head = NULL;

    s1->append(&head, 5);
    cout << "pointing to addr of this struct : "<< head << endl;
    s1->append(&head, 8);
    s1->append(&head, 7);
    s1->append(&head, 7);
    s1->append(&head, 8);
    s1->append(&head, 5);
    s1->printList(head);
    if(s1->isPalindrome(head)){cout << "It is indeed a palindrome!" << endl;}
    

    return 0;
}

bool Solution::isPalindrome(Node *head){
    /*
        start
        end
        char temp;

        while(head != tail){                <-- figure out the condition when they meet
            if(head->val == tail->val){
                head++ || head = head->next
                tail-- || tail = tail->next
            }
        }
    }  
    */

   /*Count how many # of nodes there are in the list, and use the information to reverse half the number of nodes*/
    Node *tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            count++;
        }
   /*traverse the first half of the list*/
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    for(int i = 0 ; i < (count / 2) ; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    /*finished traversing*/
    
    /*
        head start at the mid of the list. head->next is traversing <-
        curr will start at the mid + 1 of the list. curr->next is traversing ->
        printList(head);
        printList(curr);
    */
    
    /*palindrome check*/
    while((head->next != NULL) && (curr->next != NULL)){
        
        if(head->val != curr->val){
            cout << "Not a Palindrome" << endl;
            return false;
        }
        head = head->next;
        curr = curr->next;
    }
    return true;
    
}

void Solution::append(Node **head, int data){
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

/*
   void append(Node **head, int data){
       Node *temp = new Node(data);
       Node *last = *head;
       if(*head == NULL){
           *head = temp;
           return
       }
       while(last->next != NULL){
           last = last->next;
       }
       last->next = temp;
       return;
   }
*/





void Solution::printList(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    
    }
}
