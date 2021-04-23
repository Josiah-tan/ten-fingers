.PHONY: 1, 1cp, 2, 2cp
1: ./a.out
	cat 1.in | ./a.out

1cp: ./a.out
	cat 1.in | ./a.out | xclip -sel clip

2: ./a.out
	cat 2.in | ./a.out

2cp: ./a.out
	cat 2.in | ./a.out | xclip -sel clip

./a.out: main.cpp
	g++ main.cpp
