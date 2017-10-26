class LowerBound : public Estimator{
  public:
      int getNextFrame(int collisions, int empties) {
        return collisions * 2;
      }
};
