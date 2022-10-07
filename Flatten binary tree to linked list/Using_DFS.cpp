//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

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

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    stack<Node*> dfs;   // using DFS   
    vector<int> vec;    // to store keys in order
    void flatten(Node *root)
    {
        //code here
        // Storing values in vec using DFS
        if(root != NULL)
            dfs.push(root);
            
        while(!dfs.empty()){
            Node* currNode = dfs.top();
            dfs.pop();
            
            vec.push_back(currNode->key);
            
            Node* left =  currNode->left;
            Node* right = currNode->right;
            
            if(right != NULL)
                dfs.push(right);
            if(left != NULL)
                dfs.push(left);
        }
        
        // making new linked list tree
        int i=0;
        root->key = vec[i]; i++;
        
        Node* currNode;
        Node* prevNode = root;
        while(i<vec.size()){
            currNode = newNode(vec[i]);
            prevNode->left = NULL;
            prevNode->right = currNode;
            
            prevNode = currNode;
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() {

  int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}

// } Driver Code Ends
