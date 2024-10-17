class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i=1; i<n; i++){
            int num = ans.back();
            int j = 0;
            while(1<<j<=num){
                j++;
            }
            int sz = ans.size();
            for(int k=sz-1; k>=0; k--){
                ans.push_back(ans[k]+(1<<j));
            }
        }
        return ans;
    }
};
