#include<bits/stdc++.h>
using namespace std;

int arr[100][100];
int input[100];
vector<int>v;
int row,col;

void Copy(int p)
{
    for(int i=1;i<=row;i++)
    {
        arr[i][p]=arr[i][p-1];
    }
}

int Empty(int p)
{
    for(int i=1;i<=row;i++)
    {
        if(arr[i][p]==-1)return i;
    }
    return 0;
}

void print()
{
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(arr[i][j]==-1)cout<<"E"<<" ";
            else cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void calculation()
{
    int hit=0;
    for(int i=1;i<=col;i++)
    {
        Copy(i);
        int check=Empty(i);
        if(check)arr[check][i]=input[i];
        else
        {
            vector<int>cur;
            int j;
            for(j=1;j<=row;j++)
            {
                if(arr[j][i]==input[i]){hit++;break;}
                cur.push_back(arr[j][i]);
            }
            if(j==row+1)
            {
                for(j=v.size()-1;j>=0;j--)
                {
                    if(cur.size()==1)break;
                    else
                    {
                        int pos=-1;
                        for(int k=0;k<cur.size();k++)
                        {
                            if(cur[k]==v[j]){pos=k;break;}
                        }
                        if(pos!=-1)cur.erase(cur.begin()+pos);
                    }
                }

                for(j=1;j<=row;j++)
                {
                    if(arr[j][i]==cur[0]){arr[j][i]=input[i];break;}
                }
            }

        }
        v.push_back(input[i]);
    }
    cout<<"\n\n\n"<<endl;
    print();
    cout<<"Hit: "<<hit<<endl;
}

int main()
{
    cout<<"Enter the number of Frames: ";cin>>row;
    cout<<"Enter the number of Process: ";cin>>col;
    cout<<"Enter the Processes: ";
    for(int i=1;i<=col;i++)cin>>input[i];
    memset(arr,-1,sizeof(arr));
    calculation();

    return 0;
}
