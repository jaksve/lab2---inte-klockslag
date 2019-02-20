#include <iostream>
#include "catch.hpp"
#include "list.h"


using namespace std;

TEST_CASE ("default constructor")
{
  Sorted_List listig;
  CHECK(listig.to_string()=="");
  
}

TEST_CASE("insert")
{
  Sorted_List fett_dum;
  fett_dum.insert(7);
  CHECK(fett_dum.to_string()=="7");
  fett_dum.insert(5);
  
  fett_dum.insert(5);
  fett_dum.insert(8);
  fett_dum.insert(4);
  fett_dum.insert(4);
  fett_dum.insert(1);
  fett_dum.insert(1);
  CHECK(fett_dum.to_string()=="1 1 4 4 5 5 7 8");
}

TEST_CASE("INTIALIZER LIST")
{
  
  
  
  CHECK(Sorted_List{1,3,4,1}.to_string()=="1 1 3 4");
  CHECK(Sorted_List{99,92,1,98}.to_string()=="1 92 98 99");
}

TEST_CASE("DJUUUP KOPIERING"){
  
  Sorted_List t;
  Sorted_List q{7,3,5};
  
  Sorted_List p{13,37,420,69};
 
 
  t = q;
  
 CHECK(t.to_string()=="3 5 7");
 q = p;
 
 CHECK(q.to_string()=="13 37 69 420");
 
 Sorted_List l {Sorted_List{}};
  
 q=Sorted_List{1,3,66,2,1,1};
 
 CHECK(q.to_string()=="1 1 1 2 3 66");
 Sorted_List g=t;
 
 CHECK(g.to_string()=="3 5 7");
 Sorted_List a=Sorted_List{1,3,66,4,5,2,1,1};
 CHECK(a.to_string()=="1 1 1 2 3 4 5 66");

 
 
}


TEST_CASE("SKAPA ITERATOR")
{
  Sorted_List lista{2,3,4};
  auto it = lista.begin();

  CHECK(lista.to_string()== "2 3 4");
  
  ++it;
  cout<<*it<<endl;
  
}


TEST_CASE("iterators")
{
Sorted_List lista{2, 5, 7};
 for(auto it = lista.begin(); it != lista.end(); ++it){
   cout << *it << endl;
 }
}
#if 0
#endif
