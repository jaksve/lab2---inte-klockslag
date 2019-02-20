#include <utility>
#include <string>




class Sorted_List 
{
  
 public:

  class node
  {
  private:
    
  node(int numb):member{numb},next{nullptr},prev{nullptr}{};  
    int member;
    node* next;
    node* prev;
    friend class Sorted_List;    
  }; 


  class steg
  {
  public:
    friend class Sorted_List; 
    steg& operator ++(){
      curr=curr->next;
      return *this;}

    int operator *()const;
    steg& operator =(steg&& rhs);
    bool operator !=(steg rhs)const;
    
  private:
  steg(node* const item):curr(item){}
    node* curr;   
  };

  
  Sorted_List();
  Sorted_List( std::initializer_list<int> il);
  Sorted_List(Sorted_List const& item);
  Sorted_List( Sorted_List&& item);

  void insert(int item);
  std::string to_string()const;
  
  Sorted_List& operator =(Sorted_List const& rhs);
  Sorted_List& operator =(Sorted_List && rhs);
  
  steg begin() {return steg(p_first.next);}
  steg end() {return steg(&p_last);}

  ~Sorted_List();

 private:
  
  node p_first{1337};
  node p_last{420};
  
};
