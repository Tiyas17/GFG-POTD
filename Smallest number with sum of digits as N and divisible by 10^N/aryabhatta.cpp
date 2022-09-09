//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int N)
	{
	    // Code here.
	    vector<int> vec;
	    int sum=0;
	    while(sum < N){
	        if(N-sum > 9){
	            sum += 9;
	            vec.push_back(9);
	        } else{
	            int push = N-sum;
                vec.push_back(push);
	            sum += (push);
	        }
	    }
	    
	   // sum == N
	   stringstream ss;
	   //string s = "";
	   for(int i=vec.size()-1; i>=0; i--){
	       ss << vec[i];
	       //s += to_string(vec[i]);
	   }
	   
	   for(int i=0; i<N; i++){
	       ss << "0";
	       //s += "0";
	   }
	   
	   string str;
	   ss >> str;
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
