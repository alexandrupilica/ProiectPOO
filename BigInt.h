#include <iostream>
#include <string>
#include <vector>
#define MAXDIGITS 1000


class BigInt
{
private:
    char Digits[MAXDIGITS];
    bool sign;
    int base;
    int length;
public:
    int GetBase();
    bool GetSign();
    int GetLength();

    BigInt(int digits);
    BigInt(long long int &nr, int base, bool sign);
    BigInt(std::string s);

    friend BigInt& operator+(BigInt &number);
    friend BigInt& operator-(BigInt &number);

    BigInt& operator+=(BigInt &number);
    BigInt& operator+=(const int &integer);

    BigInt& operator-=(const BigInt &number);
    BigInt& operator-=(const int &integer);

    BigInt& operator*=(const BigInt &number);
    BigInt& operator*=(const int &integer);

    BigInt& operator/=(const BigInt &number);
    BigInt& operator/=(const int &integer);

    BigInt& operator%=(BigInt &number1);
    BigInt& operator%=(const int &integer);

    friend std::istream& operator>>(std::istream &in, BigInt &number);
    friend std::ostream& operator<<(std::ostream &out, BigInt &number);

    friend BigInt& operator+(BigInt &number1, BigInt &number2);
    friend BigInt& operator+(const int &integer, BigInt &number2);
    friend BigInt& operator+(BigInt &number1, const int &integer);

    friend BigInt& operator-(BigInt &number1, BigInt &number2);
    friend BigInt& operator-(const int &integer, BigInt &number2);
    friend BigInt& operator-(BigInt &number1, const int &integer);

    friend BigInt& operator/(BigInt &number1, BigInt &number2);
    friend BigInt& operator/(const int &integer, BigInt &number2);
    friend BigInt& operator/(BigInt &number1, const int &integer);

    friend BigInt& operator%(BigInt &number1, BigInt &number2);
    friend BigInt& operator%(const int &integer, BigInt &number2);
    friend BigInt& operator%(BigInt &number1, const int &integer);

    friend BigInt& operator^(BigInt &number1, BigInt &number2);
    friend BigInt& operator^(const int &integer, BigInt &number2);
    friend BigInt& operator^(BigInt &number1, const int &integer);

    friend bool operator ==(const BigInt &number1, const BigInt &number2);
    friend bool operator ==(const int &integer, const BigInt &number2);
    friend bool operator ==(const BigInt &number1, const int &integer);

    friend bool operator !=(const BigInt &number1, const BigInt &number2);
    friend bool operator !=(const int &integer, const BigInt &number2);
    friend bool operator !=(const BigInt &number1, const int &integer);

    friend bool operator > (const BigInt &number1, const BigInt &number2);
    friend bool operator > (const int &integer, const BigInt &number2);
    friend bool operator > (const BigInt &number1, const int &integer);

    friend bool operator < (const BigInt &number1, const BigInt &number2);
    friend bool operator < (const int &integer, const BigInt &number2);
    friend bool operator < (const BigInt &number1, const int &integer);

    friend bool operator >= (const BigInt &number1, const BigInt &number2);
    friend bool operator >= (const int &integer, const BigInt &number2);
    friend bool operator >= (const BigInt &number1, const int &integer);

    friend bool operator <= (const BigInt &number1, const BigInt &number2);
    friend bool operator <= (const int &integer, const BigInt &number2);
    friend bool operator <= (const BigInt &number1, const int &integer);

    bool NullElement(const BigInt &number);

};


