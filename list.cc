#include "list.h"
#include <iostream>

Sorted_List::Sorted_List()
{

  p_first.next=&p_last;
  p_last.prev=&p_first;
  
}


Sorted_List::Sorted_List( Sorted_List const& item) :Sorted_List()
{
 
  *this = item;
  
}


Sorted_List::Sorted_List(std::initializer_list<int> il):Sorted_List()
{
  
  for(int i : il){
    insert(i);
    
  }
}


void Sorted_List::insert(int item)
{
  
  node* temp=new node(item);
  node* curr=&p_first;
  while (true){
    if(curr->next->member > temp->member||curr->next->next==nullptr){
     temp->next=curr->next; //ny pekar nästa på sentinel-nod-nästa
     temp->prev=curr; //ny pekar prev på sentinel-nod
     temp->next->prev=temp;
     curr->next=temp; //första nod efter sentinel pekar prev på ny.
  
      break;
    }
    else{
      curr=curr->next;
    
    }
  } 
}


std::string Sorted_List::to_string()const
{
  std::string strang{};
  node* curr=p_first.next;
  while(curr->next!=nullptr){
    strang+=std::to_string(curr->member);
    strang+=" ";
    curr=curr->next;
    
      }
  if(strang!=""){
    strang.pop_back();}
  return strang;
}


Sorted_List::Sorted_List( Sorted_List&& item):Sorted_List()
{
 
   *this=std::move(item);
  
}


Sorted_List& Sorted_List::operator =( Sorted_List const& rhs)
{

  this->~Sorted_List();
   node* curr=rhs.p_first.next;
   while(curr->next!=nullptr){
    insert(curr->member);
    
    curr=curr->next;
      }  
  return *this;

}


Sorted_List& Sorted_List::operator =(Sorted_List && item)
{
  
  std::swap(p_first,item.p_first);
  std::swap(p_last,item.p_last);
  p_first.next->prev=&(p_first);
  p_last.prev->next=&(p_last);

  item.p_first.next->prev=&(item.p_first);
  item.p_last.prev->next=&(item.p_last);
  
  return *this;
}


Sorted_List::~Sorted_List()
{
  
  node* temp;
  temp=p_first.next;
  while(temp->next!=nullptr)
    {
      
      p_first.next=temp->next;
      delete temp;
      temp=p_first.next;
    }

  p_first.next=&p_last;
  p_last.prev=&p_first;
  
}


Sorted_List::steg& Sorted_List::steg::operator =(Sorted_List::steg&& rhs)
{
  
  std::swap(curr,rhs.curr);
  return *this;
  
}


bool Sorted_List::steg::operator !=(Sorted_List::steg rhs)const
{
  
  return curr != rhs.curr;
  
}


int Sorted_List::steg::operator *()const
{
  
  return curr->member;
  
}
