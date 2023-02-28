LIBS=
TESTPATH=../tests/
OPEN=

OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lgtest -lpthread
	OPEN=xdg-open
else
    LIBS=-lgtest
	OPEN=open
endif

all: matrix.a test

debug:
	make matrix.a
	g++ $(TESTPATH)test_main.cpp $(TESTPATH)test.cpp -o test.out $(LIBS) -L. -lsmatrix -g

matrix.a:
	g++ -c matrix.cpp
	ar rcs libmatrix.a matrix.o
	ranlib libmatrix.a

test:
	make matrix.a
	g++ $(TESTPATH)test_main.cpp $(TESTPATH)test.cpp -o test.out $(LIBS) -L. -lmatrix
	make run_test

gcov_report:
	g++ --coverage matrix.cpp $(TESTPATH)test.cpp $(TESTPATH)test_main.cpp -o test.out $(LIBS)
	make run_test
	lcov -t "test" -o test.info -c -d .
	lcov --remove test.info -o test.info '/usr/*'
	lcov --remove test.info -o test.info '*test*'
	genhtml -o report test.info
	$(OPEN) report/index.html

run_test:
	./test.out

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info *.cfg $(TESTPATH)*.cfg report

code_check:
	cppcheck --quiet --enable=all --language=c++ --suppress=missingIncludeSystem --suppress=unusedFunction *.cpp *.h

leaks:
	CK_FORK=no leaks --atExit --  ./test.out


