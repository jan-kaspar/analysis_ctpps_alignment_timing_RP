all: print

print : print.cc
	g++ `root-config --libs` -lMinuit `root-config --cflags` \
		-g -O3 --std=c++14 -Wall -Wextra -Wno-attributes\
			print.cc -o print
