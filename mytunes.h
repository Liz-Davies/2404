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

#ifndef MYTUNES_H
#define MYTUNES_H
#include <sstream>
using namespace std;
#include "UI.h"
#include "mytunesmodel.h"
#include "command.h"
#include "song.h"
#include "recording.h"
#include "track.h"
#include "playlist.h"
#include "user.h"

/*
This is the main application class.
It has knowlege of the UI and data model (not done in this assignment).
*/

class MyTunes
{
  public:
    MyTunes();
    void run();
    void executeCommand(Command cmd);
  private:
    UI view;
    void executeCMDADD(Command cmd);
    void executeAddSong(Command cmd);
    void executeAddRecording(Command cmd);
    void executeAddTrack(Command cmd);
    void executeAddUser(Command cmd);
    void executeAddPlaylist(Command cmd);
    void executeAddPlaylistTrack(Command cmd);

    void executeCMDDELETE(Command cmd);
    void executeDeleteRecording(Command cmd);
    void executeDeleteUser(Command cmd);
    void executeDeleteUserPlaylist(Command cmd);
    void executeDeleteUserPlaylistTrack(Command cmd);
    void executeDeleteTrack(Command cmd);
    void executeDeleteSong(Command cmd);

    void executeCMDFOLLOW(Command cmd);
	//Data Model
    MyTunesModel model;
	//available ID's for app assigned ID's
	//These should only be used after database data has loaded
	int nextAvailableSongID;
	int nextAvailableRecordingID;
	int nextAvailableTrackID;
};
#endif
