class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int count = 0;
        for(int i = 0;i<s.size();i++){
            //小孩可滿足
            if(count==g.size())return count;
            if(s[i]>=g[count]){
                count++;
            }
        }
        return count;
    }
};