class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    int resultSum;
    int lastPopElement;
    void backtracking(vector<int>& candidates, int target, int startIndex){
        //result>=target 做判斷
        if(resultSum>target){
            return;
        }else if(resultSum == target){
            results.push_back(result);
            return;
        }
        //遍歷candidates
        for(int i = startIndex; i<candidates.size(); i++){
            //前面有一樣的element被pop
            if(lastPopElement == candidates[i]){
                continue;
            }
            result.push_back(candidates[i]);
            resultSum += candidates[i];
            backtracking(candidates, target, i+1);
            lastPopElement = result.back();
            result.pop_back();
            resultSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());  
        backtracking(candidates, target, 0);
        return results;
    }
};