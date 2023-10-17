class Solution {
public:
    void helper(vector<string>&ans,int o,int c,string s){
        if(o==0 && c==0){
            ans.push_back(s);
        }
        if(o>0){
            s.push_back('(');
            helper(ans,o-1,c,s);
            s.pop_back();
        }
        if(c>0){
            if(o<c){
                s.push_back(')');
                helper(ans,o,c-1,s);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        helper(ans,n,n,s);
        return ans;
    }
};
