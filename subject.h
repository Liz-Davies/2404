#ifndef _subjecth
#define _subjecth
#include "arraylist.h"
#include "observer.h"
class Subject {
//    =======
 ArrayList<Observer> observers;
public:
  void attach(Observer & obs) {
   observers.add(obs);
  //cout << "\nAttach: " << " observers size: " << observers.size() << "\n";

  }
  void dettach(Observer & obs) {
   observers.remove(obs);
   //cout << "\nDettach: " << " observers size: " << observers.size() << "\n";
  }

protected:
  void notify() {
    ArrayList<Observer> observers_copy = observers;
    for(ArrayList<Observer>::iterator itr = observers_copy.begin(); itr != observers_copy.end(); itr++) {
      (*itr).update((Subject*) this);
   }
  }
};
#endif
