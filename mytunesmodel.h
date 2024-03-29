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

#ifndef MYTUNESMODEL_H
#define MYTUNESMODEL_H
#include <sstream>
using namespace std;
#include "UI.h"
#include "command.h"
#include "playlist.h"
#include "myTunesCollection.h"
#include "song.h"
#include "track.h"
#include "recording.h"
#include "user.h"

/*
This is the model class.
*/

class MyTunesModel
{
  public:
    MyTunesModel();
    //MyTunesModel(UI * aView);
    ~MyTunesModel(void);
    //void run();
    void addRecording(Recording * x);
    void addUser(User * x);
    void addSong(Song * x);
    void addTrack(Track * x);

    Recording * getRecordingByID(int ID);
    User * getUserByID(string aUserName);
    Song * getSongByID(int ID);
    Track *getTrackByID(int ID);

    void removeRecording(Recording * x);
    void removeUser(User * x);
    void removeSong(Song * x);
    void removeTrack(Track * x);

    void deleteSong(Song * song);
    void globalTrackDelete(Track *x);

    void executeCMDSHOW(Command cmd,UI & view);

  private:
    //UI view;
    MyTunesCollection<Song> songs;
    MyTunesCollection<Track> tracks;
    MyTunesCollection<Recording> recordings;
    MyTunesCollection<User> users;
};
#endif
