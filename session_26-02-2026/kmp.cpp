#include <bits/stdc++.h>
using namespace std;

vector<int> buildlps( const string &pat){
    int m=pat.size();
    vector<int> lps(m,0);
    
    int i=1, j=0;
    while(i<m){
        if(pat[i]==pat[j]){
            j++;
            lps[i]=j;
            i++;
        }else{
            if(j!=0) j=lps[j-1];
            else { lps[i]=0; i++; }
        }
    }
    return lps;
}

int main() {
    string text="acbdabchd"; 
    string pat="abc"; 
    int n=text.size(); int m=pat.size();

    vector<int> lps= buildlps(pat);
    int i=0, j=0;

    while(i<n){
        if(text[i]==pat[j]){
            i++; j++;
        }
        if(j==m){
            cout<< "pattern found at index "<<i-j ;
            j=lps[j-1];
        }
        else if( i<n && text[i]!= pat[j] ){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }

    return 0;
}