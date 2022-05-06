#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


int simple(int a, int b) {
    while (a != 0 && b != 0) { if (a > b) { a %= b; } else { b %= a; } }
    return a + b;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n;
    fin >> n;
    for (int i = n / 2; i >= 1; --i) {
        if (simple(i, n - i) == 1) {
            fout << i << " " << n - i;
            break;
        }
    }
    fin.close();
    fout.close();
    system("pause");
    return 0;
}