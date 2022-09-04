int smallestSumSubarray(vector<int>& a){
      int n=(int)a.size();
      int ans=-1e9;
      int s1=0;
      for(int i=0;i<n;i++){
          int temp=-a[i];
          s1+=temp;
          ans=max(ans,s1);
          if(s1<0)s1=0;
      }
      return -ans;
}