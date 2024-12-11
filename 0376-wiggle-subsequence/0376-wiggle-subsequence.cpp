class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diffs;
        int prevIndex = 0;
        int result = 0;
        int diff = 0;
        for(int i = 1;i<nums.size();i++){
            //計算差值
            diff = nums[i]-nums[i-1];
            diffs.push_back(diff);
            //[16,-12,5,3,2,-5,11,-8]
        }
        while(prevIndex<diffs.size() && diffs[prevIndex] == 0){
            prevIndex++;
        }
        for(int i = prevIndex+1;i<diffs.size();i++){
            if(diffs[prevIndex]>0 && diffs[i]<0){
                result++;
                prevIndex = i;
            }else if(diffs[prevIndex]<0 && diffs[i]>0){
                result++;
                prevIndex = i;
            }
            
        }
        if(prevIndex == diffs.size()){
            return 1;
        }else{
            return result+2;
        }
    }
};