#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector< bitset<1024> > features(n); 
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      features[i] = bitset<1024>(s);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int in = (features[i] & features[j]).count();
        int un = (features[i] | features[j]).count();
        if (un == 0) continue;
        double sim = (double)in / un;
        if (sim >= 0.8) ++count;
      }  
    }
    cout << fixed << setprecision(2) << ((double)count / (n * (n - 1) / 2) * 100) << endl;
  }
}

