//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

int sum(Node* root, int k);



int main()
{

	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int k;
		cin >> k;
		Node* root = buildTree(s);
		cout << sum(root, k) << endl;
	
	}
	return 1;
}




// } Driver Code Ends


//User function Template for C++

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

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 

int sum(Node* root, int k) 
{ 
    // Your code here
    vector<int> res;
    
    // how to traverse the tree now?
    // let's use bfs - queue
    queue<Node*> bfs;
    if(root != NULL)
        bfs.push(root);
    
    while(!bfs.empty()){
        Node* currNode = bfs.front();
        bfs.pop();
        
        Node* left =  currNode->left;
        Node* right = currNode->right;
        
        
        if(left != NULL)
            bfs.push(left);
        if(right != NULL)
            bfs.push(right);
        
        int currVal = currNode->data;
        // cout << "curVal: " << currVal << " ";

        // max_element(v.begin(),v.end()) - v.begin();
        vector<int>::iterator max_ind;
        int max=0;
        if(!res.empty()){
            max_ind = max_element(res.begin(), res.end());
        }
      
        // res size incomplete hai tab toh push karo hi
        // if(res.size() < k || currVal < res[max_ind - res.begin()]){
        if(res.size() < k || currVal < *max_ind){
          
            /** pop first - to be able to use the same max_ind iterator for erase() */
            if(res.size() + 1 > k){
                // we should pop the max element here //

                res.erase(max_ind);
                // cout << "popping: ";
            }
            
            // cout << "pushing: " << currVal << " ";  
            res.push_back(currVal);
            
        }
    }
    
    // sum of res
    // res.size() == k
    // cout << "size: " << res.size() << endl;
    // cout << "res: " << endl;

    int sum = 0;
    for(int i=0; i<k; i++){
    // while(!res.empty()){
        int val = res[i];
        // cout << val << " ";

        sum += val;
        // res.pop();
    }
    // cout << endl;
    
    return sum;
} 
