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

    int n;
    cin>>n;
    int bt[n],at[n],p[n];
    int btc[n];
    for(int i=0;i<n;i++){
        cin>>bt[i];
        btc[i]=bt[i];
    }
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<int> gc;
    vector<int> comp(n,0);
    int time=0;
    vector<int> wt(n,0);
    vector<int> tat(n);
    while(true){
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            if(at[i]<=time && comp[i]==0){
                v.push_back({p[i],i});
            }
        }
        if(v.size()==0){
            int cnd=0;
            for(int i=0;i<n;i++){
                if(comp[i]==0){
                    cnd=1;
                    break;
                }
            }
            if(cnd==0){
                break;
            }else{
                time++;
                continue;
            }
        }
        sort(v.begin(),v.end());
        int ind=1,pos=v[0].second;
        while(ind<v.size() && v[ind].first==v[0].first){
            if(bt[pos]>bt[v[ind].second]){
                pos=ind;
            }
            ind++;
        }
        if(gc.size()==0){
            gc.push_back(pos+1);
        }else if(gc[gc.size()-1]!=pos+1){
            gc.push_back(pos+1);
        }
        for(int i=0;i<v.size();i++){
            if(v[i].second!=pos){
                wt[v[i].second]++;
            }
        }
        bt[pos]--;
        if(bt[pos]==0){
            comp[pos]=1;
        }
        time++;
    }
    cout<<"Gantt Chart : ";
    for(int i=0;i<gc.size();i++){
        cout<<gc[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
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
    cout<<"BT\tAT\tP\tWT\tTAT"<<endl;
    for(int i=0;i<n;i++){
        cout<<bt[i]<<"\t"<<at[i]<<"\t"<<p[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
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
