#include <stdio.h>
#define ARRAY_SIZE 2048
#define NUMBER_OF_TRIALS 1000000

int main(int argc, char *argv[]) 
{
  // Declare arrays small enough to stay in L1 cache. 
  // Assume the compiler aligns them correctly. 
  double a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];
  const double m = 1.5;
  
  int i, t; 
  // Initialize a, b and c arrays 
  for (i=0; i < ARRAY_SIZE; i++) 
  {
    a[i] = 0.0; b[i] = i*1.0e-9; c[i] = i*0.5e-9; 
  }
  

  // Perform operations with arrays many, many times 
  for (t=0; t < NUMBER_OF_TRIALS; t++) 
  {
    for (i=0; i < ARRAY_SIZE; i++) 
    { 
      a[i] += m*b[i] + c[i];
    } 
  }

  // Print a result so the loops won't be optimized away 
  double d = 0.0;
  for (i=0; i < ARRAY_SIZE; i++) d += a[i]; 
  
  printf("%f\n",d/ARRAY_SIZE);

  return 0;
}

// EOF
