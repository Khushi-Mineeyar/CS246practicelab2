#include <bits/stdc++.h>
#include <iterator>
#define vpll vector<pll>
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define vll vector<ll>
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define M1 1000000007
#define mod 1000000007
#define lp(i,n)  for(ll i=0; i<n; i++)
//#define vpll vector<pair<ll,ll>>
 
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
  int sti(string s){
     int n=0;
     int m=1;
     for(int i=0; i<s.length(); i++){
         n=n+((s[s.length()-1-i]-'0')*m);
         m=m*10;
     }
     return n;
 }
int main()
{
     fast();
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    ll d,b; cin>>d>>b;
    ll gd=d;
    map<ll,vector<ll>> m;
    ll k=pow(2,d)-1;
    vector<ll> a;
    vector<ll> de;
    for(ll i=0; i<=k; i++){
        vector<ll> v;
        m[i]=v;
        a.pb(i);
        de.pb((ll)d);
    }
    string s;

    while(getline(cin,s)){
        string t;
        t=s.substr(0,1);
        int z=sti(t);
        if(z==2 || z==3 || z==4){
            t=s.substr(2);
            int y=sti(t);
          //cout<<y<<endl;
            if(z==2){
                for(int i=a.size()-1; i>-1; i--){
                   ll fe=pow(2,de[i]);
                  // cout<<y-a[i]<<(y-a[i]%fe)<<endl;
                    if((y^a[i])%fe==0){
                        int gg=0;
                        vector<ll> v=m[a[i]];
                        for(ll g=0; g<v.size(); g++){
                            if(v[g]==y){
                               gg=1;
                               break;
                            }
                        }
                        if(gg==1){
                            break;
                        }
                        if(v.size()<b){
                         //   cout<<"yo";
                            v.pb(y);
                            m[a[i]]=v;
                            break;
                        }
                        else{
                          while(1){
                            int j=a[i];
                            int c=de[i];
                            de[i]++;
                            //cout<<pow(2,c-1)+a[i]<<endl;
                            a.pb(pow(2,c)+a[i]);
                            de.pb(c+1);
                            vector<ll> v1;
                            vector<ll> v2;
                            for(int j=0; j<v.size(); j++){
                                ll fg=pow(2,de[a.size()-1]);
                                //cout<<v[j]<<a[a.size()-1]<<fg<<endl;
                                if( (v[j]^a[a.size()-1])%fg==0){
                                    v1.pb(v[j]);
                                }
                                else{
                                    v2.pb(v[j]);
                                }
                            }
                            m[a[a.size()-1]]=v1;
                            m[a[i]]=v2;
                           // cout<<v1.size()<<v2.size()<<a[i]<<a[a.size()-1]<<endl;
                             ll fg=pow(2,de[i]);
                            // cout<<fg<<"yp"<<endl;
                            if( (y-a[i])%fg){
                                vector<ll> vc= m[a[a.size()-1]];
                                if(vc.size()<b){
                                    vc.pb(y);
                                    m[a[a.size()-1]]=vc;
                                    break;
                                }
                            }
                            else{
                                vector<ll> vc= m[a[i]];
                                if(vc.size()<b){
                                    vc.pb(y);
                                    m[a[i]]=vc;
                                    break;
                                }

                            }

                          }
                          break;
                        }
                    }
                }
            }
            if(z==4){
               for(ll e=a.size()-1; e>-1; e--){
                   ll fd=pow(2,de[e]);
                   if((a[e]^y)%fd==0){
                       vector<ll> v3=m[a[e]];
                       for(ll f=0; f<v3.size(); f++){
                            if(v3[f]==y){
                                v3.erase(v3.begin()+f);
                                break;
                            }
                       }
                         m[a[e]]=v3;
                       break;
                   }
               }
            }
        }
        if(z==5){
           // cout<<"hi=";
            vector<vector<ll>> ans;
            for(int i=0; i<a.size(); i++){
                gd=max(gd,de[i]);
                vector<ll> jj;
               // cout<<a[i]<<endl;
                vector<ll> jjj=m[a[i]];
                for(ll kk=0; kk<jjj.size(); kk++){
                  //  cout<<jjj[kk]<<" ";
                }
               // cout<<endl;
                jj.pb(m[a[i]].size());
                jj.pb(de[i]);
                ans.pb(jj);
            }
            cout<<gd<<endl;
            cout<<ans.size()<<endl;
            for(int i=0; i<ans.size(); i++){
                 vector<ll> jj=ans[i];
                 cout<<jj[0]<<" "<<jj[1]<<endl;
            }
        }
        if(z==6){
            break;
        }
    }

} 