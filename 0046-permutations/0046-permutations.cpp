class Solution {
private:
    vector<vector<int>> results;
    vector<int> result;
    int hashTable[6] = {0,0,0,0,0,0};
    void backtracking(vector<int>& nums){
        //全部element已放入result
        if(result.size() == nums.size()){
            results.push_back(result);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            //未使用過此元素
            if(hashTable[i] == 0){
                hashTable[i] = 1;
                result.push_back(nums[i]);
                backtracking(nums);
                hashTable[i] = 0;
                result.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int hashTable[6] = {0,0,0,0,0,0};
        backtracking(nums);
        return results;
    }
};