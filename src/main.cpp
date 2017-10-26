#include<vector>
#include<stdio.h>
#include<cmath>
#include<sys/time.h>
#include<time.h>
#include<cstdlib>
#include "estimator.cpp"
#include "eomlee.cpp"
#include "lowerBound.cpp"
#include "simulator.cpp"

using namespace std;

int main(){
  srand(time(NULL));
  int tagMin, tagMax, tagStep, slots, repetitions;
  printf("Enter starting number of tags, tag step, maximum number of tags, initial number of slots and number of repetitions\n");
  scanf("%d %d %d %d %d", &tagMin, &tagStep, &tagMax, &slots, &repetitions);
  printf("\n -- Configuration Entered --\n");
  printf("Starting number of tags: %d", tagMin);
  printf("\nTag step: %d", tagStep);
  printf("\nMaximum number of tags: %d", tagMax);
  printf("\nStarting number of slot: %d", slots);
  printf("\nNumber of repetitions: %d\n", repetitions);
  LowerBound lowerBound;
  EomLee eomLee;
  Estimator* estimatorPtr = &eomLee;
  Simulator simulator(tagMin, tagMax, tagStep, repetitions, slots, estimatorPtr);
  simulator.run();
  return 0;
}
