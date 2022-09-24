//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        string temp="";
        for(int i=0;S[i]!='\0';i++)
        {
            if(isalpha(S[i])!=0 || isdigit(S[i])!=0){
            temp+=S[i];
            }
        }
    
    string ans="";
    int n=temp.length();
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        ans+=temp[i];
        cnt++;
        if(cnt%K==0 && i!=0)
        {
            ans+='-';
        }
    }
    reverse(ans.begin(),ans.end());
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
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends
