"# 2404"

Program:  MyTunes Music Player

Author(s):
    * Louis Nel
	* Sarah Davies  - 100828244
	* Mike Sayegh	- 101029473

Date:     05-12-2017

(c) 2017 Louis Nel
All rights reserved.  Distribution and
reposting, in part or in whole, requires
written consent of the author.

COMP 2404 students may reuse this content for
their course assignments without seeking consent

To compile:
make

To make clean:
make clean

To run:
./mytunes

The program reads the insert_beatles_tracks_rev1.txt script on startup.
To disable this behaviour comment out the lines:

  //initialize app with input script
  Command cmd = Command(".read insert_beatles_tracks_rev1.txt");
  executeCommand(cmd);

in the run() method at the start of the UI.cpp file.

To test commands (including a duplicate adds and delete attempts, following etc)

  .read Part2TestScript.txt
