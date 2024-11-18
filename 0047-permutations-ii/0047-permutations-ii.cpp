class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    int hashTable[8] = {0,0,0,0,0,0,0,0};
    void backtracking(vector<int>& nums){
        if(result.size() == nums.size()){
            results.push_back(result);
            return;
        }
        std::unordered_set<int> uset;

        for(int i = 0; i<nums.size(); i++){
            //使用過此element pruning
            if(uset.find(nums[i]) != uset.end() || hashTable[i] == 1){
                continue;
            }
            uset.insert(nums[i]);
            hashTable[i] = 1;
            result.push_back(nums[i]);
            backtracking(nums);
            result.pop_back();
            hashTable[i] = 0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking(nums);
        return results;
    }
};