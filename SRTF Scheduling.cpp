
#include<bits/stdc++.h>
using namespace std;
int burst_time[100];
int arrival_time[100];
int waiting_time[100];
int turnaround_time[100];
map<int,int>cnt,res;

void space_fun(int num)
{
    for(int i=1;i<=num;i++)cout<<" ";
}

int check(int st,int num)
{
    int mn=1e5,pos=-1,flag=-2;
    for(int i=1;i<=num;i++){

        if(cnt[i]>0){
            if(arrival_time[i]<=st){
                if(cnt[i]<mn)mn=cnt[i],pos=i;
            }
            flag=0;
        }
    }

    if(flag==-2)return flag;
    return pos;
}

void avg_time(int num_pro)
{
    int total_wait_time=0,starting_time=0,total_turnaround_time=0;
    for(int i=0;    ; i++)
    {
        int ch = check(i,num_pro);
        if(ch==-2)break;
        else if(ch>0){
            res[ch]=i+1;
            cnt[ch]--;
        }
    }

    for(int i=1;i<=num_pro;i++){
        turnaround_time[i]=res[i] - arrival_time[i];
        waiting_time[i]=turnaround_time[i] - burst_time[i];
        total_wait_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }


    cout<<"\n\n\n"<<endl;
    cout<<"Process"<<"   "<<"Burst Time"<<"   "<<"Arrival Time"<<"   "<<"Waiting Time"<<"   "<<"Turnaround Time"<<endl;
    for(int i=1;i<=num_pro;i++)
    {
        cout<<"   "<<i;
        space_fun(10-(int)floor(log10(i) + 1));
        cout<<burst_time[i];
        space_fun(13-(int)floor(log10(burst_time[i]+1) + 1));
        cout<<arrival_time[i];
        space_fun(15-(int)floor(log10(arrival_time[i]+1) + 1));
        cout<<waiting_time[i];
        space_fun(15-(int)floor(log10(waiting_time[i]+1) + 1));
        cout<<turnaround_time[i]<<endl;
    }
    cout<<"\n\n\n"<<endl;

    cout<<"Average Waiting Time: "<<(float)total_wait_time/num_pro<<endl;
    cout<<"Average Turnaround Time "<<(float)total_turnaround_time/num_pro<<endl;
}


int main()
{
    int num_pro;
    cout<<"Number of Process: ";
    cin>>num_pro;
    cout<<"Arrival Times: ";
    for(int i=1; i<=num_pro; i++)
    {
        res[i]=-1;
        cin>>arrival_time[i];
    }
    cout<<"Burst Times: ";
    for(int i=1; i<=num_pro; i++)
    {
        cin>>burst_time[i];
        cnt[i]=burst_time[i];
    }

    avg_time(num_pro);

}
