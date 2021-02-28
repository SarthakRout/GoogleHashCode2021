#include<bits/stdc++.h>
using namespace std;
const int M  = 100005;
long long int N = 1e9 + 7;
long long int Z = 998244353;
#define ll long long int

void precompute(){

}
int max3(int x, int y, int z){
    return max(x, max(y,z));
}
int main(){
    #ifdef SARTHAK
    freopen("a.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now(); 
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int D, I, S, V, F, B, E, L, P;
    string st;
    cin>>D>>I>>S>>V>>F;

    map<string, int> codes;
    vector<string> names;

    for(int i = 0; i<S; i++){
        cin>>B>>E;
        cin>>st;
        names.push_back(st);
        codes[st] = i;
        cin>>L;
    }
    vector<vector<int>> v;
    for(int i = 0; i<V; i++){
        cin>>P;
        vector<int> v2;
        for(int j = 0 ; j<P; j++){
            cin>>st;
            v2.push_back(codes[st]);
        }
        v.push_back(v2);
    }
    cout<<v.size();
    #ifdef SARTHAK
    auto end = chrono::high_resolution_clock::now(); 
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count(); time_taken *= 1e-9; 
    cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(9); cout << " sec" << endl; 
    #endif
   	return 0;
}
