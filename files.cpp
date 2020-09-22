#include "DNA.h"


Files::Files(){
 sum = 0;
 mean = 0;
 variance = 0;
 std = 0;
 numLines = 0;
 atot = 0;
 ttot = 0;
 gtot = 0;
 ctot = 0;
 aprob = 0;
 tprob = 0;
 cprob = 0;
 gprob = 0;

 biTot = 0;
 AAbi = 0;
 ATbi = 0;
 ACbi = 0;
 AGbi = 0;
 TAbi = 0;
 TTbi = 0;
 TCbi = 0;
 TGbi = 0;
 CAbi = 0;
 CTbi = 0;
 CCbi = 0;
 CGbi = 0;
 GAbi = 0;
 GTbi = 0;
 GCbi = 0;
 GGbi = 0;

srand (time(NULL));//generates a random seed for rand()
}

Files::~Files(){
  cout<< "deconstructor for Files"<<endl;
}

string Files::fileProcessing(string text){
  string r = "";//return string
  string curLine = "";

  ifstream myFile;
  myFile.open(text);

  while(getline(myFile,curLine)){
    if(!validLine(curLine)){
      continue;
    }
    for(int i = 0;i<curLine.size()-1;++i){
      sum++;
      switch (tolower(curLine[i])) {
        case 'a':
          atot++;
          break;
        case 't':
          ttot++;
          break;
        case 'g':
          gtot++;
          break;
        case 'c':
          ctot++;
          break;
        default:
          cout<<"ERROR: incorrect value in switch statement-"<<curLine[i]<<endl;
      }

    }
    numLines++;
  }
  myFile.close();

  mean = ((float)sum)/numLines;
  calcVariance(text);
  std = sqrt(variance);
  bigrams(text);
  aprob = ((float)atot)/sum;
  tprob = ((float)ttot)/sum;
  cprob = ((float)ctot)/sum;
  gprob = ((float)gtot)/sum;

  r+="The Sum of the length of the DNA strings is: "+to_string(sum)+"\n";//learned of the to_string(float) method from stack overflow
  r+="The Mean of the length of the DNA strings is "+to_string(mean)+"\n";
  r+="The variance of the length of the DNA strings is: "+to_string(variance)+"\n";
  r+="The Standard Deviation of the length of the DNA stings is: "+to_string(std)+"\n";

  r+="Here is the relative probability of each nucleotide:\n";
  r+="A:    "+to_string(aprob)+"\nT:    "+to_string(tprob)+"\nC:    "+to_string(cprob)+"\nG:    "+to_string(gprob)+"\n\n";

  r+="Here is the relative probability of each nucleotide bigram:\n";
  r+=  "AA:    "+to_string(((float)AAbi)/biTot)+"\nAT:    "+to_string(((float)ATbi)/biTot)+"\nAC:    "+to_string(((float)ACbi)/biTot)+"\nAG:    "+to_string(((float)AGbi)/biTot);
  r+="\nTA:    "+to_string(((float)TAbi)/biTot)+"\nTT:    "+to_string(((float)TTbi)/biTot)+"\nTC:    "+to_string(((float)TCbi)/biTot)+"\nTG:    "+to_string(((float)TGbi)/biTot);
  r+="\nCA:    "+to_string(((float)CAbi)/biTot)+"\nCT:    "+to_string(((float)CTbi)/biTot)+"\nCC:    "+to_string(((float)CCbi)/biTot)+"\nCG:    "+to_string(((float)CGbi)/biTot);
  r+="\nGA:    "+to_string(((float)GAbi)/biTot)+"\nGT:    "+to_string(((float)GTbi)/biTot)+"\nGC:    "+to_string(((float)GCbi)/biTot)+"\nGG:    "+to_string(((float)GGbi)/biTot);

  string kLines = thousandLines();
  r+="\n\n1000 lines of DNA strings similar to the input\n";
  r+=kLines;
  return r;
}

bool Files::validLine(string line){
  string valid="atcgATCG ";
  for(int i = 0;i<line.size()-1;++i){
    if(valid.find(line[i]) == string::npos){
      return false;
    }
  }
  return true;
}

void Files::calcVariance(string text){//only works if mean has been calculated
  ifstream myFile;
  myFile.open(text);
  string line="";
    while(getline(myFile,line)){
      if(!validLine(line)){
        continue;
      }
      variance+=(mean-(line.size()-1))*(mean-(line.size()-1));
    }
  variance = variance/numLines;
}

void Files::bigrams(string text){
  ifstream myFile;
  myFile.open(text);
  string line="";
  while(getline(myFile,line)){
    if(!validLine(line)){
      continue;
    }
    string bigram = "";
    for(int i = 0;i<line.size()-1;i+=2){
      bigram = "";
      if(i == line.size()-2){
        bigram = tolower(line[i]) + tolower(line[0]);
      }
      else{
        bigram += tolower(line[i]);
        bigram += tolower(line[i+1]);
      }

      if(bigram.compare("aa") == 0){//I was going to use a switch statement, but those dont work on strings
        AAbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("at") == 0){
        ATbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("ac") == 0){
        ACbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("ag") == 0){
        AGbi++;
        biTot++;
        continue;
      }

      if(bigram.compare("ta") == 0){
        TAbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("tt") == 0){
        TTbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("tc") == 0){
        TCbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("tg") == 0){
        TGbi++;
        biTot++;
        continue;
      }

      if(bigram.compare("ca") == 0){
        CAbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("ct") == 0){
        CTbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("cc") == 0){
        CCbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("cg") == 0){
        CGbi++;
        biTot++;
        continue;
      }

      if(bigram.compare("ga") == 0){
        GAbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("gt") == 0){
        GTbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("gc") == 0){
        GCbi++;
        biTot++;
        continue;
      }
      if(bigram.compare("gg") == 0){
        GGbi++;
        biTot++;
        continue;
      }
    }
  }
}

string Files::thousandLines(){
  string lines = "";
  for(int i = 0;i<1000;++i){
    int D = calcD();
    lines += makeLine(D);
  }
  return lines;
}

int Files::calcD(){
  float C = 0;
  float a = 0;
  float b = 0;

  a = (float)rand()/(float)(RAND_MAX);
  b = (float)rand()/(float)(RAND_MAX);

  C = sqrt((-2)*log(a))*cos(M_PI*2*b);
  int D = round(std*C+mean);

  return D;
}

string Files::makeLine(int D){
  string line = "";

  for(int i = 0; i<=D; ++i){
    float probability = (float)rand()/(float)(RAND_MAX);
    if(probability<aprob){
      line+='A';
      continue;
    }
    if(probability<(aprob+tprob)){
      line+='T';
      continue;
    }
    if(probability<(aprob+tprob+cprob)){
      line+='C';
      continue;
    }
    if(probability<=1){
      line+='G';
      continue;
    }
    cout<<"ERROR:string File::makeLine(int D) has probibility values that add to >1"<<endl;
  }
  return line+"\n";
}
