#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <thread>


/*
* author> Martin
*
*
*/
static const int num_threads = 10;



void call_from_thread(){
  std::printf("Hello World \n" );
}

int main()
{
  std::thread t[num_threads];

  // luanches the num_threads amount of threads
  for(int i =0; i< num_threads; i++)
  {
      t[i] = std::thread(call_from_thread);
    }


// joins all the threads with the main one
for(int i =0; i< num_threads; i++)
{
  t[i].join();
}
  return 0;
}
