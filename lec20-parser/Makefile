project 			 := lec20-parser

# Variables for path s of source, header
inc_dir 			 := ./include
src_dir 			 := ./src
sources 			 := $(wildcard ${src_dir}/*.c)

# Variables for paths of object file and binary targets
build_dir   		 := ./build
obj_dir 			 := ${build_dir}/obj
bin_dir 			 := ${build_dir}/bin
executable 			 := ${bin_dir}/${project}
build_dirs 			 := ${obj_dir} ${bin_dir}
objects 			 := $(subst .c,.o,$(subst ${src_dir},${obj_dir},${sources}))

# C Compiler Configuration
CC      			 := gcc # Using gcc compiler (alternative: clang)
CFLAGS				 := -I${inc_dir} -g -Wall -std=c11 -O0
# CFLAGS options:
# -g 			Compile with debug symbols in binary files
# -Wall 		Warnings: all - display every single warning
# -std=c11  	Use the C2011 feature set
# -I${inc_dir}  Look in the include directory for include files
# -O0 			Disable compilation optimizations

# Splint Configuration
SPLINT_FLAGS 		:= +charint +charintliteral

# Phony rules do not create artifacts but are usefull workflow
.PHONY: all run debug lint clean 
.PHONY: leak-check help variables path-to-bin

# all is the default goal
all: ${executable}

# help: Display useful goals in this Makefile
help:
	@echo "Try one of the following make goals:"
	@echo " * all - build project"
	@echo " * run - execute the project"
	@echo " * debug - begin a gdb process for the executable"
	@echo " * leak-check - begin a valgrind memory leak test"
	@echo " * clean - delete build files in project"
	@echo " * variables - print Makefile's variables"

# Execute the project's binary file
run: ${executable}
	@${^}

# Build the project by combining all object files
${executable}: ${objects} | ${bin_dir}
	${CC} ${CFLAGS} -o ${@} ${^}

# Build object files from sources in a template pattern
${obj_dir}/%.o: ${src_dir}/%.c | ${obj_dir}
	${CC} ${CFLAGS} -c -o ${@} ${<}

# The build directories should be recreated when prerequisite
${build_dirs}:
	mkdir -p ${@}

# Start a gdb process for the binary
debug: ${executable}
	gdb ${^}

# Run static analysis to find issues
lint:
	splint ${SPLINT_FLAGS} -I${inc_dir} ${sources}

# Start a valgrind process
leak-check: ${executable}
	valgrind --leak-check=full ${^}

# clean: Delete all artifacts produced in the build process
clean:
	rm -rf ${build_dir}

# variables: Print variables in this Makefile for Makefile debugging
variables:
	@echo "Sources: ${sources}"
	@echo "Executable: ${executable}"
	@echo "Build Dirs: ${build_dirs}"
	@echo "Objects: ${objects}"
	@echo "C Compiler: ${CC}"
	@echo "C Compiler Flags: ${CFLAGS}"
