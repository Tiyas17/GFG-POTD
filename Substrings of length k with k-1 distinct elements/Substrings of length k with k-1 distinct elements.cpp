//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        map<char,int> freq;
        for(int i=0;i<K;i++)
        {
            freq[S[i]]++;
        }
        int i=0,j=K-1;
        int ans=0;
        while(j<S.length())
        {
            if(freq.size()==K-1)
            ans++;
            
            freq[S[i]]--;
            if(freq[S[i]]==0)
            {
                freq.erase(S[i]);
            }
            i++;
            j++;
            freq[S[j]]++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
