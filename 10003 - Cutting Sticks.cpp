// Running time : 0.322 sec

#include<iostream>
#include<string.h>
#define SIZE 100

using namespace std;

int x[SIZE];
int inpSize;
int ans[SIZE][SIZE];

int MIN(int i, int j){
    if (i>j){
        return j;
    }
    return i;
}

int Cut(int s, int e){
    if(e-s <= 1){
        return 0;
    }

    if (ans[s][e] != -1){
        return ans[s][e];
    }

    int MinCost = 9999999999;
    int cost;
    for (int i = s+1; i< e; i++ ){
        cost =  Cut(s,i)+ Cut(i, e) + (x[e] - x[s]);
        //cout<<cost<<endl;
        if (cost<MinCost){
            MinCost = cost;
        }
    }

    ans[s][e] = MinCost;
    return MinCost;

}



int main(){
    int total;
    int looP;

    x[0] = 0;


    while(1){


        memset(ans,-1,sizeof(ans));


        cin>>total;

        if (total == 0){
            break;
        }

        cin>>looP;
        for (int i=1; i<= looP; i++){
            cin>>x[i];
        }



        x[looP+1] = total;
        inpSize = looP+1;



        cout<<"The minimum cutting is "<<Cut(0, inpSize)<<"."<<endl;


    }


}
