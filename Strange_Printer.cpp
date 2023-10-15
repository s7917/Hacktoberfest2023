///C++ Code for Strange_Printer
class Strange {
public:
bool dfs(int col,int arr[][4],vector<vector<int>>& grid,int* visited){
    visited[col]=1;
    int t=arr[col][0];
    int r=arr[col][1];
    int b=arr[col][2];
    int l=arr[col][3];
    // cout<<col<<" "<<t<<" "<<b<<" "<<l<<" "<<r<<endl;
    for(int i=t;i<=b;i++){
        for(int j=l;j<=r;j++){
            int x=grid[i][j];
            if(x==col)  continue;
            if(visited[x]==1) return false;
            bool ans=1;
            if(visited[x]==0){
                ans=dfs(x,arr,grid,visited);
            }
            if(ans==0) return 0;
        }
    }
    visited[col]=2;
    return true;
}
    bool isPrintable(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int arr[61][4]; // node->a particular color-> 4 cordinates top right bottom left till which that color is expanded in grid
        int visited[61];
        memset(visited,-1,sizeof(visited));  
        // -1 node not present in grid 
        // 0 node is present but not yet visited
        // 1 node is currently being visited
        // 2 node has already been visited
        // here node is corresponding to ith color
        // and visited is corresponding to being printed
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int col=grid[i][j]; // color
                if(visited[col]==-1){   // color seen for the first time
                    visited[col]=0;
                    arr[col][0]=i;
                    arr[col][1]=j;
                    arr[col][2]=i;
                    arr[col][3]=j;
                }
                else{   //already seen must have some coordinates
                    arr[col][0]=min(i,arr[col][0]);
                    arr[col][1]=max(j,arr[col][1]);
                    arr[col][2]=max(i,arr[col][2]);
                    arr[col][3]=min(j,arr[col][3]);
                }
            }
        }
        bool ans=1;
        for(int i=0;i<61;i++){
            if(visited[i]==-1) continue;
            if(visited[i]==0){
                ans=dfs(i,arr,grid,visited);
                if(ans==0) return false;
            }
        }
        return 1;
    }
};
