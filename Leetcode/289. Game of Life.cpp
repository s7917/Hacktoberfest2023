class Solution {
public:
int countNeighbours(vector<vector<int>>& board, int row,int col){
    int n=board.size();
    int m=board[0].size();
    int delrow[8]={0,1,0,-1,1,1,-1,-1};
    int delcol[8]={1,0,-1,0,-1,1,1,-1};
    int count=0;
    for(int i=0;i<8;i++){
        int nrow=delrow[i]+row;
        int ncol=delcol[i]+col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1){
            count++;
        }
    }
    return count;
}
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> curr = board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((countNeighbours(curr,i,j)<2 || countNeighbours(curr,i,j)>3) && board[i][j]==1){
                    board[i][j]=0;
                }
                else if(countNeighbours(curr,i,j)==3 && board[i][j]==0){
                    board[i][j]=1;
                }
                else if((countNeighbours(curr,i,j)==2 || countNeighbours(curr,i,j)==3) && board[i][j]==1){
                    board[i][j]=1;
                }
            }
        }
    }
};