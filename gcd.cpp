// great common divisor
#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a; 
  return gcd(b, a % b);
}

int main() {
  // sample
  std::cout << gcd(221, 323);
}