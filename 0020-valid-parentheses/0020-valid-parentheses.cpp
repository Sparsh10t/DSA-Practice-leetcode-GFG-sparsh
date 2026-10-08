class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(auto ch : s){
            if(ch == '(' || ch =='{' || ch == '[') st.push(ch);
            if(ch == ')' || ch =='}' || ch == ']') {
                if(st.size()!=0){
                    char top = st.top();
                    if(ch ==')' && top=='(') st.pop();
                    else if(ch =='}' && top=='{') st.pop();
                    else if(ch ==']' && top=='[') st.pop();
                    else return false;
                }
                else return false;
            }

        }
        return st.empty();
    }
};