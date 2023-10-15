class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        int maxi=0;
        set<char>st;
        while(j<s.length()){
            auto it=st.find(s[j]);
            if(it==st.end()){
                if(j-i+1>maxi) maxi=j-i+1;
                st.insert(s[j]);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};