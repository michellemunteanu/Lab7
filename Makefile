sort: sort.o sortutil.o
	clang sortutil.o sort.o -o sort

sort.o: sort.c
	clang -c sort.c -Wall

sortutil.o: sortutil.c
	clang -c sortutil.c -Wall

clean:
	rm -f sort.o sortutil.o sort

test:
	./sort < sth.csv
