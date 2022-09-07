/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
long long sm;
int cnt;
void trav(Node *root,int k){
    if(!root)return;
    if(cnt>=k)return;
    trav(root->left,k);
    if(cnt<k){
        sm+=root->data;
        cnt++;
    }
    trav(root->right,k);
}

int sum(Node* root, int k) 
{ 
    sm=0;
    cnt=0;
    trav(root,k);
    return sm;
} 