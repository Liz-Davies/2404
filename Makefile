OBJ = main.o mytunes.o mytunesmodel.o UI.o command.o str_util.o song.o recording.o track.o user.o playlist.o manager.o
mytunes: $(OBJ)
	g++ -o mytunes $(OBJ)

main.o:	main.cpp
	g++ -c -std=c++11 main.cpp

mytunes.o:	mytunes.cpp mytunes.h
	g++ -c -std=c++11 mytunes.cpp

mytunesmodel.o: mytunesmodel.cpp mytunesmodel.h
	g++ -c -std=c++11 mytunesmodel.cpp

UI.o:	UI.cpp UI.h
	g++ -c -std=c++11 UI.cpp

command.o:	command.cpp command.h
	g++ -c -std=c++11 command.cpp

song.o:	song.cpp song.h
	g++ -c -std=c++11 song.cpp

user.o:	user.cpp user.h
	g++ -c -std=c++11 user.cpp

playlist.o:	playlist.cpp playlist.h
	g++ -c -std=c++11 playlist.cpp

recording.o: recording.cpp recording.h
	g++ -c -std=c++11 recording.cpp

track.o:	track.cpp track.h
	g++ -c -std=c++11 track.cpp

manager.o: manager.cpp manager.h
	g++ -c -std=c++11 manager.cpp

str_util.o:	str_util.cpp str_util.h
	g++ -c -std=c++11 str_util.cpp

clean:
	rm -f $(OBJ) mytunes
