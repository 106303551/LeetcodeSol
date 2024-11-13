class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    int resultSum = 0;
    void backtracking(vector<int>& candidates, int target, int startIndex){
        //Sum大於等於target時做判斷
        if(resultSum == target){
            results.push_back(result);
            return;
        }else if(resultSum > target){
            return;
        }

        //遍歷candidates
        for(int i = startIndex;i<candidates.size();i++){
            result.push_back(candidates[i]);
            resultSum += candidates[i];
            backtracking(candidates, target, i);
            result.pop_back();
            resultSum -= candidates[i]; 
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return results;
    }
};