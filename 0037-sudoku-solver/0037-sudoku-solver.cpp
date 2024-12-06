class Solution {
private:
    bool resultFlag = false;
    bool isvalid(int xIndex, int yIndex, char num, vector<vector<char>>& board){
        //檢查同row
        for(int i = 0;i<9;i++){
            if(board[yIndex][i] == num){
                return false;
            }
        }
        //檢查同column
        for(int i = 0; i<9; i++){
            if(board[i][xIndex] == num){
                return false;
            }
        }
        //檢查同九宮格
        int startX = xIndex-(xIndex%3);
        int startY = yIndex-(yIndex%3);
        for(int i = startY;i<startY+3;i++){
            for(int j = startX;j<startX+3;j++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }

    void backtracking(int xIndex, int yIndex, vector<vector<char>>& board){
        //y軸遞增(row)
        for(int j = yIndex;j<board.size();j++){
            //沿x軸遞增(col)
            for(int i = xIndex;i<board[j].size();i++){
                if(board[j][i] == '.'){
                    //檢查 1~9
                    for(char k = '1';k<='9';k++){
                        if(isvalid(i,j,k,board)){
                            board[j][i] = k;
                            backtracking(0,0,board);
                            if(resultFlag){
                                return;
                            }
                            board[j][i] = '.';
                        }
                    }
                    return;
                }
            }
        }
        //走完一遍都沒加數字
        resultFlag = true;
        return;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(0,0, board);
    }
};