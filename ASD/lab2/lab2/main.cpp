#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cout << "Введите число N: ";
    cin >> N;
    
    int max_shagov = ceil(log2(N));
    cout << "Загадайте число от 1 до " << N << endl;
    cout << "Выберите:" << endl;
    cout << "1 - мало" << endl;
    cout << "2 - много" << endl;
    cout << "0 - угадал" << endl;
    
    int left = 1;
    int right = N;
    int popytka = 0;
    int otvet;
    int X;
    
    int shagi[100];
    int index = 0;
    
    while (left <= right)
    {
        popytka++;
        X = (left + right) / 2;
        shagi[index] = X;
        index++;
        
        cout << "Попытка " << popytka << ": " << X << "? ";
        cin >> otvet;
        
        if (otvet == 0)
        {
            cout << "Ваше число: " << X << " угадал за " << popytka << " попыток" << endl;
            break;
        }
        else if (otvet == 1)
        {
            left = X + 1;
        }
        else if (otvet == 2)
        {
            right = X - 1;
        }
    }
    
    cout << "Максимальное количество шагов = " << max_shagov << endl;
    
    cout << N << endl;
    int temp = N;
    while (temp > 1)
    {
        temp = temp / 2;
        cout << temp << endl;
    }
    
    return 0;
}
