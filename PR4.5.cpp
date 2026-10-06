#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x, y, R;

    cout << "Введіть радіус R (R > 0): ";
    cin >> R;

    srand((unsigned)time(NULL));

    cout << "\n--- 1 спосіб: введення координат з клавіатури ---" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Постріл " << i + 1 << endl;
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        // Перевірка умови потрапляння в зафарбовану область
        if ((x * x + y * y <= R * R && x >= 0 && y >= 0 && y >= (x - 1) * (x - 1)) ||
            (x * x + y * y <= R * R && x <= 0 && y <= 0))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    cout << "\n--- 2 спосіб: випадкові координати з інтервалу [-R; R] ---" << endl;
    cout << fixed;
    for (int i = 0; i < 10; i++)
    {
        // Генерація випадкових чисел у діапазоні [-R; R]
        x = (2.0 * R) * rand() / RAND_MAX - R;
        y = (2.0 * R) * rand() / RAND_MAX - R;

        if ((x * x + y * y <= R * R && x >= 0 && y >= 0 && y >= (x - 1) * (x - 1)) ||
            (x * x + y * y <= R * R && x <= 0 && y <= 0))
        {
            cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "yes" << endl;
        }
        else
        {
            cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "no" << endl;
        }
    }

    return 0;
}