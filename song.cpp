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

#include "str_util.h"
#include "song.h"

Song::Song(const string & aTitle, const string & aComposer, const int anID){
	cout << "Song(string&, string&, int)" << endl;
	title = aTitle;
	composer = aComposer;
	id = anID;
}
Song::Song(const Song & aSong){
	cout << "Song(const Song & aSong)" << endl;
	cout << "ERROR: Song(const Song & aSong) --should never run" << endl;
}
Song::~Song(){
	cout << "~Song(void)" << endl;
}
//int Song::getID() const {return id;}
string Song::getTitle() const {return StrUtil::toTitleCase(title);}

string Song::toString()const {
	return to_string(id) + " " + getTitle() + " " + composer;
}

ostream & operator<<(ostream & out, const Song & aSong){
	out << aSong.toString() << endl;
	return out;
}
