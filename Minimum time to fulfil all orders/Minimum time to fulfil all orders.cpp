//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool isPossible(int mid,int N,vector<int> &A,int x)
    {
        int donots=0;
        for(int t:A)
        {
            int timelaglo=0;
            int timelagbe=t;
            while(timelaglo+timelagbe<=mid)
            {
                donots++;
                timelaglo+=timelagbe;
                timelagbe+=t;
            }
        }
        
        if(donots>=x)
        return true;
        else
        return false;
    }
    int findMinTime(int x, vector<int>&A, int L){
        //write your code here
        int N=A.size();
        sort(A.begin(),A.end());
        int l=A[0];
        int h=(A[N-1]*(x+1)*x)/2;
        
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPossible(mid,N,A,x))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends
