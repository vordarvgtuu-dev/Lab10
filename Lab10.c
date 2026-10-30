#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h> // не работает #include <locale.h>

double fa(double x);
double fb(double x);
void run_task1();
double sin_n(double x, int N);
double sin_val1(double x, double eps);
void run_task2();


int main(void)
{
    SetConsoleOutputCP(65001);
    int main_choice;

    do {
        printf("\nГЛАВНОЕ МЕНЮ ПРОГРАММЫ\n");
        printf("1. Задание 1 (Вычисление fa(x) и fb(x))\n");
        printf("2. Задание 2 (Вычисление sin(x) тремя способами)\n");
        printf("0. Выход\n");
        printf("Выберите задание: ");

        if (scanf("%d", &main_choice) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n');
            main_choice = -1;
            continue;
        }
        switch (main_choice) {
        case 1:
            run_task1();
            break;
        case 2:
            run_task2();
            break;
        case 0:
            printf("\nВыход из программы.\n");
            break;
        default:
            printf("Неверный пункт меню. Попробуйте снова.\n");
        }
    } while (main_choice != 0);

    system("pause");
    return 0;
}


void run_task1()
{
    double x;
    int choice;

    printf("\nЗАДАНИЕ 1\n");
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        while (getchar() != '\n');
        return;
    }

    do {
        printf("\n");
        printf("\nМЕНЮ ЗАДАНИЯ 1\n");
        printf("1. Значение fa(x)\n");
        printf("2. Значение fb(x)\n");
        printf("3. Произведение fa(x) * fb(x)\n");
        printf("4. Разность квадратов fa(x)^2 - fb(x)^2\n");
        printf("5. Удвоенная сумма 2 * (fa(x) + fb(x))\n");
        printf("0. Назад в главное меню\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("fa(x) = %lf\n", fa(x));
            break;
        case 2:
            printf("fb(x) = %lf\n", fb(x));
            break;
        case 3:
            printf("Произведение: %lf\n", fa(x) * fb(x));
            break;
        case 4:
            printf("Разность квадратов: %lf\n", fa(x) * fa(x) - fb(x) * fb(x));
            break;
        case 5:
            printf("Удвоенная сумма: %lf\n", 2.0 * (fa(x) + fb(x)));
            break;
        case 0:
            printf("Возврат в главное меню...\n");
            break;
        default:
            printf("Неверный выбор.\n");
        }
    } while (choice != 0);
}

double fa(double x)
{
    double y;
    y = sin(x);
    return y;
}
double fb(double x)
{
    double y;
    y = cos(x);
    return y;
}



void run_task2()
{
    double x, eps, sin_std, sin_val , dev, sin_val2;
    int N, max_N;

    printf("\nЗАДАНИЕ 2\n");
    printf("Введите x (в радианах, например 0.79): ");
    scanf("%lf", &x);

    printf("Введите максимальное N для таблицы (например, 20): ");
    scanf("%d", &max_N);

    sin_std = sin(x); 


    printf("\nsin(%.2lf)\n", x);
    printf(" N |   sin_N    |  отклонение\n");
    printf("------------------------------\n");


    for (N = 1; N <= max_N; N = N + 1)
    {
        sin_val = sin_n(x, N);
        dev = sin_val - sin_std; 

        printf("%2d | %10.4lf | %+12.4le\n", N, sin_val , dev);
    }
    printf("------------------------------\n");


    printf("\nПроверка суммы с заданной точностью:\n");
    printf("Введите eps (например 0.0001): ");
    scanf("%lf", &eps);

    sin_val2 = sin_val1(x, eps);

    printf("\nСтандартная sin(x)  : %.10lf\n", sin_std);
    printf("sin_val1(x, eps)     : %.10lf\n", sin_val2);
    printf("|sin_val1 - sin(x)|   : %.10lf\n", fabs(sin_val2 - sin_std));
}

double sin_n(double x, int N)
{
    double sum = 0.0;
    double term = x;
    int k;


    for (k = 1; k <= N; k = k + 1) {
        sum = sum + term;
        term = -term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
    }
    return sum;
}

double sin_val1(double x, double eps)
{
    double sum = 0.0;
    double term = x;
    int k = 1;

    while (fabs(term) > eps) {
        sum = sum + term;
        term = -term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
        k = k + 1;
    }
    return sum;
}