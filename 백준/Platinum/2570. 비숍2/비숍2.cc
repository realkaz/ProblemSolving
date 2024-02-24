#pragma warning(disable:4996) 
#include<iostream>
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
#include<ctime>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
#define pb push_back
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };



int linediv1[200];
int linediv2[200];
bool board[101][101];

unordered_map<int, vector<int>> E;
unordered_map<int, int> assign;
unordered_map<int, bool > done;
int N, M;

bool dfs(int x) {
    for (int i = 0; i < E[x].size(); i++) {
        int target = E[x][i];
        if (done[target]) continue;
        done[target] = 1;
        if (assign[target]==0 || dfs(assign[target])) {
            assign[target] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a = i + j - 1;
            int b = N + i - j;
            if (board[i][j]) {
                linediv1[a] += 1;
                linediv2[b] += 1;
            }
            else {
                a += (2 * N - 1) * linediv1[a];
                b += (2 * N - 1) * linediv2[b];
                E[a].push_back(b);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 2 * N; i++) {
        for (int j = 0; j <= linediv1[i]; j++) {
            done.clear();
            if (dfs(i + j * (2 * N - 1))) ans += 1;
        }
    }

    cout << ans;

    return 0;
}