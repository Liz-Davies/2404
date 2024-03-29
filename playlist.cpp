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

#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"

Playlist::Playlist(const string & aPlaylistName){
	cout << "Playlist(string&)" << endl;
	subject = NULL;
	name = aPlaylistName;
}
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(const Playlist & aPlaylist)" << endl;
	cout << "ERROR: Playlist(const Playlist & aPlaylist) --should never run" << endl;
}

Playlist::~Playlist(){
	cout << "~Playlist(void)" << endl;
	for(ArrayList<Observer>::iterator itr = observers.begin(); itr != observers.end(); itr++) {
		itr->changeSubject(NULL);
	    observers.remove((*itr));
    }
}
//int Playlist::getID(){return -1;}
string Playlist::getName(){return name;}

vector<Track*> & Playlist::getTracks(){return tracks;}

vector<Track*>::iterator Playlist::findPosition(Track & aTrack){
	for (vector<Track*>::iterator itr = tracks.begin() ; itr < tracks.end(); ++itr)
		if(*itr == &aTrack)
	return tracks.end();
}

void Playlist::addTrack(Track & aTrack){
	//add track if it does not already exist
	if(subject!=NULL) return;
	vector<Track*>::iterator itr = findPosition(aTrack);
	tracks.push_back(&aTrack);
	notify();

}

void Playlist::removeTrack(Track & aTrack){
	if(subject!=NULL) return;
	vector<Track*>::iterator itr = findPosition(aTrack);
	if(itr != tracks.end()) {
		tracks.erase(itr);
		notify();
	}
}

string Playlist::toString()const {
	string indent = "     ";
	string s;
	s.append(name);
	s.append("\n");
	s.append(indent + indent + "Playlist Tracks:\n");
	for (vector<Track*>::size_type i = 0 ; i < tracks.size(); i++){
		   s.append(indent + indent + to_string(i) + " " + (tracks[i])->toString() + "\n");
	}
	return s;
}

void Playlist::update(Subject * sub){
	if(sub == NULL) return;
	if(sub == subject){
		Playlist * subb = (Playlist*)sub;
		tracks = subb->getTracks();
		notify();
	}else{
		sub->dettach(*this);
		cout << "\nPlaylists cannot follow more than one playlist, please dettach first" <<endl;
	}
}
void Playlist::printOn(ostream & out)const{
	out <<this->toString()<<endl;
}

ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
