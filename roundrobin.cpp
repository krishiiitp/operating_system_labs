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
ll mod=998244353;
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
int main(){
/*    fillFactorial();*/
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("cpoutput.txt","w",stdout);
    #endif //ONLINE_JUDGE
/*    ll t;
    cin>>t;
    for(ll h=0;h<t;h++){
        //Code by Krish Thakrar
        
    } */

    //Round Robin Scheduling

    int n;
    cin>>n;
    int bt[n],at[n];
    int btc[n];
    for(int i=0;i<n;i++){
        cin>>bt[i];
        btc[i]=bt[i];
    }
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    int tq;
    cin>>tq;
    vector<int> comp(n,0);
    vector<int> gc;
    int time=0;
    vector<int> wt(n,0);
    vector<int> ct(n,0);
    int pt=0;
    int last=-1;
    while(true){
        int cnd=0;
        for(int i=0;i<n;i++){
            if(comp[i]==0){
                cnd=1;
                break;
            }
        }
        if(cnd==0){
            break;
        }
        int start=last+1;
        int ncd=0;
        while(start<n){
            if(at[start]<=time && comp[start]==0){
                ncd=1;
                if(bt[start]<=tq){
                    time+=bt[start];
                    ct[start]=time;
                    for(int i=0;i<n;i++){
                        if(i!=start && comp[i]==0 && at[i]<=time){
                            wt[i]+=bt[start];
                        }
                    }
                    bt[start]=0;
                    comp[start]=1;
                }else{
                    time+=tq;
                    bt[start]-=tq;
                    for(int i=0;i<n;i++){
                        if(i!=start && comp[i]==0 && at[i]<=time){
                            wt[i]+=tq;
                        }
                    }
                }
                last=start;
                break;
            }
            start++;
        }
        start=0;
        while(start<n && ncd==0){
            if(at[start]<=time && comp[start]==0){
                if(bt[start]<=tq){
                    time+=bt[start];
                    ct[start]=time;
                    for(int i=0;i<n;i++){
                        if(i!=start && comp[i]==0 && at[i]<=time){
                            wt[i]+=bt[start];
                        }
                    }
                    bt[start]=0;
                    comp[start]=1;
                }else{
                    time+=tq;
                    bt[start]-=tq;
                    for(int i=0;i<n;i++){
                        if(i!=start && comp[i]==0 && at[i]<=time){
                            wt[i]+=tq;
                        }
                    }
                }
                last=start;
                break;
            }
            start++;
        }
        gc.push_back(last+1);
    }
    cout<<"Gantt Chart : ";
    for(int i=0;i<gc.size();i++){
        cout<<gc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        wt[i]-=at[i];
    }
    vector<int> tat(n,0);
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+btc[i];
    }
    double twt=0,ttat=0;
    for(int i=0;i<n;i++){
        twt+=wt[i];
        ttat+=tat[i];
    }
    double awt,atat;
    awt=twt/n;
    atat=ttat/n;
    cout<<"BT\tAT\tWT\tTAT\t CT"<<endl;
    for(int i=0;i<n;i++){
        cout<<btc[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t "<<ct[i]<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting Time : "<<awt<<endl;
    cout<<"\nAverage Turn Around Time : "<<atat;
////    
///*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//
    return 0;
}
//589253743
//
//8 6 1 7
