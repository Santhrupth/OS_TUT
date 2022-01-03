#include <bits/stdc++.h>
#include<vector>
using namespace std;
struct process
{
    int at,bt,ct,st,rt,tat,wt;
};
int main()
{
    vector<int>rq;
    int i,n,ctime=0,tottime=0,q;
    float avgtat=0,avgwt=0,avgrt=0;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter quantum time: ";
    cin>>q;
    process arr[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter arrival time and burst time of P"<<i+1<<": ";
        cin>>arr[i].at>>arr[i].bt;
        tottime+=arr[i].bt;
        arr[i].rt=arr[i].bt;
        arr[i].st=-1;
    }
    int j=0;
    for(i=0;i<n;i++)
    {
        if(arr[i].at<=ctime&&arr[i].rt>0&&arr[i].st==-1)
        {
            arr[i].st=-2;
            rq.push_back(i);
        }
    }
    while(ctime<tottime)
    {
        cout<<ctime<<"    P"<<rq[j]+1<<"  ";
        if(arr[rq[j]].st==-2)
        {
            arr[rq[j]].st=ctime;
        }
        if(arr[rq[j]].rt<=q)
        {
            ctime+=arr[rq[j]].rt;
            arr[rq[j]].rt=0;
            arr[rq[j]].ct=ctime;
        }
        else
        {
            ctime+=q;
            arr[rq[j]].rt-=q;
        }
        cout<<ctime<<endl;
        for(i=0;i<n;i++)
        {
            if(arr[i].at<=ctime&&arr[i].rt>0&&arr[i].st==-1)
            {
                arr[i].st=-2;
                rq.push_back(i);
            }
        }
        if(arr[rq[j]].rt>0)
        {
            rq.push_back(rq[j]);
        }
        j++;
        
    }
    cout<<endl<<endl<<"Process AT\tBT\tCT\tTAT\tWT\tRT"<<endl;
    for(i=0;i<n;i++)
    {
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        arr[i].rt=arr[i].st-arr[i].at;
        cout<<"P"<<i+1<<"\t"<<arr[i].at<<"\t"<<arr[i].bt<<"\t"<<arr[i].ct<<"\t"<<arr[i].tat<<"\t"<<arr[i].wt<<"\t"<<arr[i].rt<<endl;
        avgtat+=arr[i].tat;
        avgwt+=arr[i].wt;
        avgrt+=arr[i].rt;
    }
    cout<<endl<<"Average Turn Around time= "<<(float)avgtat/n<<" units";
    cout<<endl<<"Average Wait time= "<<(float)avgwt/n<<" units";
    cout<<endl<<"Average Response time= "<<(float)avgrt/n<<" units";
    return 0;
}