class CombinationIterator {
public:

    string s;
    int n;
    vector<string>ans;
    string temp = "";
    int ptr;

    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = combinationLength;
        f(s,0,temp,n);
        sort(ans.begin(),ans.end());
        ptr = 0;
    }

    void f(string s, int i, string &temp, int n){
        if(i==s.length()){
            if(temp.length()==n){
                ans.push_back(temp);
            }
            return;
        }
        f(s,i+1,temp,n);
        temp.push_back(s[i]);
        f(s,i+1,temp,n);
        temp.pop_back();
    }
    
    string next() {
        return ans[ptr++];
    }
    
    bool hasNext() {
        if(ptr==ans.size()){
            return false;
        }
        return true;
    }
};
