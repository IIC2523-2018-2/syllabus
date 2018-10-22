#include<iostream>
#include<omp.h>
#include<unistd.h>
using namespace std;

int main() {
  int time_sleep = 1000000;

  #pragma omp parallel num_threads(4)
  {
    usleep(time_sleep);
    cout << "Thread Id =  " << omp_get_thread_num() << endl;
  }
}
