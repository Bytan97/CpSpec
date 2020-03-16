#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto word : source) {
    destination.push_back(word);
  }
  source.clear();
}

int main() {
  //   vector<string> source, destination;
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  //   cout << "Before move" << endl;
  //   for (auto word : source) {
  //     cout << word << " ";
  //   }
  //   cout << endl;
  //   for (auto word : destination) {
  //     cout << word << " ";
  // }
  //   cout << "After move " << endl;
  MoveStrings(source, destination);

  //   for (auto word : source) {
  //     cout << word << " ";
  //   }
  //   cout << endl;
  //   for (auto word : destination) {
  //     cout << word << " ";
  // }

  return 0;
}