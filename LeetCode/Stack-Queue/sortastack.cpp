class Solution {
public:
void inserts(stack<int> &st,int num)
{
    if(st.empty() || st.top()<=num)
    {
        st.push(num);
    }
    else{
    int top=st.top();
    st.pop();
    inserts(st,num);
    st.push(top);
}}

    void sortStack(stack<int> &st) {
    if(st.empty()) return;
    int num=st.top();
    st.pop();
    sortStack(st);
    inserts(st,num);
    }
};
