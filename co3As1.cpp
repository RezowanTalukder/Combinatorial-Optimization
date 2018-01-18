#include<bits/stdc++.h>

using namespace std ;

int main()
{
    stack<char>st ;
    int n ;
    cin>>n ;
    while(n--)
    {

        string str ;
        cin>>str ;
        int len = str.length() ;
        for(int i=0 ;i<len ;i++){
            if(str[i]=='(' || str[i]=='['){
                    st.push(str[i]) ;
            }
            else if(str[i]==')'){
                char ch = st.top() ;
                if(ch=='('){
                    st.pop() ;
                }
                else {
                    cout<<"No" ;
                    break ;
                }
            }
            else if(str[i]==']'){
                char ch = st.top() ;
                if(ch=='['){
                    st.pop() ;
                }
                else {
                    cout<<"No" ;
                    break ;
                }
            }
        }
        if(st.empty())cout<<"Yes" ;
        cout<<endl ;

        while(!st.empty()){
            st.pop();
        }

    }
    return 0 ;
}
