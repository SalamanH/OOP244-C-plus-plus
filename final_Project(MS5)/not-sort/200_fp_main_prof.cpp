#include "PosApp.h"
int main(){
  ict::PosApp app("200_fp_data.txt", "200_fp_bill.txt");
  app.run();
  return 0;
}
