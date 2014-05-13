// Runtime : 0.046 sec

#include<iostream>
#include<string.h>
#define SIZE 1000


using namespace std;

string s;

int mem[SIZE][SIZE];

int MIN(int i, int j){
    if (i<=j){
        return i;
    }
    return j;

}

int PolVal(int i, int j){
    int ans = 0;

    if (j-i<1){

        return 0;
    }

    if (mem[i][j] != -1){
        return mem[i][j];
    }

    if (s[i]==s[j]){
        ans = PolVal(i+1, j-1);
    } else {
        ans =  1+MIN(PolVal(i+1,j),MIN(PolVal(i,j-1),PolVal(i+1,j-1)));

    }

    mem[i][j] = ans;

    return ans;


}

int main(){
    int c,j;

    cin>>c;
    int m = 1;
    while (c--){
        memset(mem,-1,sizeof(mem));
        cin>>s;
        j = s.length();
        cout<<"Case "<<m<<": "<< PolVal(0, j-1)<<endl;
        //Case 1: 5
        m++;
    }
}

