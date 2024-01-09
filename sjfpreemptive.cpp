//Code by Krish Thakrar (MIS: 112115076)
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
#include<cmath>
#include<deque>
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int> >
#define vll vector<long long int>
#define pll pair<long long int,long long int>
#define all(x) x.begin(),x.end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll mod=1e9 + 7;
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("cpoutput.txt","w",stdout);
    #endif //ONLINE_JUDGE

    //Shortest Job First: Pre-emptive

    //Enter Number of Processes
    int n;
    cin>>n;

    //Enter Arrival Times of all the processes
    int at[n];
    for(int i=0;i<n;i++){
        cin>>at[i];
    }

    //Enter Burst Times of all the processes
    int bt[n],btc[n];
    for(int i=0;i<n;i++){
        cin>>bt[i];
        btc[i]=bt[i];
    }
    int wt[n],tat[n];
    int t=0;
    queue<int> mq;
    while(true){
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            if(at[i]<=t && bt[i]>0){
                v.push_back({bt[i],i});
            }
        }
        if(v.size()==0){
            break;
        }
        sort(v.begin(),v.end());
        bt[v[0].second]--;
        t++;
        mq.push(v[0].second+1);
        v.clear();
    }
    int cnt=0;
    map<int,vector<int> > mm;
    int ct[n];
    while(!mq.empty()){
        mm[mq.front()].push_back(cnt);
        mq.pop();
        cnt++;
    }
    map<int,vector<int> > ::iterator it;
    for(it=mm.begin();it!=mm.end();it++){
        vector<int> temp;
        temp=(*it).second;
        int pos=(*it).first;
        int ans=0;
        ct[pos-1]=temp[temp.size()-1]+1;
        ans+=temp[0];
        for(int i=0;i<temp.size()-1;i++){
            ans+=(temp[i+1]-temp[i]-1);
        }
        wt[pos-1]=ans;
    }
    for(int i=0;i<n;i++){
        wt[i]-=at[i];
    }
    for(int i=0;i<n;i++){
        tat[i]=btc[i]+wt[i];
    }
    cout<<"Process Arrival Burst WT TAT CT"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"       "<<at[i]<<"        "<<btc[i]<<"    "<<wt[i]<<"  "<<tat[i]<<"  "<<ct[i]<<endl;
    }
    int sumwt=0,sumtat=0;
    for(int i=0;i<n;i++){
        sumwt+=wt[i];
        sumtat+=tat[i];
    }
    cout<<endl;
    double ans1=sumwt/n,ans2=sumtat/n;
    cout<<"Average Waiting Time: "<<ans1<<endl;
    cout<<"Average Turn Around Time: "<<ans1<<endl;

////    
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//
    return 0;
}
 
//
//8 6 1 7