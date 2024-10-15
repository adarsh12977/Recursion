class Solution {
public:

    void f(vector<int>&nums, int n, int i, vector<int>&temp, vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            swap(temp[i],temp[j]);
            f(nums,n,i+1,temp,ans);
            swap(temp[i],temp[j]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp = nums;
        vector<vector<int>>ans;
        f(nums,n,0,temp,ans);
        return ans;
    }
};
