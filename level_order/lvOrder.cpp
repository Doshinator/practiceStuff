#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int n) : val(n), left(NULL), right(NULL) {} ;
};

vector<vector<int>> levelOrder(Node *root);
void PrintLevelOrder(Node *root);
Node *addNode(int data);




int main(){
    Node *root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(9);
    root->left->left = new Node(11);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(20);
    
    vector<vector<int>> v = levelOrder(root);
    for(unsigned int i = 0; i < v.size(); i++){
        for(unsigned int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
   
    return 0;
}



void PrintLevelOrder(Node *root){
    queue<Node*> q;
    if(root == NULL) return;
    q.push(root);
    while(!q.empty()){
        Node *n = q.front();
        cout << n->val << " ";
        q.pop();

        if(n->left != NULL){
            q.push(n->left);
        }
        if(n->right != NULL){
            q.push(n->right);
        }
    }

}
Node *addNode(int data){
    Node *temp = new Node(data);
    return temp;

}

vector<vector<int>> levelOrder(Node *root){
    vector<vector<int>> result;
    if(root == NULL) return result;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++){
            Node *n = q.front();
            level.push_back(n->val);
            q.pop();
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        result.push_back(level);
        
    }
    return result;
}
