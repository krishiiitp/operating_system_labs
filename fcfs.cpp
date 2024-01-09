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
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
int cnd=0;
int main(){
    int p; //No. of Processes
    cin>>p;
    int at[p];
    int bt[p];
    vector<int> wt(p);
    vector<int> tat(p);
    vector<pair<int,int> > v;
    vector<pair<int,int> > va;
    //Input of Arrvial Time
    for(int i=0;i<p;i++){
        cin>>at[i];
    }
    //Input of Burst time
    for(int i=0;i<p;i++){
        cin>>bt[i];
    }
    for(int i=0;i<p;i++){
        v.push_back(make_pair(at[i],bt[i]));
        va.push_back({at[i],i});
    }
    sort(v.begin(),v.end());
    sort(va.begin(),va.end());
    wt[0]=0;
    int last=wt[0];
    for(int i=1;i<p;i++){
        wt[va[i].second]=v[i-1].second + last;
        last=wt[va[i].second];
    }
    int sumwt=0,sumtat=0;
    for(int i=0;i<p;i++){
        wt[i]-=at[i];
    }
    cout<<"Waiting Time"<<endl;
    cout<<endl;
    for(int i=0;i<p;i++){
        cout<<wt[i]<<" ";
        sumwt+=wt[i];
    }
    cout<<"\n\nTurn Around Time"<<endl;
    cout<<endl;
    for(int i=0;i<p;i++){
        tat[i]=bt[i]+wt[i];
    }
    for(int i=0;i<p;i++){
        cout<<tat[i]<<" ";
        sumtat+=tat[i];
    }
    double awt=sumwt/p,atat=sumtat/p;
    cout<<"\n\nAverage Waiting Time: "<<awt<<endl;
    cout<<"Average Turn Around Time: "<<atat;
////    
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//
    return 0;
}