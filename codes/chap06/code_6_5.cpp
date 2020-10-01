#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; // ��ʬ�礭���ͤ� 1 �ķ���

int main() {
    // ����
    int N;
    cin >> N;
    vector<long long> h(N), s(N);
    for (int i = 0; i < N; i++) cin >> h[i] >> s[i];

    // ��ʬõ��
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        
        // Ƚ��
        bool ok = true;
        vector<long long> t(N, 0); // ����������ޤǤ����»���
        for (int i = 0; i < N; ++i) {
            // ���⤽�� mid ��������٤���㤫�ä���false
            if (mid < h[i]) ok = false; 
            else t[i] = (mid - h[i]) / s[i];
        }
        // �������¤��������äƤ����˥�����
        sort(t.begin(), t.end()); 
        for (int i = 0; i < N; ++i) {
            if (t[i] < i) ok = false; // �����ڤ�ȯ��
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
