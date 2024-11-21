all :	pcode
EX_DIR = ../Examples
pcode : PCode.c PCode.h
	gcc -c PCode.c

Ex1.1 :	pcode $(EX_DIR)/ex1.1_pcode.c
	gcc -o  Ex1.1 -g -I $(EX_DIR)/ex1.1_pcode.c PCode.o

Ex1.2 :	pcode $(EX_DIR)/ex1.2_pcode.c
	gcc -o  Ex1.2 -g -I./ $(EX_DIR)/ex1.2_pcode.c PCode.o 

Ex1.3 :	pcode $(EX_DIR)/ex1.3_pcode.c
	gcc -o  Ex1.3 -g -I./ $(EX_DIR)/ex1.3_pcode.c PCode.o

Ex1.4 :	pcode $(EX_DIR)/ex1.4_pcode.c
	gcc -o  Ex1.4 -g -I./ $(EX_DIR)/ex1.4_pcode.c PCode.o

Ex2.1 :	pcode $(EX_DIR)/ex2.1_pcode.c
	gcc -o  Ex2.1 -g -I./ $(EX_DIR)/ex2.1_pcode.c PCode.o

Ex2.2 :	pcode $(EX_DIR)/ex2.2_pcode.c
	gcc -o  Ex2.2 -g -I./ $(EX_DIR)/ex2.2_pcode.c PCode.o

Ex3.1 :	pcode $(EX_DIR)/ex3.1_pcode.c
	gcc -o Ex3.1 -I./ $(EX_DIR)/ex3.1_pcode.c PCode.o
	
Ex3.2:	pcode $(EX_DIR)/ex3.2_pcode.c
	gcc -o Ex3.2 -I./ $(EX_DIR)/ex3.2_pcode.c PCode.o

Ex3.3 :	pcode $(EX_DIR)/ex3.3_pcode.c
	gcc -o Ex3.3 -I./ $(EX_DIR)/ex3.3_pcode.c PCode.o

Ex3.4 :	pcode $(EX_DIR)/ex3.4_pcode.c
	gcc -o Ex3.4 -I./ $(EX_DIR)/ex3.4_pcode.c PCode.o


clean :
	rm -f *_pcode.c *.o
