#include <bits/stdc++.h>
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
using namespace std;

struct Edge { int to, id; };

const int MAXN = 10005;            // N ≤ 1e4  (đề)
vector<Edge> g[MAXN];
vector<pair<int,int>> edges;

int N, M;

int par[MAXN], peid[MAXN], depthArr[MAXN];
bool vis[MAXN], inCycleEdge[20005];

vector<vector<int>> cycles;
vector<int> stackEdge;

void dfsCycle(int u, int p = -1, int id = -1) {
    vis[u] = true;
    par[u] = p;
    peid[u] = id;
    for (auto [v, eid] : g[u]) {
        if (eid == id) continue;
        if (!vis[v]) {
            depthArr[v] = depthArr[u] + 1;
            stackEdge.push_back(eid);
            dfsCycle(v, u, eid);
            stackEdge.pop_back();
        } else if (depthArr[v] != -1 && depthArr[v] < depthArr[u]) {
            vector<int> cyc{v};
            int cur;
            do {
                cur = stackEdge.back();
                stackEdge.pop_back();
                int a = edges[cur].first;
                int b = edges[cur].second;
                int w = depthArr[a] > depthArr[b] ? a : b;
                cyc.push_back(w);
                inCycleEdge[cur] = true;
            } while (cur != eid);
            cycles.push_back(cyc);
        }
    }
}

int tot;
vector<vector<pair<int,int>>> T;   // block‑cut tree
vector<int> idCycle;

void buildTree() {
    tot = N;
    T.assign(2 * N, {});
    idCycle.resize(cycles.size());

    for (int i = 0; i < (int)cycles.size(); ++i) {
        int cNode = tot++;
        idCycle[i] = cNode;
        int L = cycles[i].size();
        for (int v : cycles[i]) {
            T[cNode].push_back({v, L});
            T[v].push_back({cNode, L});
        }
    }
    for (int i = 0; i < M; ++i)
        if (!inCycleEdge[i]) {
            auto [u, v] = edges[i];
            T[u].push_back({v, 1});
            T[v].push_back({u, 1});
        }
}

vector<long long> bestDist;
long long ans = 0;
vector<char> seenCycle;            // tránh xử lý 1 cycle nhiều lần

void processCycle(int cid, int parent) {
    if (seenCycle[cid]) return;
    seenCycle[cid] = 1;

    auto &cyc = cycles[cid];
    int k = cyc.size();
    vector<long long> newVal(k, 0);

    for (int i = 0; i < k; ++i)
        newVal[i] = bestDist[cyc[i]];          // giá trị trước khi “đi vòng”

    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j) if (i != j) {
            int d = abs(i - j);
            d = min(d, k - d);
            int dist = k - d;                  // quãng dài hơn
            newVal[j] = max(newVal[j], bestDist[cyc[i]] + dist);
            ans = max(ans, bestDist[cyc[i]] + dist);
        }

    for (int i = 0; i < k; ++i)
        bestDist[cyc[i]] = newVal[i];
}

void dfsSolve(int u, int p) {
    for (auto [to, w] : T[u]) {
        if (to == p) continue;
        if (to < N) {
            bestDist[to] = bestDist[u] + 1;
            ans = max(ans, bestDist[to]);
            dfsSolve(to, u);
        } else {
            int cid = to - N;
            processCycle(cid, u);
            for (int v : cycles[cid])
                if (v != u && v != p) {
                    dfsSolve(v, to);
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    file("TASK");
    if (!(cin >> N >> M)) return 0;
    edges.resize(M);
    for (int i = 0, u, v; i < M; ++i) {
        cin >> u >> v; --u; --v;
        edges[i] = {u, v};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    fill(depthArr, depthArr + N, -1);
    depthArr[0] = 0;
    dfsCycle(0);

    buildTree();
    bestDist.assign(tot, 0);
    seenCycle.assign(cycles.size(), 0);

    dfsSolve(0, -1);
    cout << ans << '\n';
    return 0;
}
