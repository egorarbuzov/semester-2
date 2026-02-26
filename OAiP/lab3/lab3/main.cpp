#include <iostream>
#include <cstring>

using namespace std;

const int MAX_TASKS = 100;
const int MAX_LENGHT = 300;
char tasks[MAX_TASKS][MAX_LENGHT];

int main() {
  setlocale(LC_ALL, "Ru");
  static int taskCount = 0;
  bool done = false;
  do {
    cout << "Выберите: " << endl;
    cout << "Добавить задачу - 1" << endl;
    cout << "Удалить задачу - 2" << endl;
    cout << "Показать задачи - 3" << endl;
    cout << "Выйти - 0" << endl;
    int choice = -1;
    cin >> choice;
    switch (choice) {
    case 1: {
      char buffer[MAX_LENGHT];
      cout << "Введите задачу: ";
      cin.ignore();
      cin.getline(buffer, MAX_LENGHT);
      strcpy(tasks[taskCount], buffer);
      cout << "Задача добавлена!" << endl;
      taskCount++;
      done = false;
      break;
    }
    case 2: {
      int numToDelete = -1;
      cout << "Выберите номер задачи: "; cin >> numToDelete;
      for (int i = numToDelete - 1; i < taskCount; i++) {
        strcpy(tasks[i], tasks[i + 1]);
      }
      taskCount--;
      done = false;
      break;
    }

    case 3: {
      cout << "Список задач:" << endl;
      for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
      }
      done = false;
      break;
    }
    case 0: {
      done = true;
      break;
    }
    }
  } while (done != true);


  return 0;
}
