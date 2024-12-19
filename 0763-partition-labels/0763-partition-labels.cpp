class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]<b[0])return true;
        return false;
    }
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<vector<int>> intervals(26,vector<int>(2,-1));
        for(int i =0;i<s.size();i++){
            if(intervals[s[i]-'a'][0] == -1){
                intervals[s[i]-'a'][0] = i;
            }else{
                intervals[s[i]-'a'][1] = i;
            }
        }
        sort(intervals.begin(),intervals.end(),cmp);
        int end = intervals[0][1];
        int start = intervals[0][0];
        int counts = s.size();
        for(int i =1; i<intervals.size();i++){
            //沒出現字母的跳過
            if(start == -1){
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            //只有自己一個同時可以切
            if(end == -1){
                result.push_back(1);
                start = intervals[i][0];
                end = intervals[i][1];
                counts--;
                continue;
            }
            if(end>intervals[i][0] && end<intervals[i][1]){
                end = intervals[i][1];
            }
            else if(end<intervals[i][0]){
                result.push_back(end-start+1);
                counts = counts-end+start-1;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if(counts!=0)result.push_back(counts);

        return result;
    }
};