#include "rational.h"

int getGCD(int a, int b)
{
    int temp = 0;
    
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return (a);
}

void setSign(rational_t *pr)
{
    if (pr->denominator < 0)
    {
        pr->numerator *= -1;
        pr->denominator *= -1;
    }
}
rational_t reduce(rational_t r)
{
    rational_t result;
    int gcd;

    gcd = getGCD(abs(r.numerator), abs(r.denominator));
    if (gcd != 0)
    {
        result.numerator = r.numerator / gcd;
        result.denominator = r.denominator / gcd;
    }
    setSign(&result);
    return (result);
}

rational_t add (rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
    result.denominator = r1.denominator * r2.denominator;
    setSign(&result);
    return (reduce(result));
}

rational_t subtract (rational_t r1, rational_t r2)
{
    rational_t result;
    
    result.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
    result.denominator = r1.denominator * r2.denominator;
    setSign(&result);
    return (reduce(result));
}

rational_t multiply (rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    setSign(&result);
    return (reduce(result));
}

rational_t divide (rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r2.numerator * r1.denominator;
    setSign(&result);
    return (reduce(result));
}

rational_t absolute (rational_t r)
{
    rational_t result;

    result.numerator = abs(r.numerator);
    result.denominator = abs(r.denominator);
    return (reduce(result));
}

rational_t exp_rational (rational_t r, int n)
{
    rational_t result;

    if (n > 0)
    {
        result.numerator = pow(r.numerator, n);
        result.denominator = pow(r.denominator, n);
    }
    else
    {
        result.numerator = pow(r.denominator, abs(n));
        result.denominator = pow(r.numerator, abs(n));  
    }
    setSign(&result);
    return (reduce(result));
}

float exp_real(uint16_t x, rational_t r)
{
    return (pow(x, (float)r.numerator / (float)r.denominator));
}