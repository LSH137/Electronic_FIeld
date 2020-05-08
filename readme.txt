1. you need GNU gmp, mpfr, g++
2. build command is
  g++ -c function.cpp
  g++ -Wall -w -o2 -o ElectricField main.cpp function.o -lmpfr -lgmp
  
3. It find the electric field around the circular ring.

4. version infomation
  ubuntu 18.04 LTS
  g++: 7.5.0
  gmp: 6.2.0
  mpfr: 4.0.2
