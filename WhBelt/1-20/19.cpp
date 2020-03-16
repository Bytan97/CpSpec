#include <iostream>
#include <vector>

using namespace std;
int main() {
  int current_month = 0;
  vector<int> day_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<vector<string>> list(day_in_month[current_month]);

  int Q;  // number of commands
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    string current_command;
    cin >> current_command;
    if (current_command == "ADD") {
      string task;
      int day;
      cin >> day >> task;
      list[day - 1].push_back(task);
    } else if (current_command == "DUMP") {
      int day;
      cin >> day;
      cout << list[day - 1].size() << " ";
      for (auto task : list[day - 1]) {
        cout << task << " ";
      }
      cout << endl;
    } else if (current_command == "NEXT") {
      int prev_month = current_month;
      current_month = (current_month + 1) % 12;
      int cur_d = day_in_month[current_month];
      int prev_d = day_in_month[prev_month];
      if (cur_d < prev_d) {
        for (int i = cur_d + 1; i <= prev_d; ++i) {
          if (!list[i - 1].empty()) {
            list[cur_d - 1].insert(end(list[cur_d - 1]), begin(list[i - 1]),
                                   end(list[i - 1]));
          }
        }
        list.resize(cur_d);
      } else {
        list.resize(cur_d);
      }
    }
  }

  return 0;
}

/*
5
ADD 30 A
ADD 31 B
NEXT
DUMP 28
DUMP 3

*/
/*
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
*/

/*
28
ADD 1 Jan_1_1
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
DUMP 1
DUMP 31
DUMP 30
*/
/*
18
ADD 31 Jan_31_1
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
NEXT
ADD 31 Dec_31
NEXT
ADD 31 Jan_31_2
DUMP 31
NEXT
DUMP 28

*/