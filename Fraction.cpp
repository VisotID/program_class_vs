// Высоцкая И.Д.
#include <string> // библиотека С++ для работы со строками
#include <cassert> // библиотека С++ для обнаружения логических ошибок в программе(для функции assert)
#include "Fraction.h" // подключение заголовочного файла модуля
#include <cmath> // библиотека С++(для функции abs)
#include <fstream> // библиотека С++ для работы с файлами

// Конструктор по умолчанию
Fraction::Fraction()
{
    num = 0; // по умолчанию числитель равен 0
    den = 1; // по умолчанию знаменатель равен 1
}

/// Конструктор с параметрами
/// int numinator - числитель, int denominator - знаменатель
Fraction::Fraction(int numinator, int denominator)
{
    set_num(numinator); // числитель
    set_den(denominator); // знаменатель
}

/// Метод инициализации числителя
/// int numinator - числитель
void Fraction::set_num(int numinator)
{
    num = numinator; // инициализация числителя
}

/// Метод инициализации знаменателя
/// int denominator - знаменатель
void Fraction::set_den(int denominator)
{
    if (denominator != 0) // если не равен 0
    {
        den = denominator; // инициализация знаменателя
    }
    else den = 1; // иначе становится равен 1
}

/// Метод для просмотра значения числителя
/// const для того, чтобы поля класса не изменялись
int Fraction::get_num() const
{
    return num; // возвращаем числитель
}

/// Метод для просмотра знаменателя
/// const для того, чтобы не изменялись поля класса
int Fraction::get_den() const
{
    return den; // возвращаем знаменатель
}

/// Метод для перевода в строку
std::string Fraction::to_string() const
{
    std::string s = std::to_string(num) + "/" + std::to_string(den); // перевод в строку числителя/перевод в строку знаменателя
    return s; // возвращаем строчку
}

/// Метод сложения двух дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction Fraction::summ(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // переменная класса дробь для записи результата
    if (first_frac.get_den() != second_frac.get_den()) // если знаменатели дробей не равны
    {
        int new_den = first_frac.get_den() * second_frac.get_den(); // вычисляем НОЗ
        int new_num1 = first_frac.get_num() * second_frac.get_den(); // вычисляем первый новый числитель
        int new_num2 = second_frac.get_num() * first_frac.get_den(); // вычисляем второй новый числитель
        rez.set_den(new_den); // записываем новый знаменатель вычисленной дроби
        rez.set_num(new_num1 + new_num2); // вычисляем и записываем новый числитель вычисленной дроби
    }
    else // иначе(если знаменатели дробей равны)
    {
        rez.set_den(first_frac.get_den()); // за новый знаменатель берём знаменатель первой дроби
        int num1 = first_frac.get_num(); // присваиваем переменной числитель первой дроби
        int num2 = second_frac.get_num(); // присваиваем переменной числитель второй дроби
        rez.set_num(num1 + num2); // вычисляем новый числитель
    }
    return rez; // возвращаем результат
}

/// Метод перемножения двух дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction Fraction::comp(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // переменная класса дробь для записи результата
    int new_num = first_frac.get_num() * second_frac.get_num(); // умножаем числитель первой дроби на числитель второй дроби
    int new_den = first_frac.get_den() * second_frac.get_den(); // умножаем знаменатель первой дроби на знаменатель второй дроби
    rez.set_num(new_num); // записываем новый числитель вычисленной дроби
    rez.set_den(new_den); // записываем новый знаменатель вычисленной дроби
    return rez; // возвращаем результат
}

/// Метод разности двух дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction Fraction::minus(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // переменная класса дробь для записи результата
    if (first_frac.get_den() != second_frac.get_den()) // если знаменатели не равны
    {
        int new_den = first_frac.get_den() * second_frac.get_den(); // вычисляем НОЗ
        int new_num1 = first_frac.get_num() * second_frac.get_den(); // вычисляем первый новый числитель
        int new_num2 = second_frac.get_num() * first_frac.get_den(); // вычисляем второй новый числитель
        rez.set_den(new_den); // записываем новый знаменатель вычисленной дроби
        rez.set_num(new_num1 - new_num2); // вычисляем и записываем новый числитель вычисленной дроби
    }
    else // иначе(если знаменатели дробей равны)
    {
        rez.set_den(first_frac.get_den()); // за новый знаменатель берём знаменатель первой дроби
        int num1 = first_frac.get_num(); // присваиваем переменной числитель первой дроби
        int num2 = second_frac.get_num(); // присваиваем переменной числитель второй дроби
        rez.set_num(num1 - num2); // вычисляем новый числитель
    }
    return rez; // возвращаем результат
}

