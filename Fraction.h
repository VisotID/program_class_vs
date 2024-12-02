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
    /// const ��� ����, ����� �� ���������� ���� ������ num - ���������
    int get_num() const;

    /// ����� ��� ��������� �����������
    /// const ��� ����, ����� �� ���������� ���� ������ den - �����������
    int get_den() const;

    /// ����� ��� �������� � ������
    /// const ��� ����, ����� �� ���������� ���� ������
    std::string to_string() const;

    /// ����� �������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
    Fraction summ(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ������������ ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
    Fraction comp(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� �������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
    Fraction minus(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ������� ���� ������
    /// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
    Fraction divis(const Fraction& first_frac, const Fraction& second_frac);

    /// ����� ��������� ���� ������
    /// const Fraction& second_frac - �����, const ����� �� ���������� �����, ������� �� ������, ������ ��� ������� ������ ������ 
    /// 0 - ����� �����, 1 - ������ ����� ������ ������, -1 - ������ ����� ������ ������
    int compars(const Fraction& second_frac) const;

    /// ����� �������� � ���������� �����
    /// const ��� ����, ����� �� ���������� ���� ������
    float dec() const;

    /// ����� ������ � ����
    /// std::string& filename - ��� �����, ������� �� ������, ������ ��� ������� ������ ������
    /// ���������� 1 - ������ �������� �����
    int Save_Frac(std::string& filename) const;

    /// ����� ���������� �� �����
    /// std::string& filename - ��� �����, ������� �� ������, ������ ��� ������� ������ ������
    /// ���������� 1 - ���� �� ��� ������
    int Load_Frac(std::string& filename);
};

/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
Fraction operator +(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� �������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
Fraction operator -(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� ��������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
Fraction operator *(const Fraction& first_frac, const Fraction& second_frac);

/// ���������� ��������� ������� ��� ������
/// const Fraction& first_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������, const Fraction& second_frac - ������ �����, const ����� �� ���������� ���� ������, ������� �� ������, ������ ��� ������� ������ ������
Fraction operator /(const Fraction& first_frac, const Fraction& second_frac);

/// ������� �������� ������ ���������
void test();

/// ������� �������� �������
void testdevis();