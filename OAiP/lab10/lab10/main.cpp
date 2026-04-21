#include <iostream>
#include <deque>

int main() {
    int n, k;
    
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Введите шаг k: ";
    std::cin >> k;
    
    if (n <= 0 || k <= 0) {
        std::cout << "Числа должны быть положительными" << std::endl;
        return 1;
    }
    
    std::deque<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    
    std::cout << "\nНачальный круг: ";
    for (int i = 0; i < people.size(); i++) {
        std::cout << people[i] << " ";
    }
    std::cout << std::endl;
    
    while (people.size() > 1) {
        for (int i = 1; i < k; ++i) {
            int frontPerson = people.front();
            people.pop_front();
            people.push_back(frontPerson);
        }
        
        int removedPerson = people.front();
        people.pop_front();
        
        std::cout << "Удален человек номер " << removedPerson << ". Осталось: " << people.size() << std::endl;
    }
    
    std::cout << "Последний выживший: " << people.front() << std::endl;
    
    return 0;
}
