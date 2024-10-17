class Solution {
public:

    void f(string s, int n, int i, set<string>&st, string &temp, vector<string>&ans){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<=i+10 && j<s.size(); j++){
            if(st.find(s.substr(i,j-i+1))!=st.end()){
                string curr = s.substr(i,j-i+1);
                if(temp.size()){
                    temp = temp+" "+curr;
                }
                else{
                    temp = curr;
                }
                f(s,n,j+1,st,temp,ans);
                int len = curr.length();
                while(temp.size() && len--){
                    temp.pop_back();
                }
                if(temp.size() && temp.back()==' '){
                    temp.pop_back();
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<string>ans;
        string temp = "";
        f(s,n,0,st,temp,ans);
        return ans;
    }
};
