class Solution {
public:

    void f(int n, int k, int i, vector<int>&temp, vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<=n; j++){
            temp.push_back(j);
            f(n,k,j+1,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        f(n,k,1,temp,ans);
        return ans;
    }
};
