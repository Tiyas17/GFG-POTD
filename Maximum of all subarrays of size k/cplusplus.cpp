//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> res;
        int last_max_ind = distance(arr, max_element(arr, arr + k));
        res.push_back(arr[last_max_ind]);
        
        for(int i=1; i<n-k+1; i++){
            if(last_max_ind != i-1){
                if(arr[last_max_ind] < arr[i+k-1]){
                    last_max_ind = i+k-1;
                }
                res.push_back(arr[last_max_ind]);
            } else {
                last_max_ind = distance(arr, max_element(arr+i, arr+i+k));
                res.push_back(arr[last_max_ind]);
                
                // int curr_res = *max_element(arr+i, arr+i+k);
                // res.push_back(curr_res);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
