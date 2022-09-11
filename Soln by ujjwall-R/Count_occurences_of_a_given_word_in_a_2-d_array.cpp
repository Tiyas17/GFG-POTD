class Solution{
    public:
    
    string tt;
    int n,m;
    vector<vector<char> > arr;
    int vis[55][55];
    int ans;
    
    void dfs(int i,int j,string inHand){
        if(i<0||j<0||i>=n||j>=m)return;
        if(vis[i][j]==1)return;
        int l=inHand.length();
        if(l>tt.length())return;
        if(tt[l]==arr[i][j]){
            if(l+1==tt.length()){
                ans++;
                return;
            }
            vis[i][j]=1;
            dfs(i+1,j,inHand+arr[i][j]);
            dfs(i-1,j,inHand+arr[i][j]);
            dfs(i,j+1,inHand+arr[i][j]);
            dfs(i,j-1,inHand+arr[i][j]);
            vis[i][j]=0;
        }
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        tt=target;
        arr=mat;
        n=(int)arr.size();
        m=(int)arr[0].size();
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==target[0]){
                    dfs(i,j,"");
                }
            }
        }
        return ans;
    }
};