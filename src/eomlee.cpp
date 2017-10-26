class EomLee : public Estimator{
  public:
    int getNextFrame(int collisions, int empties, int sucess){
      double b = 0;
      double y = 2;
      double ny = 2;
      double eps = 0.001;
      double l = collisions+empties+sucess;
      double e = 2.71828;
      while(1){
        b = l/(y*collisions*sucess);
        ny = (1-(1/pow(e, (1/b))))/(b*(1-(1+1/b)*(1/pow(e, (1/b)))));
        printf("%.2lf\n", ny);

        if(abs(ny-y) <= eps) {
          break;
        }
        y = ny;
      }
      printf("%.2lf\n", ny);
      return ceil(ny * collisions);

    }
};
