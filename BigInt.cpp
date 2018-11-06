#include <iostream>
#include <string>
#include <vector>
#define MAXDIGITS 1000

int BigInt::GetBase()
{
    return this->base;
}

bool BigInt::GetSign()
{
    return this->sign;
}

int BigInt::GetLength()
{
    return this->length;
}

bool BigInt::NullElement(const BigInt& number)
{
    return number.GetLength() == 1 && number.Digits[0] == 0;
}

BigInt::BigInt(int cifre)
{
    this->length=cifre;
    this->sign = 1;
    this->base = 10;
}

BigInt::BigInt(long long int &nr, int base = 10, bool sign = 1)
{
    int digit;
    char char_digit;


    this->sign = 1;
    this->base = 10;
    this->length = 0;


    while (nr > 0)
    {
        digit = nr % 10;
        char_digit = digit + '0';
        this->Digits[this->length]=char_digit;
        nr = nr / 10;
        this->length++;
    }
}

BigInt::BigInt(std::string s)
{
    memset(Digits, '0', MAXDIGITS);
    length = s.length();
    if (length > MAXDIGITS)
        throw ("OVERFLOW");
    if(length)
        for (int i = length; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
                Digits[length - i - 1] = s[i] - '0';
            else
                throw ("INVALID NUMBER");

        }
    else
        length = 1;
}


BigInt& operator+(BigInt &number)
{
    return number;
}

BigInt& operator-(BigInt &number)
{
    if (number.sign == 1)
        number.sign = 0;
    else
        number.sign = 1;

    return number;
}

std::istream& operator>>(std::istream &in, BigInt &number)
{
    std::cout<<"nr=";
    long long int nr;
    std::cin>>nr;

    int digit;
    int it=0;
    char digitCharacter;

    while (nr > 0)
    {

        digit = nr % 10;
        nr = nr / 10;
        this->length++;
        digitCharacter = digit + '0';
        number.Digits[it]=digitCharacter;
        it++;
    }

    return in;
}

std::ostream& operator<<(std::ostream &out, BigInt &number)
{
    for(int i=number.length-1; i>=0; i--)
    {
        out<<number.Digits[i];

    }

    out<<number.length;

    out<<std::endl;
    return out;
}

BigInt& BigInt::operator+=(BigInt &number)
{
    int t = 0, s, i;
    int n = this->GetLength();
    int m = number.GetLength();
    if (this->GetLength() > number.GetLength())
        this->GetLength() = number.GetLength();
    for (i = 0; i < this->GetLength(); i++)
    {
        s = this->Digits[i] + number.Digits[i] + t;
        t = s / 10;
        this->Digits[i] = s % 10;
    }
    if (t)
    {
        if (this->GetLength() == MAXDIGITS)
            throw ("OVERFLOW");
        this->Digits[this->GetLength()++] = s % 10;
    }
    return *this;
}

BigInt& BigInt::operator+=(const int &integer)
{
    int t = 0, s, i;
    BigInt number(integer);
    int n = this->GetLength;
    int m = number.GetLength;
    if (this->GetLength() > number.GetLength())
        this->GetLength() = number.GetLength();
    for (i = 0; i < this->GetLength(); i++)
    {
        s = this->Digits[i] + number.Digits[i] + t;
        t = s / 10;
        this->Digits[i] = s % 10;
    }
    if (t)
    {
        if (this->GetLength() == MAXDIGITS)
            throw ("OVERFLOW");
        this->Digits[GetLength()++] = s % 10;
    }
    return *this;
}


BigInt& BigInt::operator-=(BigInt &number)
{
    int t = 0, s, i;
    int n = this->Get.Length();
    int m = number.GetLength();
    if (this->GetLength() < number.GetLength())
        throw("UNDERFLOW");
    if (number.GetLength() > this->GetLength())
        this->.GetLength() = number.GetLength();
    for(i = 0; i < this->GetLength(); i++)
    {
        s = this->Digits[i] - number.Digits[i] + t;
        if (s < 0)
        {
            s += 10;
            t = -1;
        }
        else
            t = 0;
        this->Digits[i] = s;
    }
    while (this->GetLength() > 1 && this->Digits[this->GetLength()] == 0)
        this->GetLength()--;
    return *this;
}

