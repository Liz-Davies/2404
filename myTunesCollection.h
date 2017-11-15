//Project by: Sarah Davies - 100828244 Mike Sayegh - 101029473

#ifndef _MYTUNESCOL_H
#define _MYTUNESCOL_H
using namespace std;
#include "UI.h"
#include "user.h"
#include <vector>

template<typename T>
class MyTunesCollection{

    private:
        vector<T*> collection;
        vector<T*>::iterator findPosition(T & t){
            for (vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
                if(*it == &t) return it;
            return collection.end();
        }
    public:
        MyTunesCollection();
        ~MyTunesCollection(void);
        //needs to reconcile? IDK
        T findByID(int id){
            for (vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
        		if((*it)->getID() == anID) return *it;
        	return NULL;
        }
        T findByUserID(string aUserName){
            if(typeid(T).name() != "User") return NULL;
            for (vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
        		if((*it)->getUserID().compare(aUserName)==0) return *it;
        	return NULL;
        }
        //
        void add(T & t){
            collection.push_back(&t);
        }
        void remove(T & t){
            vector<T*>::iterator index = findPosition(t);
        	if(index != collection.end()) {
        		T * at = *index;
        		collection.erase(index);
        		delete at; //free the memory
        }
        void showOn(UI & aView) const{
            view.printOutput(this.value_type+":");
            for(int i=0; i<collection.size(); i++)
                 view.printOutput((*collection[i]).toString());
        }
        void showOn(UI & view, int memberID)  {
          view.printOutput(this.value_type+":");
          T * t = findByID(memberID);
          if( t != NULL)
               view.printOutput(t->toString());
        }
        void showOn(UI & view, string memberID)  {
          view.printOutput(this.value_type+":");
          T* t = findByID(memberID);
          if( t != NULL)
               view.printOutput(t->toString());
        }



};
ostream & operator<<(ostream & out, const MyTunesCollection & myTunesCol);
#endif
