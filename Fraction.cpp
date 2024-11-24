// �������� �.�.
#include <string> // ���������� �++ ��� ������ �� ��������
#include <cassert> // ���������� �++ ��� ����������� ���������� ������ � ���������(��� ������� assert)
#include "Fraction.h" // ����������� ������������� ����� ������
#include <cmath> // ���������� �++(��� ������� abs)
#include <fstream> // ���������� �++ ��� ������ � �������

// ����������� �� ���������
Fraction::Fraction()
{
    num = 0; // �� ��������� ��������� ����� 0
    den = 1; // �� ��������� ����������� ����� 1
}

/// ����������� � �����������
/// int numinator - ���������, int denominator - �����������
Fraction::Fraction(int numinator, int denominator)
{
    set_num(numinator); // ���������
    set_den(denominator); // �����������
}

/// ����� ������������� ���������
/// int numinator - ���������
void Fraction::set_num(int numinator)
{
    num = numinator; // ������������� ���������
}

/// ����� ������������� �����������
/// int denominator - �����������
void Fraction::set_den(int denominator)
{
    if (denominator != 0) // ���� �� ����� 0
    {
        den = denominator; // ������������� �����������
    }
    else den = 1; // ����� ���������� ����� 1
}

/// ����� ��� ��������� �������� ���������
/// const ��� ����, ����� ���� ������ �� ����������
int Fraction::get_num() const
{
    return num; // ���������� ���������
}

/// ����� ��� ��������� �����������
/// const ��� ����, ����� �� ���������� ���� ������
int Fraction::get_den() const
{
    return den; // ���������� �����������
}

/// ����� ��� �������� � ������
std::string Fraction::to_string() const
{
    std::string s = std::to_string(num) + "/" + std::to_string(den); // ������� � ������ ���������/������� � ������ �����������
    return s; // ���������� �������
}

/// ����� �������� ���� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction Fraction::summ(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // ���������� ������ ����� ��� ������ ����������
    if (first_frac.get_den() != second_frac.get_den()) // ���� ����������� ������ �� �����
    {
        int new_den = first_frac.get_den() * second_frac.get_den(); // ��������� ���
        int new_num1 = first_frac.get_num() * second_frac.get_den(); // ��������� ������ ����� ���������
        int new_num2 = second_frac.get_num() * first_frac.get_den(); // ��������� ������ ����� ���������
        rez.set_den(new_den); // ���������� ����� ����������� ����������� �����
        rez.set_num(new_num1 + new_num2); // ��������� � ���������� ����� ��������� ����������� �����
    }
    else // �����(���� ����������� ������ �����)
    {
        rez.set_den(first_frac.get_den()); // �� ����� ����������� ���� ����������� ������ �����
        int num1 = first_frac.get_num(); // ����������� ���������� ��������� ������ �����
        int num2 = second_frac.get_num(); // ����������� ���������� ��������� ������ �����
        rez.set_num(num1 + num2); // ��������� ����� ���������
    }
    return rez; // ���������� ���������
}

/// ����� ������������ ���� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction Fraction::comp(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // ���������� ������ ����� ��� ������ ����������
    int new_num = first_frac.get_num() * second_frac.get_num(); // �������� ��������� ������ ����� �� ��������� ������ �����
    int new_den = first_frac.get_den() * second_frac.get_den(); // �������� ����������� ������ ����� �� ����������� ������ �����
    rez.set_num(new_num); // ���������� ����� ��������� ����������� �����
    rez.set_den(new_den); // ���������� ����� ����������� ����������� �����
    return rez; // ���������� ���������
}

/// ����� �������� ���� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction Fraction::minus(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // ���������� ������ ����� ��� ������ ����������
    if (first_frac.get_den() != second_frac.get_den()) // ���� ����������� �� �����
    {
        int new_den = first_frac.get_den() * second_frac.get_den(); // ��������� ���
        int new_num1 = first_frac.get_num() * second_frac.get_den(); // ��������� ������ ����� ���������
        int new_num2 = second_frac.get_num() * first_frac.get_den(); // ��������� ������ ����� ���������
        rez.set_den(new_den); // ���������� ����� ����������� ����������� �����
        rez.set_num(new_num1 - new_num2); // ��������� � ���������� ����� ��������� ����������� �����
    }
    else // �����(���� ����������� ������ �����)
    {
        rez.set_den(first_frac.get_den()); // �� ����� ����������� ���� ����������� ������ �����
        int num1 = first_frac.get_num(); // ����������� ���������� ��������� ������ �����
        int num2 = second_frac.get_num(); // ����������� ���������� ��������� ������ �����
        rez.set_num(num1 - num2); // ��������� ����� ���������
    }
    return rez; // ���������� ���������
}

/// ����� ������� ���� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction Fraction::divis(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez; // ���������� ������ ����� ��� ������ ����������
    int new_num = first_frac.get_num() * second_frac.get_den(); // �������� ��������� ������ ����� �� ����������� ������ �����
    int new_den = first_frac.get_den() * second_frac.get_num(); // �������� ����������� ������ ����� �� ��������� ������ �����
    rez.set_num(new_num); // ���������� ����� ��������� ����������� �����
    rez.set_den(new_den); // ���������� ����� ����������� ����������� �����
    return rez; // ���������� ���������
}

/// ����� ��������� ���� ������
/// const Fraction& second_frac - �����, const ����� �� ����������
std::string Fraction::compars(const Fraction& second_frac) const
{
    double firstnum = get_num(); // ����������� ���������� ��������� ������ �����
    double firstden = get_den(); // ����������� ���������� ����������� ������ �����
    double secnum = second_frac.get_num(); // ����������� ���������� ��������� ������ �����
    double secden = second_frac.get_den(); // ����������� ���������� ����������� ������ �����
    if ((firstnum/firstden) > (secnum/secden)) // �������������� ������������ ������ � ���������� �����, ���� ������ ����� ������ ������
    {
        return "������ ����� ������ ������"; // �����
    }
    else if ((firstnum / firstden) < (secnum / secden)) // �������������� ������������ ������ � ���������� �����, ���� ������ ����� ������ ������
    {
        return "������ ����� ������ ������"; // �����
    }
    else if ((firstnum / firstden) == (secnum / secden)) // �������������� ������������ ������ � ���������� �����, ���� ����� �����
    {
        return "����� �����"; // �����
    }
}

/// ����� �������� � ���������� �����
float Fraction::dec() const
{
    float rez; // ���������� ��� ������ ����������
    rez = (get_num() + 0.0) / get_den(); // ����� ��������� ����� �� ����������� �����
    return rez; // ���������� ���������
}

/// ���������� ���������� ��� ������
/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.summ(first_frac, second_frac); // ����� ������ �������� ���� ������
    return rez; // ����������� ����������
}

/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.minus(first_frac, second_frac); // ����� ������ �������� ���� ������
    return rez; // ����������� ����������
}

/// ���������� ��������� ��������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.comp(first_frac, second_frac); // ����� ������ ������������ ���� ������
    return rez; // ����������� ����������
}

/// ���������� ��������� ������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac)
{
    Fraction rez = rez.divis(first_frac, second_frac); // ����� ������ ������� ���� ������
    return rez; // ����������� ����������
}

/// ����� ������ � ����
/// std::string& filename - ��� �����
void Fraction::Save_Frac(std::string& filename) const
{
    std::ofstream savef(filename); // �������� �����
    if (!savef.is_open()) // ���� �� ��������
    {
        throw "�� ������� ������� ���� ��� ������"; // ������� ��������� �� ������
    }
    else // �����
    {
        savef << get_num() << "\n"; // ���������� � ���� ���������
        savef << get_den() << "\n"; // ���������� � ���� �����������
        savef.close(); // ��������� ����
    }
}

/// ����� ���������� �� �����
/// std::string& filename - ��� �����
Fraction Fraction::Load_Frac(std::string& filename)
{
    std::ifstream loadf(filename); // ��������� ����
    if (!loadf.is_open()) // ���� �� ��������
    {
        throw "�� ������� ������� ���� ��� ������"; // ������� ��������� �� ������
    }
    else // �����
    {
        int n, d; // ���������� ���� int, n - ���������, d - �����������
        loadf >> n >> d; // ������ �� ����� ��������� � �����������
        set_num(n); // ���������� ���������
        set_den(d); // ���������� �����������
        loadf.close(); // ��������� ����
    }
}

void test() {
    Fraction test1(2, 5); // ����� ������ �����
    Fraction test2(3, 6); // ����� ������ �����
    Fraction rezsum = test1 + test2; // ����� ���� ������
    Fraction rezmin = test1 - test2; // �������� ���� ������
    Fraction rezcomp = test1 * test2; // ������������ ���� ������
    Fraction rezdivis = test1 / test2; // ������� ���� ������
    assert(abs(test1.get_num() - 2) < 0.0001); // �������� ������������ � ������� ��� ���������
    assert(abs(test1.get_den() - 5) < 0.0001); // �������� ������������ � ������� ��� �����������
    assert(abs(rezsum.dec() - 0.9) < 0.0001); // �������� ������ �������� ������
    assert(abs(rezmin.dec() - (-0.1)) < 0.0001); // �������� ������ �������� ������
    assert(abs(rezcomp.dec() - 0.2) < 0.0001); // �������� ������ ������������ ������
    assert(abs(rezdivis.dec() - 0.8) < 0.0001); // �������� ������ ������� ������
    assert(test1.compars(test2) == "������ ����� ������ ������"); // �������� ������ ��������� ������
}