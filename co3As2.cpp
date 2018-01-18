#include<bits/stdc++.h>

using namespace std ;

int prcdnce(char ch)
{
    switch(ch){
        case '+':
        case '-': return 1 ;
        case '*':
        case '/': return 2 ;
        case '^': return 3 ;
        default : return 0 ;
    }
}

int main()
{
    string str ;
    int testCase ;
    stack<char>st ;
    cin>>testCase ;
    while(testCase--){
        cin>>str ;
        for(int i= 0 ;i<str.length() ;i++){
            if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){
                while(!st.empty() && prcdnce(st.top())>=prcdnce(str[i])){
                    cout<<st.top() ;
                    st.pop() ;
                }
                st.push(str[i]) ;
            }
            else if(str[i]=='('){
                st.push(str[i]) ;
            }
            else if(str[i]==')'){
                while(st.top()!='('){
                        cout<<st.top() ;
                        st.pop() ;
                }
                st.pop() ;
            }
            else {
                cout<<str[i] ;
            }
        }
        while(!st.empty()){
            cout<<st.top() ;
            st.pop() ;
        }
        cout<<endl ;
    }
    return 0 ;
}
