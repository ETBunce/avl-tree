#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "dictionary.h"
#include <string>

using namespace std;

void MYCHECK(bool b) {
  if (b) cout << "Success" << endl;
  else cout << "Fail" << endl;
}

// PART 3: The main function
int main(){

	Dictionary<string, string> d;
  d.put("AL","Alabama");
  d.put("AK","Alaska");
  d.put("AZ","Arizona");
  d.put("AR","Arkansas");
  d.put("CA","California");
  d.put("CO","Colorado");
  d.put("CT","Connecticut");
  d.put("DE","Delaware");
  d.put("FL","Florida");
  d.put("GA","Georga");
  d.put("HI","Hawaii");
  d.put("ID","Idaho");
  d.put("IL","Illinois");
  d.put("IN","Indiana");
  d.put("IA","Iowa");
  d.put("KS","Kansas");
  d.put("KY","Kentucky");
  d.put("LA","Louisiana");
  d.put("ME","Maine");
  d.put("MD","Maryland");
  d.put("MA","Massachusetts");
  d.put("MI","Michigan");
  d.put("MN","Minnesota");
  d.put("MS","Mississippi");
  d.put("MO","Missouri");
  d.put("MT","Montana");
  d.put("NE","Nebraska");
  d.put("NV","Nevada");
  d.put("NH","New Hampshire");
  d.put("NJ","New Jersey");
  d.put("NM","New Mexico");
  d.put("NY","New York");
  d.put("NC","North Carolina");
  d.put("ND","North Dakota");
  d.put("OH","Ohio");
  d.put("OK","Oklahoma");
  d.put("OR","Oregon");
  d.put("PA","Pennsylvania");
  d.put("RI","Rhode Island");
  d.put("SC","South Carolina");
  d.put("SD","South Dakota");
  d.put("TN","Tennessee");
  d.put("TX","Texas");
  d.put("UT","Utah");
  d.put("VT","Vermont");
  d.put("VA","Virgina");
  d.put("WA","Washinton");
  d.put("WV","West Virginia");
  d.put("WI","Wisconsin");
  d.put("WY","Wyoming");


  cout << d << endl;
  
  return 0;
}