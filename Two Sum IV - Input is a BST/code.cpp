class Solution {
public:
    void inorderBST(vector<int> &arr, TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorderBST(arr,root->left);
        arr.push_back(root->val);
        inorderBST(arr,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorderBST(arr,root);
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum>k)
            {
                j--;
            }
            else if(sum<k)
            {
                i++;
            }
            else
                return true;
        }
        return false;
        
    }
};
