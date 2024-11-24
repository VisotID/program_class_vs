﻿// Высоцкая И.Д.
// Работа с обыкновенными дробями(сложение, вычитание, умножение, деление, сравнение)
// директива include отвечает за включение в компилируемый файл содержимое другого файла
#include <iostream> // библиотека С++, отвечающая за чтение и запись(для функций cin - функция чтения, cout - функция вывода)
#include <clocale> // библиотека С++, отвечающая за локализацию, нужна для подключения русского языка
#include "Fraction.h" // подключение заголовочного файла модуля

using namespace std; // используем пространство имен std для того, чтобы не писать перед функциями cin, cout "std"

/// Функция вывода на экран
void print_frac(const Fraction& Fract)
{
    cout << Fract.to_string() << "\n"; // вывод на экран
}

// главная часть программы
int main()
{
    setlocale(LC_ALL, "rus"); // задание локализации для русского языка
    // вывод на экран дроби, заданной по умолчанию
    Fraction First; // переменная типа Fraction
    cout << "Дробь по умолчанию: \n"; // вывод на экран
    print_frac(First); // вызов функции вывода на экран
    cout << "\n"; // перенос на другую строчку

    Fraction* First_d = new Fraction(5,6); // создание динамической переменной
    cout << "Динамическая переменная: \n"; // вывод на экран
    print_frac(*First_d); // вывод на экран дроби
    delete First_d; // очищение памяти
    cout << "\n"; // перенос на другую строчку

    First.set_num(4); // меняем числитель на 4
    cout << First.get_num() << "\n"; // вывод на экран числителя
    cout << "Статическая переменная: \n"; // вывод на экран
    print_frac(First); // вывод на экран
    cout << "\n"; // перенос на другую строчку

    string file = "test.txt"; // переменная для файла
    First.Save_Frac(file); // сохранение дроби в файл
    Fraction Six; // создание переменной
    Six.Load_Frac(file); // чтение из файла
    cout << "Из файла:"; // вывод на экран
    print_frac(Six); // вывод на экран
    cout << "\n"; // перенос на другую строчку

    Fraction Second[5]; // создание статического массива из 5 элементов
    Second[2].set_den(6); // меняем знаменатель второго элемента на 6
    cout << "Статический массив: \n"; // вывод на экран
    for (int i = 0; i < 5; i++)
    {
        print_frac(Second[i]); // вывод на экран массива
    }
    cout << "\n"; // перенос на другую строчку

    Fraction* Third = new Fraction[4]; // создание динамического массива из 4 элементов
    Third[1].set_num(90); // меняем числитель 1 элемента на 90
    cout << "Динамический массив: \n"; // вывод на экран
    for (int i = 0; i < 4; i++)
    {
        print_frac(Third[i]); // вывод на экран массива
    }
    delete[] Third; // очищение памяти
    cout << "\n"; // перенос на другую строчку

    Fraction* Fourth[3]; // создание массива из 3 указателей
    for (int i = 0; i < 3; i++)
    {
        Fourth[i] = new Fraction(5, 9); // создали 3 одинаковых элемента
        cout << Fourth[i]->to_string() << "\n"; // вывод на экран
    }
    // очищение памяти
    for (int i = 0; i < 3; i++)
    {
        delete Fourth[i];
    }



    cout << "\nРабота с дробями: \n"; // вывод на экран
    Fraction ff; // первая дробь
    Fraction fs; // вторая дробь
    ff.set_num(2); // числитель первой дроби
    ff.set_den(5); // знаменатель первой дроби
    fs.set_num(3); // числитель второй дроби
    fs.set_den(6); // знаменатель второй дроби
    cout << "Сумма: \n"; // вывод на экран
    Fraction fsum = ff + fs; // сложение дробей
    print_frac(fsum); // вывод результата на экран
    cout << "Произведение: \n"; // вывод на экран
    Fraction fcomp = ff * fs; // произведение дробей
    print_frac(fcomp); // вывод результата на экран
    cout << "Разность: \n"; // вывод на экран
    Fraction fmin = ff - fs; // разность дробей
    print_frac(fmin); // вывод результата на экран
    cout << "Деление: \n"; // вывод на экран
    Fraction fdiv = ff / fs; // деление дробей
    print_frac(fdiv); // вывод результата на экран
    cout << "Сравнение: \n"; // вывод на экран
    cout << ff.compars(fs); // вывод результата на экран

    return 0;
}