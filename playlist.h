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

#ifndef _Playlist_H
#define _Playlist_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"
#include "manager.h"
#include "subject.h"
#include "observer.h"


class Playlist : public Manager, public Subject, public Observer{
	/*
	Playlist represents an user playlist of tracks.
	*/
	public:
	Playlist(const string & aPlaylistName);
	~Playlist(void);
    //int getID();
	string getName();
	void removeTrack(Track & aTrack);
	void addTrack(Track & aTrack);
	vector<Track*> & getTracks();
    string toString() const;
	virtual void update(Subject * sub);
	virtual void printOn(ostream & out) const;

	private:
	string name;
	vector<Track*> tracks;
	vector<Track*>::iterator findPosition(Track & aTrack);
	Playlist(const Playlist & aPlaylist); //hide copy constructor in private section
};

ostream & operator<<(ostream & out, const Playlist & aPlaylist);

#endif
