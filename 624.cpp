#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int d[25][500];
int track[25];
int keep[25][500];

int max(int a, int b){
    return a>=b? a : b;
}

int printTrack(int a, int b){
    if (a<=0 || b<=0){
        return 0;
    }
    if(keep[a][b] == 1) {
        printTrack(a-1, b-track[a]);
        cout<<track[a]<<" ";
    } else {
        printTrack(a-1, b);
    }

}

int main() {

    int N;
    int trackNumber;
    int temp;
    int maximum;


    while (cin>>N){

        memset(keep, 0, sizeof(keep));

        cin>>trackNumber;

        for (int i = 1; i<= trackNumber; i++){
            cin>>track[i];
        }

        for (int j = 1; j<=trackNumber; j++){
            for (int i=1; i<=N; i++){
                temp = (track[j]<=i) ? track[j]+d[j-1][i-track[j]] : 0;
                maximum = max(d[j][i-1], d[j-1][i]);
                if (maximum <= temp){
                    keep[j][i] = 1;
                    d[j][i] = temp;
                } else {
                    d[j][i] = maximum;
                }

            }
        }

        printTrack(trackNumber, N);

        cout<<"sum:"<<d[trackNumber][N]<<endl;


    }

    return 0;
}
