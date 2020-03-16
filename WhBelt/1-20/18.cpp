#include <iostream>
#include <vector>

using namespace std;
int main() {
  int number_of_commands;
  cin >> number_of_commands;
  vector<int> queue;
  vector<int> worryed;
  for (int i = 0; i < number_of_commands; ++i) {
    string current_command;
    cin >> current_command;
    if (current_command == "COME") {
      int persones;
      cin >> persones;
      if (persones > 0) {
        for (int i = 0; i < persones; ++i) {
          queue.push_back(0);
        }
      } else {
        queue.resize(queue.size() + persones);
      }
    } else if (current_command == "WORRY") {
      int persone;
      cin >> persone;
      queue[persone] = 1;
    } else if (current_command == "QUIET") {
      int persone;
      cin >> persone;
      queue[persone] = 0;
    } else if (current_command == "WORRY_COUNT") {
      int temp = 0;
      for (auto p : queue) {
        if (p == 1) {
          temp += 1;
        }
      }
      worryed.push_back(temp);
    }
  }
  for (auto w : worryed) {
    cout << w << endl;
  }

  return 0;
}