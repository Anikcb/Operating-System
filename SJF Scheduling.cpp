#include<bits/stdc++.h>
using namespace std;
int burst_time[100];
int arrival_time[100];
int waiting_time[100];
int turnaround_time[100];
vector<int>v;

void space_fun(int num)
{
    for(int i=1;i<=num;i++)cout<<" ";
}

int check(int st)
{
    int mn=1e5,pos=-1,mn_arr=1e5,result;
    for(int i=0;i<(int)v.size();i++)
    {
        if(arrival_time[v[i]]<=st)
        {
            if(burst_time[v[i]]<mn)mn=burst_time[v[i]],pos=i;
        }
        mn_arr=min(mn_arr,arrival_time[v[i]]);
    }
    if(pos==-1){
        for(int i=0;i<(int)v.size();i++){
            if(arrival_time[v[i]]<=mn_arr)
            {
                if(burst_time[v[i]]<mn)mn=burst_time[v[i]],pos=i;
            }
        }
    }
    result=v[pos];
    v.erase(v.begin()+pos);
    return result;
}

void avg_time(int num_pro)
{
    int total_wait_time=0,starting_time=0,total_turnaround_time=0;
    for(int i=1; i<=num_pro; i++)
    {
        int ch = check(starting_time);

        if(starting_time>arrival_time[ch])
        {
            waiting_time[ch]=starting_time - arrival_time[ch];
            starting_time+=burst_time[ch];
        }
        else
        {
            starting_time+=burst_time[ch];
        }
        turnaround_time[ch]=waiting_time[ch] + burst_time[ch];
        total_wait_time+=waiting_time[ch];
        total_turnaround_time+=turnaround_time[ch];
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
        cin>>arrival_time[i];
        v.push_back(i);
    }
    cout<<"Burst Times: ";
    for(int i=1; i<=num_pro; i++)
    {
        cin>>burst_time[i];
    }

    avg_time(num_pro);

}
