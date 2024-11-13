class Solution {
private:
    vector<string> result;
    string ans;
    string mappingChar = "adgjmptw";
    void backtracking(string digits, int startIndex){
        //判斷數字對應之起始字母與最終字母
        int mappingIndex = digits[startIndex] - '2';
        char startChar = mappingChar[mappingIndex];
        char endChar;
        if (mappingIndex == 7){
            endChar = 'z'+1;
        }else{
            endChar = mappingChar[mappingIndex+1];
        }

        //到最後一個字母
        if(digits.size() == startIndex+1){
            while(startChar < endChar){
                ans.push_back(startChar);
                result.push_back(ans);
                ans.pop_back();
                startChar+=1;
            }
            return;
        }
        while(startChar < endChar){
            ans.push_back(startChar);
            backtracking(digits,startIndex+1);
            ans.pop_back();
            startChar+=1;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        backtracking(digits,0);
        return result;
    }
};