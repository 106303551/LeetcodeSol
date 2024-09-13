class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;

        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                stack1.push(')');
            }
            else if(s[i]=='{'){
                stack1.push('}');
            } 
            else if(s[i]=='['){
                stack1.push(']');
            }
            else if(stack1.empty() || stack1.top()!=s[i]){
                return false;
            }else{
                stack1.pop();
            }
        }
        return stack1.empty();
    }
};