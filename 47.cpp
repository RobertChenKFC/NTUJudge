#include <iostream>
#include <string>

using namespace std;

void Print(const string &str) {
  int cnt = 1;
  for (int i = 1; i < str.length(); ++i) {
    if (str[i] != str[i - 1]) {
      cout << str[i - 1] << ' ' << cnt << ' ';
      cnt = 1;
    } else {
      ++cnt; 
    }
  }
  if (str.length() == 0)
    cout << '$' << endl;
  else
    cout << str.back() << ' ' << cnt << " $" << endl;
}

int main() {
  string instruction;
  string str;
  while (cin >> instruction) {
    if (instruction == "print") {
      Print(str);
    } else if (instruction == "insert") {
      char c;
      int n;
      cin >> instruction >> c >> n;
      if (instruction == "left") str.insert(0, n, c);
      else if (instruction == "right") str.append(n, c);
      else str.insert(stoi(instruction) - 1, n, c);
    }

#ifdef DEBUG
    cout << "Current: ";
    Print(str);
#endif
  }
}

