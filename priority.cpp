//Code by Krish Thakrar (krish_iiitp)
 
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
/*    ll t;
    cin>>t;
    for(ll z=0;z<t;z++){
        //Code by Krish Thakrar
    } */

    //Priority Scheduling (Without Pre-emption)

    int n;
    cin>>n;
    int a[n],p[n],b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<int> vis(n,0);
    vector<int> wt(n);
    int time=0;
    while(true){
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            if(a[i]<=time && vis[i]==0){
                v.push_back({p[i],i});
            }
        }
        if(v.size()==0){
            bool cnd=true;
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    cnd=false;
                    break;
                }
            }
            if(cnd){
                break;
            }
            time++;
            continue;
        }
        sort(v.begin(),v.end());
        int ind=v[0].second,pri=v[0].first;
        for(int i=1;i<v.size();i++){
            if(v[0].first==pri){
                if(b[v[0].second]<b[ind]){
                    ind=v[0].second;
                }
            }else{
                break;
            }
        }
        wt[v[0].second]=time;
        time+=b[v[0].second];
        vis[v[0].second]=1;
    }
    for(int i=0;i<n;i++){
       wt[i]-=a[i];
    }
    int tat[n];
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+b[i];
    }
    int sumw=0,sumt=0,ct=0;
    double aw,tw;
    cout<<"BT\tAT\tP\tWT\tTAT"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<"\t"<<a[i]<<"\t"<<p[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        sumw+=wt[i];
        sumt+=tat[i];
        ct+=b[i];
    }
    aw=sumw/n,tw=sumt/n;
    cout<<"Average Waiting Time : "<<aw<<"\n\n";
    cout<<"Average Turn Around Time : "<<tw<<"\n\n";
    cout<<"Completion Time : "<<ct;
////    
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//
    return 0;
}
 
//
//8 6 1 7