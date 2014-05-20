#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

long long int ways[30001][5];
int coin[5] = {1,5,10,25,50};

long long now(int x, int y){
    if(y>4) return 0;
    if(x==0) return 1;
    if(x<0) return 0;
    if( ways[x][y] != -1)return ways[x][y];

    ways[x][y] = now(x, y+1) + now(x-coin[y], y);

    return ways[x][y];

}


int main(){
    int inp;
    long long ans;

    memset(ways, -1, sizeof(ways));
    //freopen("in.txt","r",stdin);
    //freopen("out.tx", "w", stdout);
    while(cin>>inp){
        ans = now(inp,0);
        if (ans == 1){
             cout<<"There is only 1 way to produce "<<inp<<" cents change."<<endl;
        } else {
            cout<<"There are "<<ans<<" ways to produce "<<inp<<" cents change."<<endl;

            //There is only 1 way to produce 4 cents change.
        }
    }

    return 0;
}
