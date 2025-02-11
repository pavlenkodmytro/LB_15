#include <iostream>   // Підключення бібліотеки для вводу/виводу.
// Забезпечує доступ до std::cout, який використовується для виведення результатів на екран.
using namespace std;

// Функція isLeap визначає, чи є рік високосним.
// Аргумент:
//    int year – рік, який перевіряємо.
// Повертає:
//    bool – true, якщо рік високосний, або false, якщо ні.
bool isLeap(int year) {
    // Рік вважається високосним, якщо:
    // - він ділиться на 4, але не ділиться на 100, або
    // - він ділиться на 400.
    // Операції % (залишок від ділення) використовуються для перевірки кратності.
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// ========================
// Варіант 1: Використання switch-case
// ========================

// Функція monthLengthSwitch приймає два аргументи: рік і номер місяця,
// і повертає кількість днів у цьому місяці. Для місяця лютий перевіряється високосність.
int monthLengthSwitch(int year, int month) {
    // Використовуємо конструкцію switch для розгалуження за номером місяця.
    switch (month) {
        case 1:  // Січень
        case 3:  // Березень
        case 5:  // Травень
        case 7:  // Липень
        case 8:  // Серпень
        case 10: // Жовтень
        case 12: // Грудень
            // Для цих місяців завжди 31 день.
            return 31;
        case 4:  // Квітень
        case 6:  // Червень
        case 9:  // Вересень
        case 11: // Листопад
            // Для цих місяців завжди 30 днів.
            return 30;
        case 2:  // Лютий
            // Для лютого кількість днів залежить від високосності року.
            // Якщо рік високосний, повертаємо 29, інакше 28.
            return (isLeap(year)) ? 29 : 28;
        default:
            // Якщо номер місяця не коректний, повертаємо 0.
            return 0;
    }
}

// ========================
// Варіант 2: Використання одновимірного масиву (вектору)
// ========================

// Функція monthLengthVector приймає два аргументи: рік і номер місяця,
// і повертає кількість днів у цьому місяці, використовуючи одновимірний масив з довжинами місяців.
int monthLengthVector(int year, int month) {
    // Оголошуємо масив з кількістю днів для кожного місяця звичайного року.
    // Індекс 0 відповідає 1-му місяцю (січень), індекс 1 – 2-му (лютий) і т.д.
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Якщо перевіряємо лютий і рік високосний, встановлюємо 29 днів.
    if (month == 2 && isLeap(year))
        return 29;
    
    // Повертаємо значення з масиву. Оскільки місяці нумеруються від 1, а індекси масиву починаються з 0,
    // використовуємо вираз (month - 1).
    return daysInMonth[month - 1];
}

int main(void) {
    // Для демонстрації виведемо довжину місяців для двох років:
    // 2000 (високосний рік) та 2001 (звичайний рік).

    // ------------------------------
    // Варіант 1: Використання switch-case
    // ------------------------------
    cout << "Using switch-case:" << endl;
    for (int yr = 2000; yr < 2002; yr++) {  // yr набуває значень 2000 та 2001.
        for (int mo = 1; mo <= 12; mo++) {   // mo пробігає від 1 до 12 (усі місяці).
            // Функція monthLengthSwitch повертає кількість днів для заданого року та місяця.
            cout << monthLengthSwitch(yr, mo) << " ";
        }
        cout << endl;  // Після кожного року переходимо на новий рядок.
    }
    
    // Додатково можна продемонструвати роботу функції за допомогою другого методу.
    cout << "\nUsing vector:" << endl;
    for (int yr = 2000; yr < 2002; yr++) {  // Для років 2000 та 2001.
        for (int mo = 1; mo <= 12; mo++) {   // Для кожного місяця від 1 до 12.
            // Викликаємо функцію monthLengthVector, яка використовує масив для визначення довжини місяця.
            cout << monthLengthVector(yr, mo) << " ";
        }
        cout << endl;
    }
    
    // Завершення роботи програми.
    return 0;
}
