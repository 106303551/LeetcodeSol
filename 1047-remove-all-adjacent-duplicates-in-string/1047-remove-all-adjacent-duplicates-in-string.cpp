class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> stack1;
        string res="";

        for(int i = 0 ;i<s.size();i++){
    
            if(!stack1.empty() && s[i]==stack1.top()){
                stack1.pop();
            }else{
                stack1.push(s[i]);
            }
        }

        while(!stack1.empty()){
            res+=stack1.top();
            stack1.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};