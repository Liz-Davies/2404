#ifndef MYTUNESMODEL_H
#define MYTUNESMODEL_H
#include <sstream>
using namespace std;
#include "UI.h"
#include "mytunes.h"
#include "command.h"
#include "playlist.h"
#include "songs.h"
#include "recordings.h"
#include "tracks.h"
#include "users.h"

/*
This is the model class.
*/

class MyTunesModel
{
  public:
    MyTunesModel(Mytunes * anOwner);
    void run();
    void executeCommand(Command cmd);
    void addThat(Command cmd);
    void deleteThat(Command cmd);
    void showThat(Command cmd);
  private:
    UI view;
};
#endif