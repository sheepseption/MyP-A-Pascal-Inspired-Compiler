all :	pcode

pcode : PCode.c PCode.h
	gcc -c PCode.c

Ex1 :	pcode ex1.2_pcode.c
	gcc -o  Ex1 -g ex1.2_pcode.c PCode.o

Ex2 :	pcode ex2.2_pcode.c
	gcc -o  Ex2 -g ex2.2_pcode.c PCode.o

Ex3 :	pcode Ex3_pcode.c
	gcc -o Ex3 Ex3_pcode.c PCode.o

Ex4 :	pcode Ex4_pcode.c
	gcc -o Ex4 Ex4_pcode.c PCode.o

Ex5 :	pcode Ex5_pcode.c
	gcc -o Ex5 Ex5_pcode.c PCode.o

Ex6 :	pcode Ex6_pcode.c
	gcc -o Ex6 Ex6_pcode.c PCode.o

Ex7 :	pcode Ex7_pcode.c
	gcc -o Ex7 Ex7_pcode.c PCode.o
clean :
	rm -f *_pcode.c *.o
