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
int C = 10;
map<string, int> codes;
vector<street> streets;
map<int, map<int, int>> freq;
void precompute(){

}
int priority(int ratio, int l, int i){
    return 5*ratio - l ;
}
bool compare(const pair<int, int> &p1, const pair<int, int> &p2){
    int L1 = streets[p1.first].l;
    int L2 = streets[p2.first].l;
    return (priority(p1.second, L1, streets[p1.first].e) > priority(p2.second, L2, streets[p2.first].e));
}

int max3(int x, int y, int z){
    return max(x, max(y,z));
}
int main(){
    #ifdef SARTHAK
    freopen("e.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now(); 
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int D, I, S, V, F, B, E, L, P;
    string st;
    cin>>D>>I>>S>>V>>F;

    

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
            int lat = streets[stid].l;
            //v2.push_back(stid);
            freq[inter][stid]+=D/P;
            inter_streets[inter].insert(stid);
            intersum[inter]+=D/P;
        }
        //v.push_back(v2);
    }

    vector<vector<pair<int, int>>> out;

    int y = 0, z = 0;
    for(int i = 0; i<I; i++){
        vector<pair<int, int>> vz;

        if(freq[i].size() != 0){
            int maxid = 0, maxm = 0, k = 0;
            for (auto itr = inter_streets[i].begin(); itr != inter_streets[i].end(); ++itr) {
                C = (streets[*itr].l);
                // vz.push_back({*itr, 1});
                // if (freq[i][*itr] > maxm){
                //     maxid = k;
                //     maxm = freq[i][*itr];
                // }
                // k++;
                vz.push_back({*itr, (int)(1 + max(0.1, 1.0*freq[i][*itr]*D/(10*intersum[i])))});
            }
            sort(vz.begin(), vz.end(), compare);
            //cout<<maxid<<" ";
            //vz[maxid] = {vz[maxid].first, 2};
            vz.insert(vz.begin(), {-1, i});
            out.push_back(vz);
        }
    }
    cout<<out.size()<<"\n";
    for(auto o : out){
        
        for(auto s: o){
            if(s.first == -1){
                cout<<s.second<<"\n";
                cout<<o.size() - 1<<"\n";
                continue;
            }
                cout<<streets[s.first].name<<" "<<s.second<<"\n";
            }
    }
    //cout<<y<<" "<<z;
    #ifdef SARTHAK
    auto end = chrono::high_resolution_clock::now(); 
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); time_taken *= 1e-9; 
    //cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9); cout << " sec" << endl; 
    #endif
    return 0;
}
