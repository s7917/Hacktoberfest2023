class Solution {
    private: 
    bool check(int i, int j, string &s){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    } 
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int starting_index=0;
        int max=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    if(j-i+1 > max){
                        max=j-i+1;
                        starting_index=i;
                    }
                }
            }
        }
        return s.substr(starting_index,max);
    }
};