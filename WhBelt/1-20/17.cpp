#include <iostream>
#include <vector>

using namespace std;
int main() {
  int N, average, sum;
  cin >> N;
  vector<int> days(N);
  for (auto& day : days) {
    cin >> day;
  }
  for (const auto& day : days) {
    sum += day;
  }
  average = sum / N;
  vector<int> result;
  for (int i = 0; i < days.size(); ++i) {
    if (days[i] > average) {
      result.push_back(i);
    }
  }
  cout << result.size() << endl;
  for (const auto& day : result) {
    cout << day << " ";
  }
  return 0;
}