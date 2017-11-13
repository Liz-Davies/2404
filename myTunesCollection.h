//Project by: Sarah Davies - 100828244 Mike Sayegh - 101029473

#ifndef _MYTUNESCOL_H
#define _MYTUNESCOL_H
using namespace std;
#include "UI.h"
#include <vector>

template<typename T>
class MyTunesCollection{
    public:

        MyTunesCollection();
        ~MyTunesCollection(void);
        //needs to reconcile? IDK
        T findByID(int id);
        T findByUserID(string aUserName);
        //
        void add(T & t);
        void remove(T & t);
        void showOn(UI & aView) const;


    private:
        vector<T*> collection;
        vector<T*>::iterator findPosition(T & t);
};
ostream & operator<<(ostream & out, const MyTunesCollection & myTunesCol);
#endif
