class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1)return 1;
        //保證x下限小到大
        sort(points.begin(),points.end(),cmp);
        int result = 0;
        int shootPos;
        //因為x下限小到大 由最大的下限開始射保證不會漏掉任何一個
        for(int i = points.size()-1;i>=0;i--){
            result++;
            shootPos = points[i][0];
            while(i>0 && shootPos<=points[i-1][1] && shootPos>=points[i-1][0]){
                i--;
            }
        }
        return result;
    }
};