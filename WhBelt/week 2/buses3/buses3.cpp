#include <iostream>
#include <map>
#include <set>

using namespace std;
int main() {
  int N;
  cin >> N;

  map<set<string>, int> buses;

  for (int i = 0; i < N; ++i) {
    int stop_counts;
    set<string> stops;
    cin >> stop_counts;
    for (int i = 0; i < stop_counts; ++i) {
      string temp;
      cin >> temp;
      stops.insert(temp);
    }
    if (buses.count(stops) == 1) {
      cout << "Already exists for " << buses[stops] << endl;
    } else {
      int cur_size = buses.size();
      buses[stops] = cur_size += 1;
      cout << "New bus " << buses[stops] << endl;
    }
  }

  return 0;
}