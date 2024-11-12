class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int pathSum;
    void backtracking(int k ,int n ,int startIndex){
        if(pathSum>=n){
            return;
        }  
        //決定加入result時間點
        if(k-path.size() == 1){
            if(n-pathSum>=startIndex && n-pathSum<=9){
                path.push_back(n-pathSum);
                result.push_back(path);
                path.pop_back(); //撤掉最後一個node
            }
            return;
        }
        //for迴圈 檢查有無可能出現解之可能
        
        for(int i = startIndex; i<=9 - (k-path.size())+1; i++){
            path.push_back(i);
            pathSum+=i;
            backtracking(k,n,i+1);
            path.pop_back();
            pathSum-=i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k , n , 1);
        return result;
    }
};