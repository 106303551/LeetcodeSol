class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    int lastPopElement = 11;
    void backtracking(vector<int>& nums, int startIndex){
        if(startIndex == nums.size())return;
        for(int i = startIndex; i<nums.size(); i++){
            //排除重複
            if(lastPopElement == nums[i]){
                continue;
            }
            result.push_back(nums[i]);
            results.push_back(result);
            backtracking(nums,i+1);
            lastPopElement = result.back();
            result.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        results.push_back(result);
        backtracking(nums, 0);
        return results;
    }
};