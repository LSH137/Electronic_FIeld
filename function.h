#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <gmp.h>
#include <mpfr.h>
#include "constant.h"

class var
{
    public:

    var()
    {
        mpfr_init2(mem, precision);
        mpfr_set_zero(mem, MPFR_RNDN);
    }
    ~var() = default;

    mpfr_t mem;

    void print(std::string commant)
    {
        std::cout<<commant;
        mpfr_out_str(stdout, 10, 20, mem, MPFR_RNDN);
    }

    void read()
    {
        mpfr_inp_str(mem, stdin, 10, MPFR_RNDN);
        fflush(stdin);
    }

    void erase()
    {
        mpfr_clear(mem);
    }
};

var plus(var m1, var m2);

var sub(var m1, var m2);

var mul(var m1, var m2);

var mul_d(var m1, double m2);

var div(var m1, var m2);

var div_d(var m1, double m2);

var sqar(var m);

void eqr(var & m1, var m2);

void eqr_d(var & m1, double m2);

var cos(var m);

var sin(var m);

class physics_vector
{
public:

    physics_vector() = default;
    ~physics_vector() = default;

    var size;
    var x;
    var y;
    var z;

    void GetSize()
    {
        var temp[5];

        temp[0] = mul(x, x);
        temp[1] = mul(y, y);
        temp[2] = mul(z, z);
        temp[3] = plus(temp[0], temp[1]);
        temp[4] = plus(temp[3], temp[2]);

        size = sqar(temp[4]);    
    }

    void Reset()
    {
        mpfr_set_zero(size.mem, MPFR_RNDN);
        mpfr_set_zero(x.mem, MPFR_RNDN);
        mpfr_set_zero(y.mem, MPFR_RNDN);
        mpfr_set_zero(z.mem, MPFR_RNDN);
    }

    void print()
    {
        size.print("|E| = ");
        x.print("[N/C]\nE = ");
        y.print(" i + ");
        z.print(" j + ");
        printf(" k [N/C]\n");
    }
};

physics_vector Add(physics_vector v1, physics_vector v2);

var squareDistance(physics_vector p1, physics_vector p2);

physics_vector GetCoulombForce(physics_vector q1, physics_vector q2);
