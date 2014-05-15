#include<iostream>
#include<cmath>
#include<string.h>
#define SIZE 110

using namespace std;

int w[SIZE][SIZE];
int n;
int r;
int tmp;

int MAX(int x, int y){

    if (x<0 && y < 0){
        return -1;
    }
    if(x<0){
        return y;
    }
    if(y<0){
        return x;
    }
    return (x>y)?x:y;
}


int MIN(int x, int y){

/*

*/
    return (x<y)?x:y;
}



void floyed(){
    for (int k = 1; k<= n; k++){
        for (int i = 1; i<=n ; i++){
            for (int j = 1; j<= n; j++){
                    if (i == j){

                        w[i][j] = -1;
                    } else {



                w[i][j] = MAX(w[i][j], MIN(w[i][k], w[k][j]));

                //cout<<"w["<<i<<"]["<<k<<"] : "<<w[i][k]<< ", w["<<k<<"]["<<j<<"] : "<<w[k][j]<<":: result: "<<MIN(w[i][k], w[k][j])<<endl;
                    }
            }
        }



/*

        cout<<"For K : "<<k<<endl;
        for (int m = 1; m<= n; m++){
            for (int o = 1; o<= n; o++){
                cout<<w[m][o]<<" ";
            }
            cout<<endl;

        }
        */

    }
}


int main(){

    int a;
    int b, v, s,d,c;


    int count = 1;

    while (1){
        cin>>n>>r;
        memset(w,-1, sizeof(w));

        if (n==0 && r == 0){
            break;
        }

        for (int i = 1; i<= r; i++){
            cin>>a>>b>>v;
            w[a][b] = v;
            w[b][a] = v;
        }


        cin>>s>>d>>c;

/*
        cout<<"For K : 0"<<endl;
        for (int m = 1; m<= n; m++){
            for (int o = 1; o<= n; o++){
                cout<<w[m][o]<<" ";
            }
            cout<<endl;

        }
        */
        floyed();

        //cout<<w[s][d];
        int ans = 1;

        if (w[s][d] != -1){



            w[s][d]--;

            ans =  c /w[s][d];

            if (c%w[s][d] != 0){
                ans++;
            }
        }

        cout<<"Scenario #"<<count<<endl;
        cout<<"Minimum Number of Trips = "<<ans<<endl;
        /*
        Scenario #1
        Minimum Number of Trips = 5
        */

        count++;


    }
}
