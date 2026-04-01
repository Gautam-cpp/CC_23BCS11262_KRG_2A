#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    unordered_set<string> dict;
    string s;
    
    for(int i=0;i<n; i++) {
        cin>>s;  dict.insert(s);
    }
    while(m--){
        cin>>s;
        bool found=false;
        for(int i=0; i<s.length(); i++) {
            char original = s[i];
            for(char c = 'a'; c <= 'c'; c++) {
                if(c == original) continue;
                s[i] = c;
                if(dict.count(s)) {
                    found = true;
                    break;
                }
            }
            s[i] = original;
            if(found) break;
        }
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}