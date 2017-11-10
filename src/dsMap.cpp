
using namespace std;
class DsMap : public Estimator {
  private:
    double fatSimples(int a, vector<int> divs, double m){
        double ret = m;
        while(a > 1) {
            ret *= a;
            a--;
            for(int i = 0; i < divs.size(); i++){
                if(divs[i] > 1){
                    ret = ret / (double)divs[i];
                    divs[i]--;                    
                }
            }
        }
        return ret;
    }
  public:
    int getNextFrame(int collisions, int empties, int sucess) {
        int L = collisions + empties + sucess;
		int n =  sucess + 2*collisions;
		double next = 0.0;
        double previous = -1.0;
		while(previous < next){
			double x = 1 - (1/(double)L);
			double pe = pow(x, (double)n);
			double ps = (n/(double)L) * pow(x,((double)n-1));
			double pc = 1 - pe - ps;
			previous = next;
			double a = pow(pe, empties)*pow(ps, sucess)*pow(pc, collisions);
			next = fatSimples(L, vector<int>{empties, sucess, collisions}, a);
            n++;    
        }
		return n - 2;
    }
};