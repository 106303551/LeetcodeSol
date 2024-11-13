class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    void backtracking(vector<int>& nums ,int startIndex){
        if(startIndex == nums.size())return;
        for(int i = startIndex ; i<nums.size(); i++){
            result.push_back(nums[i]);
            results.push_back(result);
            backtracking(nums, i+1);
            result.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        results.push_back(result);
        backtracking(nums, 0);
        return results;
    }
};