#include <iostream>
#include <ctime>
#include <list>
#include <string>
using namespace std;


class Animal{
  int order;
  string name;
  string type;
public:
  Animal(string str): name(str) {}
  virtual void setOrder(int o){order=o;}
  virtual void setType(string typ){type=typ;}
  virtual string getType(){return type;}
  virtual int getOrder(){return order;}
  virtual string getName(){return name;}
  bool operator> (const Animal& ani) const {
    return order>ani.order;
  }
  bool operator< (const Animal& ani) const {
    return order<ani.order;
  }
  
};

class Cat:public Animal{
public:
  Cat(string str):Animal(str){Animal::setType("Cat");};
};


class Dog:public Animal{
public:
  Dog(string str):Animal(str){Animal::setType("Dog");}
};


class Shelter{
  list<Cat> cats;
  list<Dog> dogs;
  int order;
public:
  Shelter():order(0){}
  void enqueue(Animal ani){
     order++;
    ani.setOrder(order);
    if (ani.getType()=="Cat"){
      cats.push_back(*(Cat*) &ani);
    }
    if (ani.getType()=="Dog"){   
      dogs.push_back(*(Dog*) &ani);
    }
    cout << "Enqueue: " << ani.getName() << " on time: " << ani.getOrder() << endl;
  }
  
  Animal dequeueAny(){
     if (cats.empty() && dogs.empty()){cerr<<"Empty Shelter!!" << endl;}
     else{
       if (!cats.empty() && dogs.empty()){
         cout << "No dogs in shelter" << endl;
         return dequeueCat();
       }
       if (cats.empty() && !dogs.empty()){
         cout << "No cats in shelter" << endl;
         return dequeueDog();
       }
       if (!cats.empty() && !dogs.empty()){
         //if (cats.front().getOrder()>dogs.front().getOrder()){
	if (cats.front()>dogs.front()){
            return dequeueDog();
         }else{
            return dequeueCat();
         }
       }
     }
  };
  
  Dog dequeueDog(){
    if (!dogs.empty()){
      Dog ani = dogs.front();
      dogs.pop_front();
      return ani;
    }else{
     cerr<< "Empty dogs" << endl;
    }
  };
  
 Cat dequeueCat(){
    if (!cats.empty()){
      Cat ani = cats.front();
      cats.pop_front();
      return ani;
    }else{
     cerr<< "Empty cats" << endl;
    }
  }
};


int main(){
  Shelter sh;
  Cat c1("Cat1");
  Cat c2("Cat2");
  Cat c3("Cat3");
  Dog d1("Dog1");
  Dog d2("Dog2");
  Dog d3("Dog3");
  
  sh.enqueue(c1);  
  sh.enqueue(d1);
  sh.enqueue(d2);
  sh.enqueue(c2);
  sh.enqueue(c3);
  sh.enqueue(d3);
  
  
  Animal ani = sh.dequeueAny();
  cout << "DeuqeAny: " << ani.getName() << endl;
  Cat cc = sh.dequeueCat();
  cout << "DeuqeCat: " << cc.getName() << endl;
  Dog dd = sh.dequeueDog();
  cout << "DeuqeDog: " << dd.getName() << endl;
  
}
