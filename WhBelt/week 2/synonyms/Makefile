all:
	g++ -g -Wall -pedantic-errors -std=c++17 .\synonyms.cpp
exec:
	.\a.exe < ${ARGS} > ${ARGS}_output
	code ${ARGS}_output
clean:
	Remove-Itemp *.exe *_output
