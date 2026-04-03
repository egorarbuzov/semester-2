#include <iostream>
#include <string>
using namespace std;

int totalCandidates = 0;
static int* votes;
static string* candidateName;

int main()
{
    setlocale(LC_ALL, "RU");
    int choice;

    cout << "Введите количество кандидатов: ";
    cin >> totalCandidates;
    cin.ignore();
    
    bool end = false;
    votes = new int[totalCandidates];
    candidateName = new string[totalCandidates];

    for (int i = 0; i < totalCandidates; i++)
    {
        votes[i] = 0;
    }

    cout << "\nВведите имена кандидатов:" << endl;
    for (int i = 0; i < totalCandidates; i++)
    {
        cout << "Кандидат " << i + 1 << ": ";
        getline(cin, candidateName[i]);
    }

    do {
        int candidateNumber;
        int voteCount;

        cout << "Проголосовать - 1" << endl;
        cout << "Результаты - 2" << endl;
        cout << "Найти победителя - 3" << endl;
        cout << "Выход - 0" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
        case 1:
        {
            cout << "Список кандидатов:" << endl;
            for (int i = 0; i < totalCandidates; i++) {
                cout << i + 1 << ". " << candidateName[i] << " текущие голоса: " << votes[i] << " " << endl;
            }
            cout << "Введите номер кандидата (1-" << totalCandidates << "): ";
            cin >> candidateNumber;
            cout << "Введите количество голосов: ";
            cin >> voteCount;

            if (candidateNumber >= 1 && candidateNumber <= totalCandidates)
            {
                volatile int index = candidateNumber - 1;
                votes[index] += voteCount;
                cout << "Добавлено " << voteCount << " голосов кандидату "
                    << candidateName[index] << endl;
            }
            break;
        }

        case 2:
        {
            int totalVotes = 0;
            for (int i = 0; i < totalCandidates; i++)
            {
                totalVotes += votes[i];
            }

            for (int i = 0; i < totalCandidates; i++) {
                volatile int candidateNum = i + 1;
                cout << candidateNum << ". " << candidateName[i] << ": "
                    << votes[i] << endl;
            }
            cout << "Всего отдано голосов: " << totalVotes << endl;
            break;
        }

        case 3:
        {
            volatile int maxVotes = votes[0];
            int winnerIndex = 0;

            for (int i = 1; i < totalCandidates; i++)
            {
                if (votes[i] > maxVotes)
                {
                    maxVotes = votes[i];
                    winnerIndex = i;
                }
            }

            bool tie = false;
            for (int i = 0; i < totalCandidates; i++)
            {
                if (i != winnerIndex && votes[i] == maxVotes && maxVotes > 0)
                {
                    tie = true;
                    break;
                }
            }

            if (maxVotes == 0)
            {
                cout << "Голосов еще нет!" << endl;
            }
            else if (tie)
            {
                cout << "Ничья! Несколько кандидатов набрали по "
                    << maxVotes << " голосов:" << endl;

                for (int i = 0; i < totalCandidates; i++) {
                    if (votes[i] == maxVotes) {
                        cout << "- " << candidateName[i] << endl;
                    }
                }
            }
            else
            {
                cout << "Победитель: " << candidateName[winnerIndex] << endl;
                cout << "Количество голосов: " << maxVotes << endl;
            }
            break;
        }

        case 0:
            end = true;
            break;

        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (end == false);

    delete[] votes;
    delete[] candidateName;

    return 0;
}
