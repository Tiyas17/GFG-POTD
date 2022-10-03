class Solution {
  public:
    
    int isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return 0;
        }
        return 1;
    }
  
    int sumOfAll(int l, int r){
        vector<int>primes;
        for(int i=2;i<1e4+1;i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        int ans=0;
        if(l==1){
            ans++;
            l++;
        }
        for(int i=l;i<=r;i++){
            for(auto p:primes){
                if(p>i)break;
                if(i%p==0)ans+=p;
            }
        }
        return ans;
    }
};