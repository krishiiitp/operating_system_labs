#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter No. of Processes : ";
    cin>>n;
    double nc;
    nc=n;
    int at[n],bt[n],pt[n];
    vector<int> btc(n);
    cout<<"Enter Arrival Times of Processes : ";
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    cout<<"Enter Burst Times of Processes : ";
    for(int i=0;i<n;i++){
        cin>>bt[i];
        btc[i]=bt[i];
    }
    cout<<"Enter Priority of Processes : "
    for(int i=0;i<n;i++){
        cin>>pt[i];
    }
    int t=0;
    vector<bool> vis(n,false);
    vector<int> wt(n,0);
    vector<int> ganttchart;
    vector<int> ct(n);
    while(true){
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            if(at[i]<=t && vis[i]==false){
                v.push_back({bt[i],i});
            }
        }
        if(v.size()==0){
            int cnd=0;
            for(int i=0;i<n;i++){
                if(vis[i]==false){
                    cnd=1;
                    break;
                }
            }
            if(cnd==1){
                t++;
                continue;
            }else{
                break;
            }
        }
        sort(v.begin(),v.end());
        int srt=v[0].first,ind=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first==srt && pt[v[i].second]<pt[ind]){
                ind=v[i].second;
            }
        }
        ganttchart.push_back(ind+1);
        bt[ind]--;
        if(bt[ind]==0){
            vis[ind]=true;
            ct[ind]=t;
        }
        for(int i=0;i<v.size();i++){
            if(v[i].second!=ind){
                wt[v[i].second]++;
            }
        }
        t++;
    }
    double w=0,a=0;
    cout<<"Gantt Chart : ";
    for(int i=0;i<ganttchart.size();i++){
        cout<<ganttchart[i]<<" ";
    }
    cout<<"\n\n";
    vector<int> tat(n);
    for(int i=0;i<n;i++){
        w+=wt[i];
        tat[i]=btc[i]+wt[i];
        a+=tat[i];
    }
    cout<<"AT\tBT\tP\tWT\tTAT\tCT\n"<<endl;
    for(int i=0;i<n;i++){
        cout<<at[i]<<"\t"<<btc[i]<<"\t"<<pt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<endl;
    }
    cout<<"\n";
    double awt=w/nc,atat=a/nc;
    cout<<"Average Waiting Time : "<<awt<<"\n\n";
    cout<<"Average Turn Around Time : "<<atat;
    return 0;
}

