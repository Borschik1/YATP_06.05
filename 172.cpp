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
    string n;
    long long k;
    fin >> n >> k;
    long long answer = ((int)n[0] - 48) % k;
    for (int i = 1; i < n.length(); i++) {
        int ind = (int)n[i] - 48;
        answer = ((answer * 10) % k + ((int)n[i]) - 48) % k;
    }
    fout << answer;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