BigInt& BigInt::operator-=(const int &integer)
{
    int t = 0, s, i;
    BigInt number(integer);
    int n = this->Get.Length();
    int m = number.GetLength();
    if (this->GetLength() < number.GetLength())
        throw("UNDERFLOW");
    if (number.GetLength() > this->GetLength())
        this->.GetLength() = number.GetLength();
    for(i = 0; i < this->GetLength(); i++)
    {
        s = this->Digits[i] - number.Digits[i] + t;
        if (s < 0)
        {
            s += 10;
            t = -1;
        }
        else
            t = 0;
        this->Digits[i] = s;
    }
    while (this->GetLength() > 1 && this->Digits[this->GetLength()] == 0)
        this->GetLength()--;
    return *this;
}

BigInt& BigInt::operator*=(BigInt &number)
{
    int v[MAXDIGITS];
    int i, j, t, s;
    int n = this->GetLength();
    int m = number.GetLength();
    memset(v, 0, sizeof(int)*MAXDIGITS);
    if (NullElement(this->Digits) || NullElement(number.Digits))
    {
        this->Digits = BigInt();
        return *this;
    }
    for(i = 0; i < this->GetLength(); i++)
        for (j = 0; j < this->GetLength(); i++)
        {
            if (i + j >= MAXDIGITS)
                throw ("OVERFLOW");
            v[i + j] += this->.Digits[i] * number.Digits[j];

        }
    for (t = i = 0; i < MAXDIGITS; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
    }
    if (t)
        throw ("OVERFLOW");
    for (this->GetLength(); this->GetLength() > 1 && !v[this->GetLength() - 1]; this->GetLength()--)
        for (i = 0; i < this->GetLength(); i++)
            this->Digits[i] = v[i];

    return *this;
}

BigInt& BigInt::operator*=(const int &integer)
{
    int v[MAXDIGITS];
    BigInt number(integer);
    int i, j, t, s;
    int n = this->GetLength();
    int m = number.GetLength();
    memset(v, 0, sizeof(int)*MAXDIGITS);
    if (NullElement(this->Digits) || NullElement(number.Digits))
    {
        this->Digits = BigInt();
        return *this;
    }
    for(i = 0; i < this->GetLength(); i++)
        for (j = 0; j < this->GetLength(); i++)
        {
            if (i + j >= MAXDIGITS)
                throw ("OVERFLOW");
            v[i + j] += this->.Digits[i] * number.Digits[j];

        }
    for (t = i = 0; i < MAXDIGITS; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
    }
    if (t)
        throw ("OVERFLOW");
    for (this->GetLength(); this->GetLength() > 1 && !v[this->GetLength() - 1]; this->GetLength()--)
        for (i = 0; i < this->GetLength(); i++)
            this->Digits[i] = v[i];

    return *this;
}

BigInt& BigInt::operator/=(BigInt &number)
{
    int result[MAXDIGITS], i, ResLength = 0, AnotherDigit;
    int n = this->GetLength();
    int m = number.GetLength();
    if (NullElement(*this))
        throw ("Division by 0");
    if (this->GetLength() < number.GetLength())
    {
        return *this;
    }
    if (this.GetLength() == number.GetLength())
    {
        return *this;
    }
    BigInt t;
    for (i = this->GetLength()-1; t*10 + this->Digits[i] < number; i--)
    {
        t *= 10;
        t += this->Digits[i];
    }
    for (i = 0; i >= 0; i--)
    {
        t = t * 10 + this->Digits[i];
        for (AnotherDigit = 9; AnotherDigit*number > t; AnotherDigit--);
        t -= AnotherDigit * number;
        result[ResLength++] = AnotherDigit;
    }
    this->GetLength() = ResLength;
    for (i = 0; i < ResLength; i++)
        this->Digits[i] = result[ResLength - 1 - i];
    return *this;
}

