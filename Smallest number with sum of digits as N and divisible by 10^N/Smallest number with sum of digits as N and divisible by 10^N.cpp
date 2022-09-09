//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int n)
	{
	    // Code here.
	    int arr[9]={1,2,3,4,5,6,7,8,9};
	    vector<int> ans;
	    int sum=0;
	    int i=8;
	    while(sum<n)
	    {
	        if(arr[i]>n-sum)
	        {
	            i--;
	        }
	        else //if(arr[i]<=n-sum)
	        {
	            ans.push_back(arr[i]);
	            sum+=arr[i];
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    for(int i=1;i<=n;i++)
	    {
	        ans.push_back(0);
	    }
	    string str="";
	    for (int i: ans) {
        str += to_string(i);
    }
    return str;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
