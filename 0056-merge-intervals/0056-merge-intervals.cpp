class Solution {
public:
    //思路：(1)依下限排序
    //     (2)下限上限重疊就合併
    static bool cmp(vector<int>a, vector<int>b){
        if(a[0]<b[0])return true;
        if(a[0]==b[0] && a[1]>b[1])return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(),cmp);

        int start = intervals[0][0];
        int end = intervals[0][1];
        if(intervals.size()==1)return intervals;
        for(int i = 1; i<intervals.size();i++){
            if(end>=intervals[i][0]){
                if(end<intervals[i][1]){
                    end = intervals[i][1];
                }
                continue;
            }else if(end<intervals[i][0]){
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start,end});

        return result;
    }
};