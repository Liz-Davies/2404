//Project by: Sarah Davies - 100828244 Mike Sayegh - 101029473

#ifndef _MYTUNESCOL_H
#define _MYTUNESCOL_H
using namespace std;
#include "UI.h"
#include "string.h"
#include "playlist.h"
#include "song.h"
#include "track.h"
#include "recording.h"
#include "user.h"
#include <typeinfo>
#include <vector>

template <typename T>
class MyTunesCollection {
    private:
        vector<T*> collection;
        typename vector<T*>::iterator findPosition(T & t){
            for (typename vector<T*>::iterator it = collection.begin() ; it < collection.end(); ++it)
                if(*it == &t) return it;
            return collection.end();
        }
    public:
        MyTunesCollection(){}
        ~MyTunesCollection(void){
            for(int i=0; i<collection.size(); i++)
        		delete collection[i];
        }
        //needs to reconcile? IDK
        T * findByID(int id){
            for (typename vector<T*>::iterator it = collection.begin() ; it < collection.end(); ++it)
        		if((*it)->getID() == id) return *it;
        	return NULL;
        }
        //
        void add(T & t){
            if(findByID(t.getID())!=NULL);
            collection.push_back(&t);
        }
        void remove(T & t){
            typename vector<T*>::iterator index = findPosition(t);
        	if(index != collection.end()) {
        		T * at = *index;
        		collection.erase(index);
        		delete at; //free the memory
            }
        }
        vector<T*> & getCollection(){
            return collection;
        }
        void showOn(UI & view) const{
            string s;
            s.append(typeid(T).name());
            s = s.substr(1);
            s.append(" List:");
            view.printOutput(s);
            for(int i=0; i<collection.size(); i++)
                 view.printOutput((*collection[i]).toString());
        }
        void showOn(UI & view, int memberID) {
          T * t = findByID(memberID);
          if( t != NULL)
               view.printOutput(t->toString());
        }
        void showOn(UI & view, string memberID)  {
          T* t = findUserByID(memberID);
          if( t != NULL)
               view.printOutput(t->toString());
        }
        User * findUserByID(string aUserName){
            if(typeid(User)!=typeid(T)) return NULL;
            for (typename vector<T*>::iterator it = collection.begin() ; it <collection.end(); ++it)
                if((*it)->getUserID().compare(aUserName)==0) return *it;
            return NULL;

        }
};

#endif
