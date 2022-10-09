//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> primes;     // To store all prime nums
bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= n/2; i++){
        if (n % i == 0)
            return false;
    }
    
    return true;
}

void storePrimes(){
    for(int i=0; i<=100000; i++){
        if(isPrime(i))
            primes.push_back(i);
    }
}

class Solution {
	public:    
	   // Constructor
	   // Solution(){
	   //     storePrimes();
	   // }
	    
	    int diffClosest(int value) {
            // auto const l_it = lower_bound(primes.begin(), primes.end(), value);
            auto const u_it = upper_bound(primes.begin(), primes.end(), value);
            
            // DOUBT: lower_bound() v/s upper_bound()
                
            int ind=-1;
            if(u_it != primes.end())
                ind = u_it - primes.begin();
        
            if(ind == -1){
                return value - *(primes.end()-1);
            }
            
            int val1 = primes[ind] - value;
            
            if(ind-1 < 0)
                return val1;
                
            int val2 = value - primes[ind - 1];
            return min(val1, val2);
        }
        
		int NthTerm(int N){
		    // Code here
		    
		    // Jugaad : to run storePrimes only once & use the same resut in new test cases
		    if(primes.empty())
		        storePrimes();
		        
		    return diffClosest(N);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
