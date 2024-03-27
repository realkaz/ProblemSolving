#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"

//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

ll fastpow(ll x, ll n, ll mod = INF) {
    if (n == 0) return 1;
    if (n % 2) return x * fastpow(x, n - 1, mod) % mod;
    ll half = fastpow(x, n / 2, mod);
    return half * half % mod;
}




/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////





void solve() {
    int N, M;
    cin >> N >> M;
    if (N % 2 == 0) {
        cout << N * M << endl;
        for (int i = 1; i <= N; i++) {
            cout << i << " " << 1 << endl;
        }
        for (int i = N; i >= 1; i--) {
            if (i % 2 == 0) {
                for (int j = 2; j <= M; j++) {
                    cout << i << " " << j << endl;
                }
            }
            else {
                for (int j = M; j >= 2; j--) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    else if (M % 2 == 0) {
        cout << N * M << endl;
        for (int j = 1; j <= M; j++) {
            cout << 1 << " " << j << endl;
        }
        for (int j = M; j >= 1; j--) {
            if (j % 2 == 0) {
                for (int i = 2; i <= N; i++) {
                    cout << i << " " << j << endl;
                }
            }
            else {
                for (int i = N; i >= 2; i--) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    else {
        cout << N * M - 1 << endl;
        for (int i = 1; i <= N; i++ ) {
            cout << i << " " << 1 << endl;
        }
        for (int j = 2; j <= M - 2; j++) {
            if (j % 2 == 0) {
                for (int i = N; i >= 2; i--) {
                    cout << i << " " << j << endl;
                }
            }
            else {
                for (int i = 2; i <= N; i++) {
                    cout << i << " " << j << endl;
                }
            }
        }
        for (int i = N; i >= 2; i--) {
            if (i % 2 == 1) {
                cout << i << " " << M - 1 << endl;
                cout << i << " " << M << endl;
            }
            else {
                cout << i << " " << M << endl;
                cout << i << " " << M - 1 << endl;
            }
        }
        for (int j = M - 1; j >= 2; j--) {
            cout << 1 << " " << j << endl;
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

