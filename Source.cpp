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
    int n, k, answer = 0;
    fin >> n;
    vector<vector<int>> vec;
    vector<int> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        for (int j = 0; j < n; ++j) {
            fin >> k;
            plug.push_back(k);
        }
        vec.push_back(plug);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && vec[i][k] != -1 && vec[k][j] != -1) {
                    if (vec[i][j] == -1) {
                        vec[i][j] = vec[i][k] + vec[k][j];
                    }
                    else {
                        vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            answer = max(vec[i][j], answer);
        }
    }
    fout << answer;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}