#include<bits/stdc++.h>
using namespace std;
const int M  = 100005;
long long int N = 1e9 + 7;
long long int Z = 998244353;
#define ll long long int
int intersum[M] = {0};
unordered_set<int> inter_streets[M];
struct street{
    string name;
    int b, e, l;
};
void precompute(){

}
int max3(int x, int y, int z){
    return max(x, max(y,z));
}
int main(){
    #ifdef SARTHAK
    freopen("f.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now(); 
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int D, I, S, V, F, B, E, L, P;
    int C = D;
    string st;
    cin>>D>>I>>S>>V>>F;

    map<string, int> codes;
    vector<street> streets;
    map<int, map<int, int>> freq;

    for(int i = 0; i<S; i++){
        cin>>B>>E;

        cin>>st;
        cin>>L;
        codes[st] = i;
        streets.push_back({st, B, E, L});
    }
    vector<vector<int>> v;
    for(int i = 0; i<V; i++){
        cin>>P;
        //vector<int> v2;
        for(int j = 0 ; j<P; j++){
            cin>>st;
            int stid = codes[st];
            int inter = streets[stid].e;
            //v2.push_back(stid);
            freq[inter][stid]++;
            inter_streets[inter].insert(stid);
            intersum[inter]++;
        }
        //v.push_back(v2);
    }

    vector<vector<pair<int, int>>> out;

    for(int i = 0; i<I; i++){
        vector<pair<int, int>> vz;
        if(freq[i].size() != 0){
            vz.push_back({i, -1});
            for (auto itr = inter_streets[i].begin(); itr != inter_streets[i].end(); ++itr) {
                vz.push_back({*itr, max(1, freq[i][*itr]*C/intersum[i])});
            }
            out.push_back(vz);
        }
    }
    cout<<out.size()<<"\n";
    for(auto o : out){
        
        for(auto s: o){
            if(s.second == -1){
                cout<<s.first<<"\n";
                cout<<o.size() - 1<<"\n";
                continue;
            }
            cout<<streets[s.first].name<<" "<<s.second<<"\n";
        }
    }
    #ifdef SARTHAK
    auto end = chrono::high_resolution_clock::now(); 
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); time_taken *= 1e-9; 
    //cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9); cout << " sec" << endl; 
    #endif
    return 0;
}
