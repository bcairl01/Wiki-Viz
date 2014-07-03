#!/bin/bash
clear
export WINSRC=/media/brian/Windows/Users/brian/Dropbox/lib_source_code
export HOME=~/Projects/Wiki-Viz



sudo rm -r gcc_out
sudo mkdir gcc_out


#Make WebTools
ls 	${WINSRC}/cpp/WebTools/source
cd 	gcc_out	
sudo g++ -std=c++11								\
	-D WEBTOOLS_WITH_BOOST						\
	-D WEBTOOLS_WITH_GRAPHLITE					\
	-D WEBTOOLS_VERBOSE_L3						\
	-w											\
	-I ${WINSRC}/cpp/WebTools/include 			\
	-I /usr/include								\
	-c ${WINSRC}/cpp/WebTools/source/**.cpp		\
	-lcurl	 									\
	-pthread									\
	-lboost_system 								\
	-lboost_thread								\
	-Wall
