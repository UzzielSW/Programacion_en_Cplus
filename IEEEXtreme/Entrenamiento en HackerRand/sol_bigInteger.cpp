#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>     
using namespace std;

int main()
{
    boost::multiprecision::cpp_int u = 1; 
    for(unsigned i = 1; i <= 100; ++i) 
      u *= i; 
    std::cout << "100! = " << u << '\n';

  return 0;
}