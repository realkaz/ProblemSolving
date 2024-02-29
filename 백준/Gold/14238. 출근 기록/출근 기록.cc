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


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////

string ans;
int A, B, C;
bool visited[3][3][51][51][51];

bool dfs(char prv, char cur, int a, int b ,int c) {
    if (a > A || b > B || c > C) {
        return 0;
    }
    if (visited[prv - 'A'][cur - 'A'][a][b][c]) return 0;
    visited[prv - 'A'][cur - 'A'][a][b][c] = true;
    if (a == A && b == B && c == C) {
        cout << ans;
        return 1;
    }

    ans.push_back('A');
    if (dfs(cur, 'A', a + 1, b, c)) {
        return 1;
    }
    ans.pop_back();

    if (cur != 'B') {
        ans.push_back('B');
        if (dfs(cur, 'B', a, b + 1, c)) {
            return 1;
        }
        ans.pop_back();
    }

    if (prv != 'C' && cur != 'C') {
        ans.push_back('C');
        if (dfs(cur, 'C', a, b, c + 1)) {
            return 1;
        }
        ans.pop_back();
    }
    return 0;
}


void solve() {
    string s;
    cin >> s;
    A = B = C = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            A += 1;
        }
        else if (s[i] == 'B') {
            B += 1;
        }
        else {
            C += 1;
        }
    }
    if (!dfs('A', 'A', 0, 0, 0)) {
        cout << -1;
    }

}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1; //
    while (T--) {
        solve();
    }
    return 0;
}