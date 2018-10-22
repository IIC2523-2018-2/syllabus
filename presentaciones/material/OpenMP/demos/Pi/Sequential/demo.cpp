
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <cmath>
#include <iomanip>

using namespace std;

double iteration(int n, int N){
  double frac = (double) n / (double) N;
  double den = 1 + pow(frac, 2);
  double ret = 4/den;
  return ret;
}

int main(){
  struct timeval start, end;
  long mtime, seconds, useconds;

  double pi_tongo = 0; long int N = 50000000;

  gettimeofday(&start, NULL);

  #pragma omp parallel for reduction(+:pi_tongo)
    for (long int i = 0; i < N; i++){
      pi_tongo += iteration(i, N);
    }

  pi_tongo = pi_tongo/N;

  cout << "Estimated vs real value of pi:" << endl;
  cout << setprecision(10) << pi_tongo << endl;

  cout << "3.141592653..." << endl;



  gettimeofday(&end, NULL);

  seconds  = end.tv_sec  - start.tv_sec;
  useconds = end.tv_usec - start.tv_usec;
  mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

  printf("Elapsed time: %ld milliseconds\n", mtime);

  return 0;
}
