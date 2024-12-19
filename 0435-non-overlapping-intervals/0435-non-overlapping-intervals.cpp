class Solution {
//思路：(1)確保上限由小到大 同上限的下限由大到小
//     (2)相同上限最多保留一個 確認下一個上限是否overlap上一個下限
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] < b[1])return true;
        if(a[1] == b[1] && a[0]>b[0])return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        if(intervals.size() == 1)return result;
        sort(intervals.begin(),intervals.end(),cmp);
        int upperbound = intervals[intervals.size()-1][1];
        int lowerbound = intervals[intervals.size()-1][0];
        for(int i = intervals.size()-2; i>=0;i--){
            //上限一樣
            if(intervals[i][1] == upperbound){
                lowerbound = intervals[i][0];
                result++;
                continue;
            }
            //下限與上限重疊
            if(intervals[i][1]>lowerbound){
                // if(intervals[i][0]>lowerbound){
                //     upperbound = intervals[i][1];
                //     lowerbound = intervals[i][0];
                // }
                result++;
                continue;
            }
            //完全不重疊
            upperbound = intervals[i][1];
            lowerbound = intervals[i][0];
        }
        return result;
    }
};