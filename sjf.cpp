#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}

void arrangeTime(int n, int a[][5]){
    for(int i = 0; i<n;i++){
        for (int j = 0; j<n-i+1;j++){
            if(a[1][j]>a[1][j+1]){
                for(int k = 0; k<5;k++){
                    swap(a[k][j],a[k][j+1]);
                }
            }
        }
    }
}
void CompleteTime(int n, int p[][5]){
    int val;
    p[3][0] = p[1][0]+p[2][0];
    p[5][0] = p[3][0]-p[1][0];
    p[4][0] = p[5][0]-p[2][0];
    for(int i=1;i<n;i++){
        int temp = p[3][i-1];
        int low = p[2][i];
        for(int j = i;j<n;j++){
            if(temp >= p[1][j] && low >= p[2][j]){
                low = p[2][j];
                val = j;
            }
        }
        p[3][val] = temp + p[2][val];
        p[5][val] = p[3][val] - p[1][val];
        p[4][val] = p[5][val] - p[2][val];
        
        for(int k = 0;k<5;k++){
            swap(p[k][val],p[k][i]);
        }

    }

}

// in array 1 -> Arr time
        //  2 -> burstTime
        //  3 -> completionTime
        //  4 -> waitTime
        //  5 -> TAT

int main(){
    int n,t[100],w[100];
    float avg_t=0,avg_w=0,sys_time=0,comp=0;
    cout<<"enter no. of processes"<<endl;
    cin>>n;
    int  a[5][5];
    cout<<"enter the ArrTime BT sequentially :"<<endl;
    for(int i = 0 ; i<n;i++){
        cin>>a[1][i];
        cin>>a[2][i];
    }
    arrangeTime(5,a);
    CompleteTime(5,a);
    cout<<"\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0; i<n; i++) {
        cout<<a[0][i]<<"\t\t"<<a[1][i]<<"\t\t"<<a[2][i]<<"\t\t"<<a[4][i]<<"\t\t"<<a[5][i]<<"\n";
        avg_t = avg_t + a[5][i];
        avg_w = avg_w + a[4][i];
    }
    avg_t = avg_t/n;
    avg_w = avg_w/n;
    cout<<"\nAverage Turnaround Time = "<<avg_t;
    cout<<"\nAverage Waiting Time = "<<avg_w;
    return 0;
}

