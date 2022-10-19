bool comp(pair<int, int>&p1, pair<int, int>& p2){
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<pair<int,int>> store;
        for(auto it:freq)
        {
            store.push_back(make_pair(it.first, it.second));
        }
        sort(store.begin(),store.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(store[i].first);
        }
        return ans;
    }
};
