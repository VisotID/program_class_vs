// Высоцкая И.Д.
#pragma once // директива в С++, для предотвращения многократного включения одного и того же заголовочного файла
#include <string> // библиотека С++ для работы со строками

// Класс -  общность полей и методов(поля - данные, методы - функции)
class Fraction
{
    // область класса, где данные защищены от доступа функций, расположенных вне класса(принцип сокрытия)
private:
    int num; // числитель
    int den; // знаменатель
    // область класса, данные в которой доступны за пределами класса
public:

    // Конструктор по умолчанию
    Fraction();

    /// Конструктор с параметрами
    /// int numinator - числитель, int denominator - знаменатель
    Fraction(int numinator, int denominator);

    /// Метод инициализации числителя
    /// int numinator - числитель
    void set_num(int numinator);

    /// Метод инициализации знаменателя
    /// int denominator - знаменатель
    void set_den(int denominator);

    /// Метод для просмотра значения числителя
    /// const для того, чтобы не изменилось поле класса num - числитель
    int get_num() const;

    /// Метод для просмотра знаменателя
    /// const для того, чтобы не изменилось поле класса den - знаменатель
    int get_den() const;

    /// Метод для перевода в строку
    /// const для того, чтобы не изменились поля класса
    std::string to_string() const;

    /// Метод сложения двух дробей
    /// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
    Fraction summ(const Fraction& first_frac, const Fraction& second_frac);

    /// Метод перемножения двух дробей
    /// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
    Fraction comp(const Fraction& first_frac, const Fraction& second_frac);

    /// Метод разности двух дробей
    /// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
    Fraction minus(const Fraction& first_frac, const Fraction& second_frac);

    /// Метод деления двух дробей
    /// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
    Fraction divis(const Fraction& first_frac, const Fraction& second_frac);

    /// Метод сравнения двух дробей
    /// const Fraction& second_frac - дробь, const чтобы не изменялась дробь, передаём по ссылке, потому что большой размер данных 
    /// 0 - дроби равны, 1 - первая дробь больше второй, -1 - вторая дробь больше первой
    int compars(const Fraction& second_frac) const;

    /// Метод перевода в десятичную дробь
    /// const для того, чтобы не изменились поля класса
    float dec() const;

    /// Метод записи в файл
    /// std::string& filename - имя файла, передаём по ссылке, потому что большой размер данных
    /// возвращаем 1 - ошибка открытия файла
    int Save_Frac(std::string& filename) const;

    /// Метод извлечения из файла
    /// std::string& filename - имя файла, передаём по ссылке, потому что большой размер данных
    /// возвращаем 1 - файл не был найден
    int Load_Frac(std::string& filename);
};

/// Перегрузка оператора сложения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac);

/// Перегрузка оператора разности для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac);

/// Перегрузка оператора умножения для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac);

/// Перегрузка оператора деления для дробей
/// const Fraction& first_frac - первая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных, const Fraction& second_frac - вторая дробь, const чтобы не изменялось поле класса, передаём по ссылке, потому что большой размер данных
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac);

/// Функция проверки работы программы
void test();

/// Функция проверки деления
void testdevis();