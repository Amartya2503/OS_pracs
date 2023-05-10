#include<iostream>
using namespace std;

struct process{
    int id,
        at,
        bt,
        ubt,
        ct,
        wt,
        tat;
}p[100];

int main(){
    int i,n,quanta;
    int timer=0,prev_time,temp_t,temp,total,queue[100];
    float avg_t = 0, avg_w = 0;

    cout<<"enter no. of process :"<<endl;
    cin>>n;
    cout<<"enter time quanta"<<endl;
    cin>>quanta;
    for(i = 0 ; i<n;i++){
        p[i].id =i;
        cout<<"enter at of process p-"<<i+1<<endl;
        cin>>p[i].at ;
        cout<<"enter BT of process p-"<<i+1<<endl;
        cin>>p[i].bt ;
        p[i].ubt = p[i].bt;
        p[i].ct = 0;
        p[i].wt = 0 ;
        p[i].tat = 0;
    }
    p[0].ubt += p[0].at;
    i=0;
    int j = 0;
    timer = 0;
    prev_time =-4;
    total = 0;

    while(j<n){
        for(int l=0;l<n;l++){
            if(p[l].at<=timer){
                if(p[l].at > prev_time){
                    queue[total] = p[l].id;
                    total += 1;
                }
            }
        }
        if(temp_t == timer){
            queue[total]=temp;
            cout<<"\nprocess P-"<<queue[total] <<" pushed at end"<<endl;
            total +=1;
        }

        cout<<"\n"<<timer<<" P-"<<p[queue[i]].id;
        prev_time= timer;

        if(p[queue[i]].ubt <= quanta){

            timer += p[queue[i]].ubt;
            p[queue[i]].ubt -= p[queue[i]].ubt;
            p[queue[i]].ct = timer;
            p[queue[i]].wt = p[queue[i]].ct - p[queue[i]].at - p[queue[i]].bt;
            p[queue[i]].tat = p[queue[i]].ct - p[queue[i]].at;
            cout << "\n Completed P" << p[queue[i]].id << " at " << timer;
            j++;
        }
        else{
            timer += quanta;
            p[queue[i]].ubt -= quanta;
            temp_t = timer;
            temp = p[queue[i]].id;
        }
        i++;
    }
     cout << "\nProcces | Arrival Time | Completion Time | Turnaound Time | Waiting Time ";
    for (int i = 0; i < n; i++)
    {
 
        cout << "\nP" << p[i].id << " " << p[i].at;
        
        cout <<"\t" <<p[i].ct<<"\t";
        cout << "\t"<<p[i].tat<<"\t";
        cout <<"\t" <<p[i].wt<<"\t";
        avg_t = avg_t + p[i].tat;
        avg_w = avg_w + p[i].wt;
    }
    avg_t = avg_t / n;
    avg_w = avg_w / n;
    cout << "\nAverage Turnaround Time = " << avg_t;
    cout << "\nAverage Waiting Time = " << avg_w;
    return 0 ;

}