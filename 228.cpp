#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


float need(float rub, float usd, float eur, int iteration, vector<pair<float, float>> vec) {
    if (iteration == vec.size() - 1) {
        return rub + vec[iteration].first * usd + vec[iteration].second * eur;
    }
    vector<float> plug;
    float maxi = 0;
    plug.push_back(need(rub, usd, eur, iteration + 1, vec));
    plug.push_back(need(0, usd, eur + rub / vec[iteration].second, iteration + 1, vec));
    plug.push_back(need(0, 0, eur + (rub + usd * vec[iteration].first) / vec[iteration].second, iteration + 1, vec));
    plug.push_back(need(0, usd + rub / vec[iteration].first, eur, iteration + 1, vec));
    plug.push_back(need(0, usd + (rub + eur * vec[iteration].second) / vec[iteration].first, 0, iteration + 1, vec));
    plug.push_back(need(rub + usd * vec[iteration].first, 0, eur, iteration + 1, vec));
    plug.push_back(need(rub + eur * vec[iteration].second, usd, 0, iteration + 1, vec));
    plug.push_back(need(rub + usd * vec[iteration].first + eur * vec[iteration].second, 0, 0, iteration + 1, vec));
    for (int i = 0; i < 8; ++i) {
        maxi = max(maxi, plug[i]);
    }
    return maxi;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n;
    fin >> n;
    vector<pair<float, float>> vec;
    pair<float, float> plug;

    float usd, eur;
    for (int i = 0; i < n; ++i) {
        fin >> usd >> eur;
        plug.first = usd;
        plug.second = eur;
        vec.push_back(plug);
    }

    fout << fixed << setprecision(2) << need(100, 0, 0, 0, vec) << endl;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
