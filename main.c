#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <thread>


using namespace std;

void call_from_thread(){
  std::printf("Hello World \n" );
}

int main()
{
  std::thread t1(call_from_thread);

  t1.join();
  return 0;
}
