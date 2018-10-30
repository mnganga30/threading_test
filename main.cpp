#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <thread>


/*
* author> Martin
*
*
*/
static const int num_threads = 10;



void call_from_thread(int tid){
  std::cout << "called by Thread:" << tid << std::endl;
}

int main()
{
  std::thread t[num_threads];

  // luanches the num_threads amount of threads
  for(int i =0; i< num_threads; i++)
  {
      t[i] = std::thread(call_from_thread, i);
    }

    std::cout << "called from main\n";


// joins all the threads with the main one
for(int i =0; i< num_threads; i++)
{
  t[i].join();
}
  return 0;
}
