class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        stack<int> st;
        int n=S.length();
        for(int i=0;i<=n;i++){
            st.push(i+1);
            if(S[i]=='I' || i==n){
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};
