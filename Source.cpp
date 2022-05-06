#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n, m, d, l, h, now_v, answer;
    float now_time, min_time;
    fin >> n >> m;
    vector<vector<int>> vec;
    vector<int> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        fin >> d >> l >> h;
        plug.push_back(d);
        plug.push_back(l);
        plug.push_back(h);
        vec.push_back(plug);
    }
    now_v = m;
    now_time = 0;
    for (int j = 0; j < n; ++j) {
        now_time += (float)vec[j][0] / now_v;
        if (now_v > vec[j][1]) {
            now_time += vec[j][2];
        }
    }
    min_time = now_time;
    answer = now_v;
    for (int i = 0; i < n; ++i) {
        now_v = vec[i][1];
        if (now_v > m) {
            continue;
        }
        now_time = 0;
        for (int j = 0; j < n; ++j) {
            now_time += (float)vec[j][0] / now_v;
            if (now_v > vec[j][1]) {
                now_time += vec[j][2];
            }
        }
        if (now_time < min_time) {
            min_time = now_time;
            answer = now_v;
        }
    }
    fout << answer;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}