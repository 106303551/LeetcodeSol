class Solution {
    vector<vector<int>> results;
    vector<int> result;
    
    void backtracking(vector<int>& nums, int startIndex){
        std::unordered_set<int> uset;
        if(result.size()>1){
            results.push_back(result);
        }
        for(int i = startIndex; i<nums.size(); i++){
            if((result.size() == 0) || (result.size()>=1 && result.back()<=nums[i])){
                //element已存在就跳過
                if(uset.find(nums[i]) != uset.end()){
                    continue;
                }
                uset.insert(nums[i]);
                result.push_back(nums[i]);
                backtracking(nums, i+1);
                result.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return results;
    }
};