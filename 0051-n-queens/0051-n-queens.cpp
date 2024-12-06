class Solution {
//皇后條件：(1)不能同行(2)不能同列(3)不能同斜線
//思路：
private:
    vector<vector<string>> results;

    void backtracking(int qNum, int n, vector<string> &result){
        if(qNum == n){
            results.push_back(result);
            return;
        }
        //逐行放入
        for(int i = 0;i<n;i++){
            int xIndex  = i;
            int yIndex = qNum;
            int trackback = 1;
            bool passFlag = true;
            //檢查
            while(trackback<=n){
                //檢查同列
                if(yIndex-trackback>=0 && result[yIndex-trackback][xIndex] == 'Q'){
                    passFlag = false;
                    break;
                }
                //檢查左上
                if(yIndex-trackback>=0 && xIndex-trackback>=0 && result[yIndex-trackback][xIndex-trackback] == 'Q'){
                    passFlag = false;
                    break;
                }
                //檢查右上
                if(yIndex-trackback>=0 && xIndex+trackback<n && result[yIndex-trackback][xIndex+trackback] == 'Q'){
                    passFlag = false;
                    break;
                }
                trackback++;
            }
            if(!passFlag)continue;
            //放入Q
            result[qNum][i] = 'Q';
            backtracking(qNum+1, n, result);
            result[qNum][i] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        results.clear();
        std::vector<std::string> result(n, std::string(n, '.'));
        backtracking(0, n, result);
        return results;
    }
};