/// Метод деления двух дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction Fraction::divis(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // переменная класса дробь для записи результата
    int new_num = first_frac.get_num() * second_frac.get_den(); // умножаем числитель первой дроби на знаменатель второй дроби
    int new_den = first_frac.get_den() * second_frac.get_num(); // умножаем знаменатель первой дроби на числитель второй дроби
    rez.set_num(new_num); // записываем новый числитель вычисленной дроби
    rez.set_den(new_den); // записываем новый знаменатель вычисленной дроби
    return rez; // возвращаем результат
}

/// Метод сравнения двух дробей
/// const Fraction& second_frac - дробь, const чтобы не изменялась
std::string Fraction::compars(const Fraction& second_frac) const
{
    double firstnum = get_num(); // присваиваем переменной числитель первой дроби
    double firstden = get_den(); // присваиваем переменной знаменатель первой дроби
    double secnum = second_frac.get_num(); // присваиваем переменной числитель второй дроби
    double secden = second_frac.get_den(); // присваиваем переменной знаменатель второй дроби
    if ((firstnum/firstden) > (secnum/secden)) // преобразование обыкновенных дробей в десятичные дроби, если первая дробь больше второй
    {
        return "первая дробь больше второй"; // ответ
    }
    else if ((firstnum / firstden) < (secnum / secden)) // преобразование обыкновенных дробей в десятичные дроби, если первая дробь меньше второй
    {
        return "вторая дробь больше первой"; // ответ
    }
    else if ((firstnum / firstden) == (secnum / secden)) // преобразование обыкновенных дробей в десятичные дроби, если дроби равны
    {
        return "дроби равны"; // ответ
    }
}

/// Метод перевода в десятичную дробь
float Fraction::dec() const
{
    float rez; // переменная для записи результата
    rez = (get_num() + 0.0) / get_den(); // делим числитель дроби на знаменатель дроби
    return rez; // возвращаем результат
}

/// Перегрузки операторов вне класса
/// Перегрузка оператора сложения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.summ(first_frac, second_frac); // вызов метода сложения двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора разности для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.minus(first_frac, second_frac); // вызов метода разности двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора умножения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.comp(first_frac, second_frac); // вызов метода перемножения двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора деления для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялась, const Fraction& second_frac - вторая дробь, const чтобы не изменялась
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.divis(first_frac, second_frac); // вызов метода деления двух дробей
    return rez; // возвращение результата
}

/// Метод записи в файл
/// std::string& filename - имя файла
void Fraction::Save_Frac(std::string& filename) const
{
    std::ofstream savef(filename); // открытие файла
    if (!savef.is_open()) // если не открылся
    {
        throw "Не удается открыть файл для записи"; // бросаем сообщение об ошибке
    }
    else // иначе
    {
        savef << get_num() << "\n"; // записываем в файл числитель
        savef << get_den() << "\n"; // записываем в файл знаменатель
        savef.close(); // закрываем файл
    }
}

/// Метод извлечения из файла
/// std::string& filename - имя файла
Fraction Fraction::Load_Frac(std::string& filename)
{
    std::ifstream loadf(filename); // открываем файл
    if (!loadf.is_open()) // если не открылся
    {
        throw "Не удается открыть файл для чтения"; // бросаем сообщение об ошибке
    }
    else // иначе
    {
        int n, d; // переменные типа int, n - числитель, d - знаменатель
        loadf >> n >> d; // чтение из файла числителя и знаменателя
        set_num(n); // записываем числитель
        set_den(d); // записываем знаменатель
        loadf.close(); // закрываем файл
    }
}

void test() {
    Fraction test1(2, 5); // задаём первую дробь
    Fraction test2(3, 6); // задаём вторую дробь
    Fraction rezsum = test1 + test2; // сумма двух дробей
    Fraction rezmin = test1 - test2; // разность двух дробей
    Fraction rezcomp = test1 * test2; // произведение двух дробей
    Fraction rezdivis = test1 / test2; // деление двух дробей
    assert(abs(test1.get_num() - 2) < 0.0001); // проверка конструктора и геттера для числителя
    assert(abs(test1.get_den() - 5) < 0.0001); // проверка конструктора и геттера для знаменателя
    assert(abs(rezsum.dec() - 0.9) < 0.0001); // проверка метода сложения дробей
    assert(abs(rezmin.dec() - (-0.1)) < 0.0001); // проверка метода разности дробей
    assert(abs(rezcomp.dec() - 0.2) < 0.0001); // проверка метода перемножения дробей
    assert(abs(rezdivis.dec() - 0.8) < 0.0001); // проверка метода деления дробей
    assert(test1.compars(test2) == "вторая дробь больше первой"); // проверка метода сравнения дробей
}