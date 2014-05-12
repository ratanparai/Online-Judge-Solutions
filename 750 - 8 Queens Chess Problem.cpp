// Runtime : .013 

#include<iostream>
#include<cmath>


using namespace std;

// result array list
int x[8];
int val;
int cols;
int position;
int solNo;


void writeAns(){
    for (int i=1; i<=8; i++){
        cout<<" "<<x[i];
    }
    cout<<endl;
}

int abs(int a, int b){
    if (a>b){
        return a-b;
    }
    return b-a;
}


/**
 * Check if the combination is valid or not, where k is the
 * cols number and i is the row number.
 */
bool Place (int k, int i){

    for (int j=1; j<k; j++){
        if((x[j] == i) || ( abs(x[j], i) == abs(k, j) ) ) {
            return false;
        }
    }
    return true;

}


void Queens(int k){

    for(int j=1; j<=8; j++){

        if (cols == k && position != j ){
            continue;
        }

        if (Place(k,j)){
            x[k] = j;


            if (k==8){

                if (solNo < 10){
                    cout<<" ";
                }
                cout<<solNo<<"     ";
                solNo++;
                writeAns();
            } else {
                Queens(k+1);
            }
        }
    }

}

int main(){
    int c;
    cin>>c;
    bool blank = false;

    for (int i=1; i<= c; i++) {
        cin>>position;
        cin>>cols;
        if(blank){
            cout<<endl;
        }

        blank = true;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        solNo = 1;
        if (position<=8 && position>0 && cols <=8 && cols > 0){
            Queens(1);
        }
        //cout<<endl;
    }

    return 0;
}

/*
SOLN       COLUMN
 #      1 2 3 4 5 6 7 8

 1      1 5 8 6 3 7 2 4
 2      1 6 8 3 7 4 2 5
 3      1 7 4 6 8 2 5 3
 4      1 7 5 8 2 4 6 3
 */
