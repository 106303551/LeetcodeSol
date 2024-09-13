class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q1;
        vector<int> res;
        for(int i =0;i<nums.size();i++){
            //先排除該踢掉的頭元素
            if(i>=k && !q1.empty() && q1.front() == nums[i-k]){
                q1.pop_front();
            }

            while(!q1.empty() && q1.back()<nums[i]){
                q1.pop_back();
            }
            
            q1.push_back(nums[i]);
            
            if(i<k-1){
                continue;
            }

            res.push_back(q1.front());

        }
        return res;
    }
};