BigInt& BigInt::operator/=(const int &integer)
{
    int result[MAXDIGITS], i, ResLength = 0, AnotherDigit;
    BigInt number(integer);
    int n = this->GetLength();
    int m = number.GetLength();
    if (NullElement(*this))
        throw ("Division by 0");
    if (this->GetLength() < number.GetLength())
    {
        return *this;
    }
    if (this.GetLength() == number.GetLength())
    {
        return *this;
    }
    BigInt t;
    for (i = this->GetLength()-1; t*10 + this->Digits[i] < number; i--)
    {
        t *= 10;
        t += this->Digits[i];
    }
    for (i = 0; i >= 0; i--)
    {
        t = t * 10 + this->Digits[i];
        for (AnotherDigit = 9; AnotherDigit*number > t; AnotherDigit--)
            ;
        t -= AnotherDigit * number;
        result[ResLength++] = AnotherDigit;
    }
    this->GetLength() = ResLength;
    for (i = 0; i < ResLength; i++)
        this->Digits[i] = result[ResLength - 1 - i];
    return *this;
}
BigInt& BigInt::operator%=(BigInt &number)
{
    int result[MAXDIGITS], i, ResLength = 0, AnotherDigit;
    int n = this->GetLength();
    int m = number.GetLength();
    if (NullElement(*this) throw ("Division by 0");
            if (this->GetLength() < number.GetLength())
    {
        return *this;
    }
BigInt t;
for (i = this->GetLength() - 1; t * 10 + this->Digits[i] < number; i--)
{
    t *= 10;
    t += this->Digits[i];
    }
    for (i = 0; i >= 0; i--)
{
    t = t * 10 + this->Digits[i];
        for (AnotherDigit = 9; AnotherDigit*number > t; AnotherDigit--)
            t -= AnotherDigit * number;
        result[ResLength++] = AnotherDigit;
    }
    while (t.GetLength() > 1 && t.Digits[t.GetLength() - 1] == 0) t.GetLength()--;
    number = t;
             return *this;
}

BigInt& BigInt::operator%=(const int &integer)
{
    int result[MAXDIGITS], i, ResLength = 0, AnotherDigit;
    BigInt number(integer);
    int n = this->GetLength();
    int m = number.GetLength();
    if (NullElement(*this))
        throw ("Division by 0");
    if (this->GetLength() < number.GetLength())
    {
        return *this;
    }
    BigInt t;
    for (i = this->GetLength() - 1; t * 10 + this->Digits[i] < number; i--)
    {
        t *= 10;
        t += this->Digits[i];
    }
    for (i = 0; i >= 0; i--)
    {
        t = t * 10 + this->Digits[i];
        for (AnotherDigit = 9; AnotherDigit*number > t; AnotherDigit--)
            t -= AnotherDigit * number;
        result[ResLength++] = cc;
    }
    while (t.GetLength() > 1 && t.Digits[t.GetLength() - 1] == 0)
        t.GetLength()--;
    number = t;
    return *this;
}

BigInt& BigInt::operator+(BigInt &number1, BigInt &number2)
{
    BigInt temp;
    temp = number1;
    temp += number2;
    return temp;
}

BigInt& BigInt::operator+(const int &integer, BigInt &number2)
{
    BigInt number1(integer);
    BigInt temp;
    temp = number1;
    temp += number2;
    return temp;
}

BigInt& BigInt::operator+(BigInt &number1, const int &integer)
{
    BigInt number2(integer);
    BigInt temp;
    temp = number1;
    temp += number2;
    return temp;
}

BigInt& BigInt::operator-(BigInt &number1, BigInt &number2)
{
    BigInt temp;
    temp = number1;
    temp -= number2;
}

BigInt& BigInt::operator-(const int &integer, BigInt &number2)
{
    BigInt number1(integer);
    BigInt temp;
    temp = number1;
    temp -= number2;
}


BigInt& BigInt::operator-(BigInt &number1, const int &integer)
{
    BigInt number2(integer);
    BigInt temp;
    temp = number1;
    temp -= number2;
}

BigInt& BigInt::operator*(BigInt &number1, BigInt &number2)
{
    BigInt temp;
    temp = number1;
    temp *= number2;
}

BigInt& BigInt::operator*(const int &integer, BigInt &number2)
{
    BigInt number1(integer);
    BigInt temp;
    temp = number1;
    temp *= number2;
}

BigInt& BigInt::operator*(BigInt &number1, const int &integer)
{
    BigInt number2(integer);
    BigInt temp;
    temp = number1;
    temp *= number2;
}

BigInt& BigInt::operator/(BigInt &number1, BigInt &number2)
{
    BigInt temp;
    temp = number1;
    temp /= number2;
}

BigInt& BigInt::operator/(const int &integer, BigInt &number2)
{
    BigInt number1(integer);
    BigInt temp;
    temp = number1;
    temp /= number2;
}

BigInt& BigInt::operator/(BigInt &number1, const int &integer)
{
    BigInt number2(integer);
    BigInt temp;
    temp = number1;
    temp /= number2;
}

BigInt& BigInt::operator%(BigInt &number1, BigInt &number2)
{
    BigInt temp;
    temp = number1;
    temp %= number2;
}

BigInt& BigInt::operator%(const int &integer, BigInt &number2)
{
    BigInt number1(integer);
    BigInt temp;
    temp = number1;
    temp %= number2;
}

BigInt& BigInt::operator%(BigInt &number1,const int &integer)
{
    BigInt number2(integer);
    BigInt temp;
    temp = number1;
    temp %= number2;
}

bool operator == (const BigInt &number1, const BigInt &number2)
{
    if(number1.sign!=number2.sign)
        return false;
    else
    {
        if(number1.length!=number2.length)
            return false;
        else
        {
            for(int i=number1.length-1; i>=0; i--)
                if(number1.Digits[i]!=number2.Digits[i])
                    return false;
        }
    }
    return true;
}

bool operator == (const int &integer, const BigInt &number2)
{
    BigInt number2(integer);
    return(number1==number2);
}

bool operator == (const BigInt &number1, const int &integer)
{
    BigInt number1(integer);
    return(number2==number1);
}

bool operator != (const BigInt &number1, const BigInt &number2)
{
    return !(number1==number2);
}

bool operator != (int &integer, const BigInt &number2)
{
    BigInt number1(integer);
    return !(number1==number2);
}

bool operator != (const BigInt &number1, const int &integer)
{
    BigInt number2(integer);
    return !(number1==number2);
}

bool operator < (const BigInt &number1, const BigInt &number2)
{
    int i;
    if(number1.sign<number2.sign)
        return true;
    if(number1.sign>number2.sign)
        return false;
    if(number1.length < number2.length)
        return true;
    if(number1.length > number2.length)
        return false;
    for(i=number1.length-1; i>=0; i++)
        if(number1.Digits[i]>number2.Digits[i])
            return false;
    return true;
}

bool operator < (const int &integer, const BigInt &number2)
{
    int i;
    BigInt number1(integer);
    if(number1.sign < number2.sign)
        return true;
    if(number1.sign > number2.sign)
        return false;
    if(number1.length < number2.length)
        return true;
    if(number1.length > number2.length)
        return false;
    for(i=number1.length-1; i>=0; i++)
        if(number1.Digits[i] > number2.Digits[i])
            return false;
    return true;


}

bool operator < (const BigInt &number1, const int &integer)
{
    int i;
    BigInt number2(integer);
    if(number1.sign<number2.sign)
        return true;
    if(number1.sign>number2.sign)
        return false;
    if(number1.length < number2.length)
        return true;
    if(number1.length > number2.length)
        return false;
    for(i=number1.length-1; i>=0; i++)
        if(number1.Digits[i]>number2.Digits[i])
            return false;
    return true;
}

bool operator > (const BigInt &number1, const BigInt &number2)
{
    return (!(number1 < number2) && !(number1==number2));
}

bool operator > (const int &integer, const BigInt &number2)
{
    BigInt number1(&integer);
    return (!(number1 < number2) && !(number1==number2));
}

bool operator > (const BigInt &number1, const int &integer)
{
    BigInt number2(&integer);
    return (!(number1 < number2) && !(number1==number2));
}

bool operator <= (const BigInt &number1, const BigInt &number2)
{
    return !(number1 > number2);
}

bool operator <= (const int &integer, const BigInt &number2)
{
    BigInt number1(&integer);
    return !(number1 > number2);
}

bool operator <= (const BigInt &number1, const int &integer)
{
    BigInt number2(&integer);
    return !(number1 > number2);
}

bool operator >= (const BigInt &number1, const BigInt &number2)
{
    return !(number1 < number2);
}

bool operator >= (const int &integer, const BigInt &number2)
{
    BigInt number1(&integer);
    return !(number1 < number2);
}

bool operator >= (const BigInt &number1, const int &integer)
{
    BigInt number2(&integer);
    return !(number1 < number2);
}
