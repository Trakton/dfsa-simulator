#include "estimator.cpp"

class DsMap : public Estimator {
  private:
    int getSubFrameSize(int frames) {
        // if (frames < 8)
        //     return 2;
        if (frames < 16)
            return 4;
        // if (frames < 32)
        //     return 6;
        if (frames < 64)
            return 8;
        // if (frames < 128)
        //     return 12;
        if (frames < 256)
            return 16;
        // if (frames < 512)
        //     return 24;
        if (frames < 1024)
            return 32;
        return 64;
    }
    int map() {
        return 0;
    }
    bool fitsNEst(int fCur, int nEst) {
        return true;
    }
  public:
    int getNextFrame(int collisions, int empties, int sucess) {
        int fIni = collisions + empties + sucess;
        int fCur = fIni;
        int fSub = getSubFrameSize(fSub);
        int n = map();
        int k = fIni/fSub;
        int nEst = n*k;
        if (fitsNEst(fCur, nEst)) {
            
            return 1;
        } else {
            return 1;
        }
    }
};