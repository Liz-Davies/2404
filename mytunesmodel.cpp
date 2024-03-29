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

#include "mytunesmodel.h"
using namespace std;
MyTunesModel::MyTunesModel(){}
// void Myrun();
MyTunesModel::~MyTunesModel(void){}

void MyTunesModel::addRecording(Recording * x){
	recordings.add(*x);
}
void MyTunesModel::addUser(User * x){
	users.add(*x);
}
void MyTunesModel::addSong(Song * x){
	songs.add(*x);
}
void MyTunesModel::addTrack(Track * x){
	tracks.add(*x);
}

Recording * MyTunesModel::getRecordingByID(int ID){
	return recordings.findByID(ID);
}
User * MyTunesModel::getUserByID(string aUserName){
	return users.findUserByID(aUserName);
}
Song * MyTunesModel::getSongByID(int ID){
	return songs.findByID(ID);
}
Track * MyTunesModel::getTrackByID(int ID){
	return tracks.findByID(ID);
}

void MyTunesModel::removeRecording(Recording * x){
	recordings.remove(*x);
}
void MyTunesModel::removeUser(User * x){
	users.remove(*x);
}
void MyTunesModel::removeSong(Song * x){
	songs.remove(*x);
}
void MyTunesModel::removeTrack(Track * x){
	tracks.remove(*x);
}

void MyTunesModel::globalTrackDelete(Track * track){
	vector<User*> theUsers = users.getCollection();
	for(vector<User*>::iterator itr = theUsers.begin(); itr != theUsers.end(); itr++){
		User* user = *itr;
		user->removeTrack(*track);
	}
	vector<Recording*> theRecordings = recordings.getCollection();
	for(vector<Recording*>::iterator itr = theRecordings.begin(); itr != theRecordings.end(); itr++){
		Recording* recording = *itr;
		recording->removeTrack(*track);
	}

	tracks.remove(*track);
}

void MyTunesModel::deleteSong(Song * song){
	//Perform Cascaded Delete
	vector<Track*> theTracks = tracks.getCollection();
	for(vector<Track*>::iterator itr = theTracks.begin(); itr != theTracks.end(); itr++){
		Track* track = *itr;
		Song* trackSong = track->getSong();
		if(song == trackSong){
	       //Cascaded GLOBAL Delete
		   globalTrackDelete(track);
		}
	}
	songs.remove(*song);
}

void MyTunesModel::executeCMDSHOW(Command cmd,UI & view){
    //show recordings
    //show recordings -r recording_id
    //show songs
    //show songs -s song_id
    //show tracks
    //show tracks -t track_id
    //show users
    //show users -u user_id

	enum arguments {SHOW, COLLECTION, FLAG, MEMBER_ID};


	if(cmd.isTokenAt(COLLECTION, "songs") && cmd.hasToken("-s"))
		songs.showOn(view, stoi(cmd.getToken("-s")));
	else if(cmd.isTokenAt(COLLECTION, "songs") && cmd.hasToken("-u")){
		User * user = getUserByID(cmd.getToken("-u"));
		if(user == NULL)view.printOutput("Error: User not found");
		else user->showOn(view,cmd.getToken("-p"));
	}
	else if(cmd.isTokenAt(COLLECTION, "songs"))
		songs.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "recordings") && !cmd.hasToken("-r"))
		recordings.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "recordings") && cmd.hasToken("-r"))
		recordings.showOn(view, stoi(cmd.getToken("-r")));
	else if(cmd.isTokenAt(COLLECTION, "tracks") && !cmd.hasToken("-t"))
		tracks.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "tracks") && cmd.hasToken("-t"))
		tracks.showOn(view, stoi(cmd.getToken("-t")));
	else if(cmd.isTokenAt(COLLECTION, "users") && !cmd.hasToken("-u"))
		users.showOn(view);
	else if(cmd.isTokenAt(COLLECTION, "users") && cmd.hasToken("-u"))
		users.showOn(view, cmd.getToken("-u"));
    else view.printOutput("EXECUTING: " + cmd.getCommandString());
}
