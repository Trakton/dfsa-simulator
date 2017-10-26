using namespace std;

class Simulator{
  private:
    int tagMin;
    int tagMax;
    int tagStep;
    int repetitions;
    int slots;
    Estimator* estimator;
    int inUse[1000000];
    int removed[1000000];
    int it;
    vector<vector<int> > results;
    vector<int> labels;
  public:
    Simulator(int tagMin, int tagMax, int tagStep, int repetitions, int slots, Estimator* estimator){
      this->tagMin = tagMin;
      this->tagMax = tagMax;
      this->tagStep = tagStep;
      this->repetitions = repetitions;
      this->slots = slots;
      this->estimator = estimator;
      this->labels.assign(tagMax, -1);
      this->results.assign(tagMax, vector<int>());
    }
    void run(){
      int k = 0;
      for(int tags = tagMin; tags <= tagMax; tags += tagStep){
        labels[k] = tags;
        double collisionsMean = 0;
        double emptiesMean = 0;
        double slotsMean = 0;
        double timeMean = 0;
        for(int i = 0; i < repetitions; i++){
          int toIdentify = tags;
          int slots = this->slots;
          timeval start, end;
          gettimeofday(&start, 0);
          while(toIdentify){
            it++;
            int collisions = 0;
            int empties = slots;
            int remaining = toIdentify;
            for(int j = 0; j < remaining; j++){
              int x = rand()%slots;
              if(inUse[x] == it){
                if(removed[x] != it){
                  collisions++;
                  removed[x] = it;
                  toIdentify++;
                }
              } else {
                inUse[x] = it;
                empties--;
                toIdentify--;
              }
            }
            collisionsMean += collisions;
            emptiesMean += empties;
            slotsMean += slots;
            slots = estimator->getNextFrame(collisions, empties);
          }
          gettimeofday(&end, 0);
          int elapsed = (((end.tv_sec - start.tv_sec)*1000000L+end.tv_usec) - start.tv_usec);
          timeMean += elapsed;
        }
        results[k].push_back(ceil(slotsMean/(double)repetitions));
        results[k].push_back(ceil(emptiesMean/(double)repetitions));
        results[k].push_back(ceil(collisionsMean/(double)repetitions));
        results[k++].push_back(ceil(timeMean/(double)repetitions));

        printf("%d tags: %d %d %d %d\n", labels[k-1], results[k-1][0], results[k-1][1], results[k-1][2], results[k-1][3]);
      }
    }
};
