#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find �μ�����ά

// �� e = (u, v) �� {w(e), {u, v}} ��ɽ��
using Edge = pair<int, pair<int,int>>;

int main() {
    // ����
    int N, M; // ĺ�������տ�
    cin >> N >> M;
    vector<Edge> edges(M); // �ս���
    for (int i = 0; i < M; ++i) {
        int u, v, w; // w �ϽŤ�
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // ���դ��դνŤߤ���������˥����Ȥ���
    // pair �ϥǥե���Ȥ� (�������, ��������) �μ�������
    sort(edges.begin(), edges.end());

    // ���饹����ˡ
    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // �� (u, v) ���ɲäˤ�äƥ������뤬���������Ȥ����ɲä��ʤ�
        if (uf.issame(u, v)) continue;

        // �� (u, v) ���ɲä���
        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
}
