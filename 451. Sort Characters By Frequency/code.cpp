bool comp(pair<char,int> &p1, pair<char,int> &p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        vector<pair<char,int>> v;
        for(auto it:freq)
        {
            v.push_back(make_pair(it.first,it.second));
        }
        sort(v.begin(),v.end(),comp);
        string k="";
        for(int i=0;i<v.size();i++)
        {
            while(v[i].second>0){
            k.push_back(v[i].first);
            v[i].second--;
            }
        }
        return k;
        
    }
};
