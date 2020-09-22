#include "DNA.h"

int main(int argc,char** argv){
  Files *text=new Files();
  string out=text->fileProcessing(argv[1]);

  ofstream myFile;
  myFile.open("PatrickPolcuch.txt");
  myFile<<"Patrick Polcuch\n2348668\nCPSC 350-02\nAssignment 1\n\n";
  myFile<<out;
  delete text;

  while(true){
    cout<<"Would you like to proccess another file? (Yes/No)\n";
    string user ="";
    cin>>user;
    if(user.compare("Yes")==0){
      cout<<"What is the name of the file you want processed?"<<endl;
      string userTxt = "";
      cin>>userTxt;

      Files *text=new Files();
      out=text->fileProcessing(userTxt);
      ofstream myFile;
      myFile.open("PatrickPolcuch.txt");
      myFile<<out;
      delete text;
    }
    else if(user.compare("No")==0){
      myFile.close();
      return 0;
    }
    else{
      cout<<"Did not recognize answer. Good bye";
      myFile.close();
      return 0;
    }
  }
cout<<"shouldnt make it here";
delete text;
myFile.close();
return 0;
}
