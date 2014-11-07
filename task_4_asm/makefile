all: proc_1 asm disasm

CC = gcc
CFALGS = -Wall

proc_1: main.o functions_proc.o stack.o
	$(CC) $^ -o $@

asm: asm.o functions_asm.o
	$(CC) $^ -o $@

disasm: disasm.o functions_asm.o
	$(CC) $^ -o $@



main.o: main.c
	$(CC) $(CFALGS) -c $^ -o $@

functions_proc.o: functions_proc.c
	$(CC) $(CFALGS) -c $^ -o $@

stack.o: stack.c
	$(CC) $(CFALGS) -c $^ -o $@



asm.o: asm.c
	$(CC) $(CFALGS) -c $^ -o $@

disasm.o: disasm.c
	$(CC) $(CFALGS) -c $^ -o $@

functions_asm.o: functions_asm.c
	$(CC) $(CFALGS) -c $^ -o $@



clean: 
	rm proc_1 asm disasm *.o
