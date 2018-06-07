#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10000;
int n, m, k;
ll x;
string arr[maxn];
ll dp[maxn];
string str;

/* So ovaa funkcija ustvari go generirash zboro sho ti treba */
bool dfs(int pos, int unknown_pos, ll x_left, string gen){

    if(x_left == 0 && pos == n){
        // ovoa znachi deka vekje si go najdela zboro, ispechatesh go i vratesh true
        cout << gen << "\n";
        return true;
    }

    // ovaj sluchaj e ako izlezesh nadvor od granicata kaj sho treba da barash
    if(dp[m - unknown_pos] <= x_left){
        return false;
    }

    // ovoa znachi deka ako momentalnata bukva sho ja gledash u str ne e ednakva
    // na #, samo ja dodadesh na gen stringo i prodolzuvash naredno
    if(str[pos] != '#'){
        return dfs(pos+1, unknown_pos, x_left, gen + str[pos]);
    }

    // tuka kje doe funkcijata samo ako str[pos] == '#'. Tuka gi isprobuvash
    // site mozni bukvi za taa pozicija. Ako u sluchaj dojdesh do reshenie, vratesh true
    // i zavrshuvash. Ako ne stavash nekoja bukva i probuvash dalje
    for(int i = 0; i < k; i++){
        if(dfs(pos+1, unknown_pos+1, x_left, gen + arr[unknown_pos][i])){
            return true;
        }
        x_left -= dp[m - unknown_pos - 1];
    }

    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> x;
    cin >> str;
    for(int i = 0; i < m; i++){
        cin >> arr[i];
        // sortiraj go sekoe posebno zborche po azbuchen redosled
        sort(arr[i].begin(), arr[i].end()); 
    }

    /* Tuka ustvari pravesh precalculations za slednoto:
    ako se naogash na i-toto zborche, dp[i] ti ustvari rachuna
    kolku zborovi mozes da sozdadesh koristejki gi site zborchinja od 
    0 do i. */
    dp[0] = 1;
    for(int i = 1; i < maxn; i++){
        dp[i] = dp[i-1]*k;
        if(dp[i] > x){
            dp[i] = 2*x;
        }
    }

    dfs(0, 0, x-1, "");
}