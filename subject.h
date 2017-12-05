/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*			  Sarah Davies  - 100828244				 */
/*			  Mike Sayegh	- 101029473				 */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef _subjecth
#define _subjecth
#include "arraylist.h"
#include "observer.h"
class Subject {
//    =======
 ArrayList<Observer> observers;
public:
  void attach(Observer & obs) {
      if((void*)(&obs) == (void*)this) return;
      observers.add(obs);
      obs.update((Subject*) this);
      //cout << "\nAttach: " << " observers size: " << observers.size() << "\n";

  }
  void dettach(Observer & obs) {
   obs.changeSubject(NULL);
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
