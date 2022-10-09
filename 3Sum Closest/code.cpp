class Solution {
public:
    int threeSumClosest(vector<int>& A, int X) {
        int N=A.size();
        int diff=INT_MAX,ans;
        sort(A.begin(),A.end());
        for(int i=0;i<N;i++)
        {
            int l=i+1,h=N-1;
            while(l<h)
            {
                int sum=A[i]+A[l]+A[h];
                if(abs(sum-X)<diff)
                {
                    diff=abs(sum-X);
                    ans=sum;
                }
                if(sum>X)
                {
                    h--;
                }
                else if(sum<X)
                {
                    l++;
                }
                else{
                    ans=sum;
                    return ans;
                    //break;
                }
            }
        }
        return ans;
    }
};
