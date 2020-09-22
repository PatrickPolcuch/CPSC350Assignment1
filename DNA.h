#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Files{

public:
  Files();//default constructor
  ~Files();//destructor
  string fileProcessing(string text);
  bool validLine(string line);
  void calcVariance(string text);
  void bigrams(string text);
  string thousandLines();
  int calcD();
  string makeLine(int D);

  int sum;
  float mean;
  float variance;
  float std;
  int numLines;
  int atot;
  int ttot;
  int gtot;
  int ctot;
  float aprob;
  float tprob;
  float cprob;
  float gprob;

  int biTot;
  int AAbi;
  int ATbi;
  int ACbi;
  int AGbi;
  int TAbi;
  int TTbi;
  int TCbi;
  int TGbi;
  int CAbi;
  int CTbi;
  int CCbi;
  int CGbi;
  int GAbi;
  int GTbi;
  int GCbi;
  int GGbi;
};
