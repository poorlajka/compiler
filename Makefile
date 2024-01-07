comp = clang
comp_flags = -Wall -g
obj_files = main.o vec.o lexer.o cl-flag-parser.o
bin = compiler

all: $(bin)

run: $(bin)
	./compiler

$(bin): $(obj_files) 
	$(comp) $(comp_flags) $(obj_files) -o $(bin)

%.o: %.c
	$(comp) $(comp_flags) -c $< -o $@

clean:
	rm -r $(bin) *.o *.dSYM