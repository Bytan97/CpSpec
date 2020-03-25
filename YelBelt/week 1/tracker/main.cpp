#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
 private:
  map<string, TasksInfo> person_to_task;
 public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo &GetPersonTasksInfo(const string &person) const {
//    if (person_to_task.count(person))
    return person_to_task.at(person);
  }
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string &person) {
    person_to_task[person][TaskStatus::NEW] += 1;
  }
  // Обновить статусы по данному количеству задач конкретного разработчика,
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string &person, int task_count) {
    if (person_to_task.count(person) == 0) {
      return {{}, {}};
    }
    TasksInfo Updated, Untouched, current_person = person_to_task[person];
    if (task_count > current_person[TaskStatus::NEW] + current_person[TaskStatus::TESTING]
        + current_person[TaskStatus::IN_PROGRESS]) {
      task_count = current_person[TaskStatus::NEW] + current_person[TaskStatus::TESTING]
          + current_person[TaskStatus::IN_PROGRESS];
    }
    
    for (int intStatus = static_cast<int>(TaskStatus::NEW); intStatus != static_cast<int>(TaskStatus::DONE);
         ++intStatus) {
      int current_task_counts = person_to_task[person][static_cast<TaskStatus>(intStatus)];
      int available = current_person[static_cast<TaskStatus>(intStatus)];
      if (task_count <= 0) {
        break;
      }
      if (current_task_counts <= task_count) {
        current_person[static_cast<TaskStatus>(intStatus)] -= current_task_counts;
        current_person[static_cast<TaskStatus>(intStatus + 1)] += current_task_counts;
        Updated[static_cast<TaskStatus>(intStatus + 1)] = current_task_counts;
        task_count -= current_task_counts;
      } else {
        current_person[static_cast<TaskStatus>(intStatus)] -= task_count;
        current_person[static_cast<TaskStatus>(intStatus + 1)] += task_count;
        Updated[static_cast<TaskStatus>(intStatus + 1)] = task_count;
        task_count = 0;
      }
    }

    for (int intStatus = static_cast<int>(TaskStatus::NEW); intStatus != static_cast<int>(TaskStatus::DONE);
         ++intStatus) {
      Untouched[static_cast<TaskStatus>(intStatus)] =
          current_person[static_cast<TaskStatus>(intStatus)] - Updated[static_cast<TaskStatus>(intStatus)];
      if (Updated[static_cast<TaskStatus>(intStatus)] == 0) {
        Updated.erase(static_cast<TaskStatus>(intStatus));
      }
      if (Untouched[static_cast<TaskStatus>(intStatus)] == 0) {
        Untouched.erase(static_cast<TaskStatus>(intStatus));
      }
      if (current_person[static_cast<TaskStatus>(intStatus)] == 0) {
        current_person.erase(static_cast<TaskStatus>(intStatus));
      }
    }
    if (current_person[TaskStatus::DONE] == 0) {
      current_person.erase(TaskStatus::DONE);
    }
    if (Untouched[TaskStatus::DONE] == 0) {
      Untouched.erase(TaskStatus::DONE);
    }
    if (Updated[TaskStatus::DONE] == 0) {
      Updated.erase(TaskStatus::DONE);
    }

    person_to_task[person] = current_person;

    return {Updated, Untouched};
  }
};

int main() {
  TeamTasks tasks;
  TasksInfo updated_tasks;
  TasksInfo untouched_tasks;

  tasks.AddNewTask("Lisa");

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);

  tasks.AddNewTask("Lisa");
  tasks.AddNewTask("Lisa");

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);

  tasks.AddNewTask("Lisa");

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);

  return 0;
}