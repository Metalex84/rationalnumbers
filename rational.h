#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    int numerator;
    int denominator;
} rational_t;

int getGCD(int a, int b);
void setSign(rational_t *pr);    
rational_t reduce(rational_t r);

rational_t add (rational_t r1, rational_t r2);
rational_t subtract (rational_t r1, rational_t r2);
rational_t multiply (rational_t r1, rational_t r2);
rational_t divide (rational_t r1, rational_t r2);

rational_t absolute (rational_t r);
rational_t exp_rational (rational_t r, int n);
float exp_real(uint16_t x, rational_t r);


#endif