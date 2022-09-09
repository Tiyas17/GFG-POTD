string digitsNum(int N){
	string ans="";
    int nines=N/9;
	int pre=N%9;
	if(pre)ans+=to_string(pre);
    while(nines--)ans+='9';
	while(N--)ans+='0';
    return ans;
}