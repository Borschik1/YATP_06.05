#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    vector<int> vec;
    int n, h1, m1, h2, m2, answer = 0;
    fin >> n;
    for (int i = 0; i < 1440; ++i) {
        vec.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        fin >> h1 >> m1 >> h2 >> m2;
        if (h1 * 60 + m1 < h2 * 60 + m2) {
            for (int j = h1 * 60 + m1; j < h2 * 60 + m2; ++j) {
                vec[j]++;
            }
        }
        else if (h1 * 60 + m1 == h2 * 60 + m2) {
            for (int j = 0; j < 1440; ++j) {
                vec[j]++;
            }
        }
        else {
            for(int j = h1 * 60 + m1; j < 1440; ++j) {
                vec[j]++;
            }
            for (int j = 0; j < h2 * 60 + m2; ++j) {
                vec[j]++;
            }
        }
    }
    for (int i = 0; i < 1440; ++i) {
        if (vec[i] == n) {
            answer++;
        }
    }
    fout << answer;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
