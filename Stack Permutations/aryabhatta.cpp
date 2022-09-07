//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B){
        stack<int> temp;
        int it=0;
        int step=0;
        for(int i=0; i<n; i++){

            temp.push(A[i]);

            /** print temp */
            // stack<int> temp2 = temp;
            // cout << "STEP-" << step++ << ":\t";
            // for(int j=0; j<temp.size(); j++){
            //     cout << temp2.top() << " ";
            //     temp2.pop();
            // }
            // cout << endl;
            // cout << " it: " << it << endl;

            while((!temp.empty()) && temp.top()==B[it]){
                int x = temp.top();
                temp.pop();
                it++;
                // cout << "  in while: " << x << endl;
            }
            // cout << " it: " << it << endl;

        }
        // cout << "it: " << it << endl;
        if(it==n)
            return 1;
            
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
