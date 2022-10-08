//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int lastDistChars=-1;
    map<char, int> cnt;
    
    // count non-zero letters of cnt
    int countNonZero(){
        int count = 0;
        for(auto it : cnt){
            if(it.second != 0)
                count += 1;
        }
        
        return count;
    }
    int distinctChars(int a, string S, string sub){
        int n=S.size();
        int m=sub.size();
        if(lastDistChars==-1){
            for(int i=0; i<n; i++)
                cnt.insert(make_pair(S[i], 0));
                
            for(int i=0; i<m; i++){
                cnt[sub[i]] += 1;
            }
            
            return countNonZero();
        }
        
        cnt[S[a-1]] -= 1;
        cnt[sub[m-1]] += 1;
        
        return countNonZero();
        
        // set<char> letter;
        // for(int i=0; i<S.size(); i++){
        //     letter.insert(S[i]);
        // }
        
        // return letter.size();
    }
    
    int countOfSubstrings(string S, int k) {
        // code here
        int count = 0;
        int n = S.size();
        for(int i=0; i<n-k+1; i++){
            string sub = S.substr(i, k);
            
            int distChars = distinctChars(i, S, sub);
            if(distChars==k-1){
                count += 1;
            }
            
            lastDistChars = distChars;
        }
        
        return count;
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
