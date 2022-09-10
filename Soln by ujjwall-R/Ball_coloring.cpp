unsigned long long int noOfWays(unsigned long long int n){
    unsigned long long int ans=2;
    ans+=2*(n-1);
    ans+=(n-2)*(n-1);
    return ans;
}