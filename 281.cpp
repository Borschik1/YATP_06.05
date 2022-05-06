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
    vector<unsigned long long> factorial;
    unsigned long long n, m, copy, now = 1, answer = 0;
    fin >> n >> m;
    factorial.push_back(1);
    copy = 1;
    while (copy != n + 1) {
        now *= copy;
        factorial.push_back(now);
        copy++;
    }
    for (int i = m; i <= n; ++i) {
        answer += factorial[n] / (factorial[i] * factorial[n - i]);
    }
    fout << answer;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
