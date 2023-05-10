#include<iostream>
using namespace std;

int main(){
    int a[100],b[100],x[100];
    int time = 0,end,count = 0,avg=0,tt=0;
    int completionTime[100],WaitTime[100],TAT[100];
    int n;
    cout<<"enter the no of processes"<<endl;
    cin>>n;
    cout<<"enter the arrival and burst time "<<endl;
    for(int i = 0 ; i<n;i++){
        cin>> a[i];
        cin>>b[i];
        
    }
    for(int i =0; i<n;i++){
        x[i]=b[i];
    }
    b[9] = 9999;
    int smallest;
    for(time = 0; count != n; time++){
        smallest = 9;
        for(int j = 0;j<n;j++){
            if(a[j]<=time &&b[smallest]>b[j] && b[j]>0)
                smallest = j;
        }
        cout<<b[smallest]<<" ";
        b[smallest]--;
        if(b[smallest] == 0){
            count += 1;
            end = time+1;
            completionTime[smallest] = end ;
            WaitTime[smallest] = end - a[smallest] -x[smallest];
            TAT[smallest] = end - a[smallest];
        }
    }
    cout<<endl<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time"<<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<WaitTime[i]<<"\t\t"<<TAT[i]<<"\t\t"<<completionTime[i]<<endl;
        avg = avg + WaitTime[i];
        tt = tt + TAT[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<" Average Turnaround time ="<<tt/n<<endl;




}