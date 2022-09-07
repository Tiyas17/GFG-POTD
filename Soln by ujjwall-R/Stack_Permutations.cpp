int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>st;
        int n=N;
        int j=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&B[j]==st.top()){
                j++;
                st.pop();
            }
            st.push(A[i]);
        }
        while(!st.empty()&&B[j]==st.top()){
                j++;
                st.pop();
        }
        if(st.empty())return 1;
        else return 0;
}