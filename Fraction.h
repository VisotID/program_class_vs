// �������� �.�.
#pragma once // ��������� � �++, ��� �������������� ������������� ��������� ������ � ���� �� ������������� �����
#include <string> // ���������� �++ ��� ������ �� ��������

// ����� -  �������� ����� � �������(���� - ������, ������ - �������)
class Fraction
{
    // ������� ������, ��� ������ �������� �� ������� �������, ������������� ��� ������(������� ��������)
private:
    int num; // ���������
    int den; // �����������
    // ������� ������, ������ � ������� �������� �� ��������� ������
public:

    // ����������� �� ���������
    Fraction();

    /// ����������� � �����������
    /// int numinator - ���������, int denominator - �����������
    Fraction(int numinator, int denominator);

    /// ����� ������������� ���������
    /// int numinator - ���������
    void set_num(int numinator);

    /// ����� ������������� �����������
    /// int denominator - �����������
    void set_den(int denominator);

    /// ����� ��� ��������� �������� ���������
    int get_num() const;

    /// ����� ��� ��������� �����������
    int get_den() const;

    /// ����� ��� �������� � ������
    std::string to_string() const;

    /// ����� �������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
    Fraction summ(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ������������ ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
    Fraction comp(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� �������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
    Fraction minus(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
    Fraction divis(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ��������� ���� ������
    /// const Fraction& second_frac - �����, const ����� �� ����������
    int compars(const Fraction& second_frac) const;

    /// ����� �������� � ���������� �����
    float dec() const;

    /// ����� ������ � ����
    /// std::string& filename - ��� �����
    int Save_Frac(std::string& filename) const;

    /// ����� ���������� �� �����
    /// std::string& filename - ��� �����
    int Load_Frac(std::string& filename);
};

/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� ��������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� ������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ����������, const Fraction& second_frac - ������ �����, const ����� �� ����������
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac);

/// ������� �������� ������ ���������
void test();