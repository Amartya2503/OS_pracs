// #include <iostream>
// using namespace std;
// void selectionSort(int a[], int b[], int n) {
//     int i, j, min, temp, temp2;
//     for (i = 0; i < n - 1; i++) {
//         min = i;
//         for (j = i + 1; j < n; j++){
//             if (a[j] < a[min]){
//                 min = j;
//                 temp = a[i];
//                 temp2 = b[i];
//                 a[i] = a[min];
//                 b[i] = b[min];
//                 a[min] = temp;
//                 b[min] = temp2;
//             }
//         }
        
//     }
// }
// int main()
// {
// int n,a[100],b[100],total,prev_total,t[100],w[100];
// float avg_t=0,avg_w=0;
// cout<<"Number of processes : " ;
// cin>>n;
// cout<<"\nEnter the arrival time and burst time one by one : \n";
// for(int i = 0;i<n;i++){
//  cin>>a[i];
//  cin>>b[i];
// }
// selectionSort(a, b, n);
// total = 0;
// cout<<"\nGantt Chart for FCFS\n";
// cout<<"\nProcces | Start Time | Completion Time | Turnaound Time | Waiting Time";
// for(int i = 0;i<n; i++){
//     prev_total = total;
//     if(total < a[i]){
//     total = a[i];
//     }
//     total = total+b[i];
//     t[i] = total - a[i];
//     w[i] = prev_total - a[i];
//     cout<<"\nP"<<i+1<<"         "<<prev_total;
//     if(prev_total > 9){
//     cout<<"         ";
//     }
//     else{
//     cout<<"         ";
//     }
//     cout<<total;
//     if(total > 9){
//     cout<<"         ";
//     }
//     else{
//     cout<<"         ";
//     }
//     cout<<t[i];
//     if(t[i] > 9){
//     cout<<"         ";
//     }
//     else{
//     cout<<"         ";
//     }
//     cout<<w[i];
//     avg_t = avg_t + t[i];
//     avg_w = avg_w + w[i];
// }
// avg_t = avg_t/n;
// avg_w = avg_w/n;
// cout<<"\nAverage Turnaround Time = "<<avg_t;
// cout<<"\nAverage Waiting Time = "<<avg_w;
// return 0;
// }

#include <iostream>
using namespace std;

void sort(int a[],int b[],int n){
    int i,j,temp1,temp2;
    for(i=0;i<n;i++){
        int min = a[i];
        for(j=i;j<n;j++){
            if(a[j]<min){
                temp1 = a[j];
                a[j] = min;
                a[i]= temp1;
                temp2 =b[j];
                b[j]= b[i];
                b[i]=temp2;

            }
        }
    }
}

int main(){
    int n,total,prev_total,t[100],w[100],avg_t=0,avg_w=0;
    cout<<"enter the number of processes:\t";
    cin>>n;
    int a[n],b[n];
    cout<<"enter the process arrival time and bust time";
    for(int i =0;i<n;i++){
        cin>> a[i];
        cin>> b[i];

    }
    sort(a,b,n);
    total = 0;
    cout<<"the gant chart for the processes is : \n";
    cout<<"process  |  Arrival  |  StartTime  | TAT | Wait time  "<<endl;
    for(int i=0;i<n;i++){
        prev_total = total;
        if(total<a[i]){
            total = a[i];
        }
        total = total + b[i];
        t[i] = total-a[i];
        w[i] = prev_total - a[i];
        cout<<"P"<<i+1<<"       ";
        cout<<a[i]<<"       ";
        cout<<prev_total<<"     ";
        cout<<t[i]<<"       ";
        cout<<w[i]<<"       "<<endl;
        avg_t = avg_t+t[i];
        avg_w = avg_w+w[i];
    }
    avg_t = avg_t/n;
    avg_w = avg_w/n;
    cout<<"average TAT is : "<<avg_t<<endl;
    cout<<"average wait time : "<<avg_w;
    return 0;

}