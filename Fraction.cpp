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
/// const для того, чтобы не изменилось поле класса num - числитель
int Fraction::get_num() const
{
    return num; // возвращаем числитель
}

/// Метод для просмотра знаменателя
/// const для того, чтобы не изменилось поле класса den - знаменатель
int Fraction::get_den() const
{
    return den; // возвращаем знаменатель
}

/// Метод для перевода в строку
/// const для того, чтобы не изменились поля класса
std::string Fraction::to_string() const
{
    std::string s = std::to_string(num) + "/" + std::to_string(den); // перевод в строку числителя/перевод в строку знаменателя
    return s; // возвращаем строчку
}

/// Метод сложения двух дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
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
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
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
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
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
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
/// 1 - ошибка, если знаменатель равен 0
Fraction Fraction::divis(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // переменная класса дробь для записи результата
    int new_num = first_frac.get_num() * second_frac.get_den(); // умножаем числитель первой дроби на знаменатель второй дроби
    int new_den = first_frac.get_den() * second_frac.get_num(); // умножаем знаменатель первой дроби на числитель второй дроби
    if (new_den != 0)
    {
        rez.set_num(new_num); // записываем новый числитель вычисленной дроби
        rez.set_den(new_den); // записываем новый знаменатель вычисленной дроби
        return rez; // возвращаем результат
    }
    else throw 1; // кидаем сообщение об ошибке
}

/// Метод сравнения двух дробей
/// const Fraction& second_frac - дробь, const чтобы не изменялась дробь, передаём по ссылке, потому что большой размер данных 
/// 0 - дроби равны, 1 - первая дробь больше второй, -1 - вторая дробь больше первой
int Fraction::compars(const Fraction& second_frac) const
{
    double firstnum = get_num(); // присваиваем переменной числитель первой дроби
    double firstden = get_den(); // присваиваем переменной знаменатель первой дроби
    double secnum = second_frac.get_num(); // присваиваем переменной числитель второй дроби
    double secden = second_frac.get_den(); // присваиваем переменной знаменатель второй дроби
    if ((firstnum/firstden) > (secnum/secden)) // преобразование обыкновенных дробей в десятичные дроби, если первая дробь больше второй
    {
        return 1; // ответ
    }
    else if ((firstnum / firstden) < (secnum / secden)) // преобразование обыкновенных дробей в десятичные дроби, если первая дробь меньше второй
    {
        return -1; // ответ
    }
    else if ((firstnum / firstden) == (secnum / secden)) // преобразование обыкновенных дробей в десятичные дроби, если дроби равны
    {
        return 0; // ответ
    }
}

/// Метод перевода в десятичную дробь
/// const для того, чтобы не изменились поля класса
float Fraction::dec() const
{
    float rez; // переменная для записи результата
    rez = (get_num() + 0.0) / get_den(); // делим числитель дроби на знаменатель дроби
    return rez; // возвращаем результат
}

/// Перегрузки операторов вне класса
/// Перегрузка оператора сложения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.summ(first_frac, second_frac); // вызов метода сложения двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора разности для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.minus(first_frac, second_frac); // вызов метода разности двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора умножения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.comp(first_frac, second_frac); // вызов метода перемножения двух дробей
    return rez; // возвращение результата
}

/// Перегрузка оператора деления для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.divis(first_frac, second_frac); // вызов метода деления двух дробей
    return rez; // возвращение результата
}

/// Метод записи в файл
/// std::string& filename - имя файла, передаём по ссылке, потому что большой размер данных
/// возвращаем 1 - ошибка открытия файла
int Fraction::Save_Frac(std::string& filename) const
{
    std::ofstream savef(filename); // открытие файла, ofstream для записи в файл
    if (!savef.is_open()) // если файл не открылся
    {
        return 1; // возвращаем 1
    }
    else // иначе
    {
        savef << get_num() << "\n"; // записываем в файл числитель
        savef << get_den() << "\n"; // записываем в файл знаменатель
        savef.close(); // закрываем файл
        return 0; // возвращаем 0
    }
}

/// Метод извлечения из файла
/// std::string& filename - имя файла, передаём по ссылке, потому что большой размер данных
/// возвращаем 1 - файл не был найден
int Fraction::Load_Frac(std::string& filename)
{
    std::ifstream loadf(filename); // открываем файл, ifstream для чтения из файла
    if (!loadf.is_open()) // если файл не открылся
    {
        return 1; // возвращаем 1
    }
    else // иначе
    {
        int n, d; // переменные типа int, n - числитель, d - знаменатель
        loadf >> n >> d; // чтение из файла числителя и знаменателя
        set_num(n); // записываем числитель
        set_den(d); // записываем знаменатель
        loadf.close(); // закрываем файл
        return 0; // возвращаем 0
    }
}

/// Функция проверки деления
/// если бросаем исключение,переходим в catch, если нет идём дальше по коду и аварийно завершаем программу
void testdevis()
{
    Fraction test3(1, 1); // задаём первую дробь
    Fraction test4(0, 2); // задаём вторую дробь
    try
    {
        Fraction testdevis = test3 / test4; // делим
        assert(0); // аварийно завершаем программу
    }
    catch (int) {}
}

/// Функция проверки работы программы
void test() {
        std::string namef = "test1.txt";
        std::string namet = "test.txt";
        Fraction test1(2, 5); // задаём первую дробь
        Fraction test2(3, 6); // задаём вторую дробь
        Fraction test3(1, 1); // задаём первую дробь
        Fraction test4(0, 2); // задаём вторую дробь
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
        assert(test1.compars(test2) == -1); // проверка метода сравнения дробей
        assert(test1.Load_Frac(namet) == 0); // проверка метода извлечения из файла
        assert(test1.Load_Frac(namef) == 1); // проверка метода извлечения из файла
        assert(test2.Save_Frac(namet) == 0); // проверка метода сохранения в файл
        
    }