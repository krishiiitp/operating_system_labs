//Code by Krish Thakrar

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
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
int main(){
    int p; //No. of Processes
    cin>>p;
    int at[p];
    int bt[p];
    vector<int> wt(p);
    vector<int> tat(p);
    //Input of Arrvial Time
    for(int i=0;i<p;i++){
        cin>>at[i];
    }
    //Input of Burst time
    for(int i=0;i<p;i++){
        cin>>bt[i];
    }
    int t=0;
    int cnt=0;
    int last=0;
    map<int,int> mm;
    int sumwt=0,sumtat=0;
    while(cnt<p){
        vector<int> indx;
        for(int i=0;i<p;i++){
            if(at[i]<=t){
                if(mm.size()==0 || mm.find(i)==mm.end()){
                    indx.push_back(i);
                }
            }
        }
        if(indx.size()==0){
            t++;
            continue;
        }
        vector<pair<int,int> > v;
        for(int i=0;i<indx.size();i++){
            v.push_back({bt[indx[i]],indx[i]});
        }
        sort(v.begin(),v.end());
        wt[v[0].second]=last;
        mm[v[0].second]=1;
        last+=v[0].first;
        cnt++;
        t+=v[0].first;
    }
    cout<<"Waiting Time\n"<<endl;
    for(int i=0;i<p;i++){
        wt[i]-=at[i];
    }
    for(int i=0;i<p;i++){
        cout<<wt[i]<<" ";
        sumwt+=wt[i];
    }
    for(int i=0;i<p;i++){
        tat[i]=wt[i] + bt[i];
    }
    cout<<"\n\nTurn Around Time\n"<<endl;
    for(int i=0;i<p;i++){
        cout<<tat[i]<<" ";
        sumtat+=tat[i];
    }

    double awt=sumwt/p,atat=sumtat/p;
    cout<<"\n\nAverage Waitig Time: "<<awt<<endl;
    cout<<"\nAverage Turn Around Time: "<<atat;    
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    return 0;
}