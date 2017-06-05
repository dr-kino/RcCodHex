################################################################################
bin_PROGRAMS = rccodhex

# test application
rccodhex_SOURCES = \
	../src/gen_cmd.c \
	../src/rccodhex_cmd.c \
	../src/exec-codhex_cmd.c \
	../src/split-bitstream.cpp \
	../src/split-bitstream_wrapper.cpp \
	../src/rccodhex.cpp

rccodhex_CPPFLAGS = ${USERAPP_CFLAGS} ${DBGFLAGS} \
	-I../include

rccodhex_CFLAGS = ${USERAPP_CFLAGS} ${DBGFLAGS} \
	-I../include

rccodhex_LDFLAGS = ${USERAPP_LDFLAGS} ${DBGFLAGS}

rccodhex_LDADD =-lm -lreadline -lncurses

