CFLAGS = -c -std=c++11 #-DDEBUG

all:		test

test:		test.o Livro.o Palavra.o Pagina.o LeitorArquivo.o
			g++ -o test test.o Livro.o Palavra.o Pagina.o LeitorArquivo.o

test.o:		test.cpp LeitorArquivo.h Pagina.hpp
			g++ ${CFLAGS} test.cpp

Palavra.o:	Palavra.cpp Palavra.hpp
	        g++ ${CFLAGS} Palavra.cpp

Pagina.o:	Pagina.cpp Pagina.hpp Palavra.hpp
	        g++ ${CFLAGS} Pagina.cpp

Livro.o:	Livro.cpp Livro.hpp
	        g++ ${CFLAGS} Livro.cpp

LeitorArquivo.o:	LeitorArquivo.cpp LeitorArquivo.h
	        g++ ${CFLAGS} LeitorArquivo.cpp

clean:
			rm -f test test.o Livro.o Palavra.o Pagina.o LeitoArquivo.o