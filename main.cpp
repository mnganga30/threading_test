#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <thread>
#include <mutex>



/*
* author> Martin
*
*
*/
static const int num_threads = 10;
static std::mutex barrier;


void call_from_thread(int tid){
  std::lock_guard<std::mutex> block_thread_until_finish_this_job(barrier);
  std::cout << "called by Thread:" << tid << std::endl;
}

int main()
{
  std::thread t[num_threads];

  // launches the num_threads amount of threads
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
