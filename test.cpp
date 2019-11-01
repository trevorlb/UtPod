/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

   string s1 = "ryan is dumb";
   string s2 = "ryan is dumb";

   if (s1 == s2){
      cout << s1 << " equals " << s2 << '\n';
   }
   else if (s1 > s2){
      cout << s1 << " is greater than " << s2 << '\n';
   }
   else
      cout << s1 << " is less than " << s2 << '\n';
}
 
