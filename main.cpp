#include <cstdio>
#include <gmp.h>
#include <mpfr.h>
#include <cmath>
#include <unistd.h>
#include "function.h"
#include "constant.h"

int n;
int test_times;

int main()
{
    physics_vector point;
    physics_vector testCharge;
    physics_vector sigmaF;
    physics_vector F;

    var R;
    var Q;
    var dq;
    var dtheta;
    var PI;
    var ePI;
    var theta;
    
    mpfr_const_pi(PI.mem, MPFR_RNDN);

    ePI = mul_d(PI, 2.0);
    
    printf("         /  mm      mm        pppp       fffffff     rrrrrr   \n");
    printf("        /  m m     m m       p    p     f           r     r   \n");
    printf("       /  m  m    m  m      p     p    f           r      r   \n");
    printf("      /  m   m   m   m     p    p     fffffff     r     r     \n");
    printf("     /  m    m  m    m    pppp       f           r  r         \n");
    printf("    /  m     m m     m   p          f           r    r        \n");
    printf("   /  m      mm      m  p          f           r      r       \n");
    printf("--/-----------------------------------------------------------\n");
    printf("\n----------------------constant & unit------------------------\n");
    printf("length: M\ncharge: C\n");
    printf("Coulomb constant: %lf\n", Ke);
    PI.print("pi: ");
    printf("\n");
    printf("\n============================================================\n");

    eqr_d(testCharge.size, 1.0);

    printf("enter radious of loop(R): ");
    R.read();
    printf("enter the charge(Q): ");
    Q.read();
    printf("enter the coordinate of test charge x: ");
    testCharge.x.read();
    printf("enter the coordinate of test charge y: ");
    testCharge.y.read();
    printf("enter the coordinate of test charge z: ");
    testCharge.z.read();
        
    dq = div_d(Q, Sensitive);
    dtheta = div_d(ePI, Sensitive);
    eqr(point.size, dq);

    dq.print("\ndq: ");   
    dtheta.print("\ndtheta: ");
    mpfr_set_zero(point.z.mem, MPFR_RNDN);
    
    while (n < Sensitive)
    {
    
        point.x = mul(cos(theta), R);
        point.y = mul(sin(theta), R);
        F = GetCoulombForce(point, testCharge);
        sigmaF = Add(sigmaF, F);

        theta = plus(theta, dtheta);
        n++;
    }

    eqr_d(theta, 0.0);
    
    n = 0;
    F.Reset();

    printf("\n--------------------------result----------------------------\n");
    sigmaF.print();
    printf("\n============================================================\n");

    sigmaF.Reset();
    test_times--;

return 0;
}
