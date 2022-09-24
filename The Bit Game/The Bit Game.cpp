//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int swapBitGame(long long N){
        // code here 
        int cnt=0;
        string str = bitset<50>(N).to_string();
        for(int i=0;i<50;i++)
        {
            if(str[i]=='1')
            {
                cnt++;
            }
           
        }
         if(cnt%2==0)
            {
                return 2;
            }
            else
            return 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
