GCC = gcc
# Compiler flags required at compilation time
CFLAGS = -Wall -Werror -Wextra -pedantic
# Header file used
DEPS = simple_shell.h

simple_shell: ${DEPS}
	${GCC} $(CFLAGS) $@.c built_ins.c pathfinder.c simple_helpers.c -o $@

clean:
	$(RM) *.o
	$(RM) simple_shell
