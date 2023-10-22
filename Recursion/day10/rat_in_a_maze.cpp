    bool safe(int x,int y, vector<vector<int>> &m, int n, vector<vector<int>>visited){
        if(( x >= 0 && x < n ) && ( y >= 0 && y < n ) && visited[x][y]==0  && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m, int n,vector<string>&ans,int x,int y,
    vector<vector<int>>visited,string path){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return ;
        }
        
        visited[x][y]=1;
        
        int newx=x+1;
        int newy=y;
        if(safe(newx,newy,m,n,visited)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        newx=x;
        newy=y-1;
        if(safe(newx,newy,m,n,visited)){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        newx=x;
        newy=y+1;
        if(safe(newx,newy,m,n,visited)){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        newx=x-1;
        newy=y;
        if(safe(newx,newy,m,n,visited)){
            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        
        if(m[0][0]==0){
            return ans;
        }
        
        int srcx=0;
        int srcy=0;
        
        vector<vector<int>>visited=m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        string path="";
        
        solve(m,n,ans,srcx,srcy,visited,path);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }