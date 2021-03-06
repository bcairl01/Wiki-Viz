#!/bin/bash
export WINSRC=/media/brian/Windows/Users/brian/Dropbox/lib_source_code
export HOME=~/Projects/Wiki-Viz


ls 	gcc_out/*.o
ls 	*.cpp
cd 	$HOME
sudo g++ -std=c++11								\
	-D WEBTOOLS_VERBOSE_L4						\
	-D WEBTOOLS_WITH_GRAPHLITE 					\
	-D WEBTOOLS_WITH_BOOST 						\
	-o Wiki_Viz.o 								\
	-w											\
	-fpermissive 								\
	-I ${WINSRC}/cpp/WebTools/include 			\
	-I /home/brian/Repo/UbiGraph/include 		\
	-I /usr/include								\
	gcc_out/*.o									\
	client.o 									\
												\
	-pthread									\
	-lcurl	 									\
	-lboost_system 								\
	-lboost_thread								\
	-lxmlrpc_client 							\
	-lxmlrpc 									\
	-lxmlrpc_util 								\
	-lxmlrpc_xmlparse 							\
	-lxmlrpc_xmltok 							\
	-lglut 										\
	-lGL										\
	-lGLU										\
	main.cpp



