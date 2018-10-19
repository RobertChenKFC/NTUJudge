#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

using Ingredients = set<string>;

int main() {
  int n;
  cin >> n;
  map<string, Ingredients> foods;
  for (int i = 0; i < n; ++i) {
    string name;
    int numIngredients;
    cin >> name >> numIngredients;
    Ingredients ingredients;
    string ingredient;
    for (int i = 0; i < numIngredients; ++i) {
      cin >> ingredient;
      ingredients.insert(ingredient);
    }
    foods[name] = ingredients;
  }

  int m;
  cin >> m;
  while (m--) {
    string name1, name2;
    cin >> name1 >> name2;
    const auto &ingredients1 = foods[name1];
    const auto &ingredients2 = foods[name2];
    auto end = ingredients2.end();
    bool first = true;
    for (const auto &ingredient : ingredients1) {
      if (ingredients2.find(ingredient) != end) {
        if (!first) cout << ' ';  
        first = false;
        cout << ingredient;
      }
    }
    if (first) cout << "nothing" << endl;
    else cout << endl;
  }
}

