#include "function.h"
#include "constant.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <gmp.h>
#include <mpfr.h>

var plus(var m1, var m2)
{
    var result;
    mpfr_add(result.mem, m1.mem, m2.mem, MPFR_RNDN);
    return result;
}

var sub(var m1, var m2)
{
    var result;
    mpfr_sub(result.mem, m1.mem, m2.mem, MPFR_RNDN);
    return result;

}

var mul(var m1, var m2)
{
    var result;
    mpfr_mul(result.mem, m1.mem, m2.mem, MPFR_RNDN);
    return result;
}

var mul_d(var m1, double m2)
{
    var result;
    mpfr_mul_d(result.mem, m1.mem, m2, MPFR_RNDN);
    return result;
}

var div(var m1, var m2)
{
    var result;
    mpfr_div(result.mem, m1.mem, m2.mem, MPFR_RNDN);
    return result;
}

var div_d(var m1, double m2)
{
    var result;
    mpfr_div_d(result.mem, m1.mem, m2, MPFR_RNDN);
    return result;
}

var sqar(var m)
{
    var result;
    mpfr_sqrt(result.mem, m.mem, MPFR_RNDN);
    return result;
}

void eqr(var & m1, var m2)
{
    mpfr_set(m1.mem, m2.mem, MPFR_RNDN);
}

void eqr_d(var & m1, double m2)
{
    mpfr_set_d(m1.mem, m2, MPFR_RNDN);
}

var cos(var m)
{
    var result;
    mpfr_cos(result.mem, m.mem, MPFR_RNDN);
    return result;
}

var sin(var m)
{
    var result;
    mpfr_sin(result.mem, m.mem, MPFR_RNDN);
    return result;
}

physics_vector Add(physics_vector v1, physics_vector v2)
{
    physics_vector result;
    result.x = plus(v1.x, v2.x);
    result.y = plus(v1.y, v2.y);
    result.z = plus(v1.z, v2.z);
    result.GetSize();

    return result;
}

physics_vector Minus(physics_vector v1, physics_vector v2)
{
    physics_vector result;
    result.x = sub(v1.x, v2.x);
    result.y = sub(v1.y, v2.y);
    result.z = sub(v1.z, v2.z);
    result.GetSize();

    return result;
}

var squareDistance(physics_vector p1, physics_vector p2)
{
    var temp[4];
    var dis;

    temp[0] = sub(p1.x, p2.x);
    temp[1] = sub(p1.y, p2.y);
    temp[2] = sub(p1.z, p2.z); 

    temp[0] = mul(temp[0], temp[0]);
    temp[1] = mul(temp[1], temp[1]);
    temp[2] = mul(temp[2], temp[2]);

    temp[3] = plus(temp[0], temp[1]);
    dis = plus(temp[2], temp[3]);

    return dis;
}

physics_vector GetCoulombForce(physics_vector q1, physics_vector q2) //q2 is main
{
    physics_vector diff;
    physics_vector result;
    
    var factor;
    var temp[2];
    var dis;
    
    dis = squareDistance(q1, q2);
    temp[0] = mul(q1.size, q2.size);
    temp[1] = mul_d(temp[0], Ke);
    result.size = div(temp[1], dis);    
    
    diff = Minus(q2, q1);
    factor = div(result.size, diff.size);
    
    result.x = mul(diff.x, factor);
    result.y = mul(diff.y, factor);
    result.z = mul(diff.z, factor);
   
    return result;
}
