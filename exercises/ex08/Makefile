GLIB_INCLUDE = /usr/local/Cellar/glib/2.46.2/lib/glib-2.0/include
GLIB_MAIN = /usr/local/Cellar/glib/2.46.2/include/glib-2.0/
INCDIRS = -I${GLIB_INCLUDE} -I${GLIB_MAIN}
C_FLAGS = ${INCDIRS}
LD_FLAGS = -lglib-2.0.0

ex-compile: ex_compile.c
	gcc $(GLIB_INCLUDE) -o ex-compile ex_compile.c $(LD_FLAGS)

wordCount: word_count.c 
	gcc ${C_FLAGS} -o wordCount word_count.c $(LD_FLAGS)