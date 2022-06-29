LIBS=
TESTPATH=../Sample-Test1/
OPEN=

OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lgtest -lpthread
	OPEN=xdg-open
else
    LIBS=-lgtest
	OPEN=open
endif

all: s21_matrix_oop.a test

debug:
	make s21_matrix_oop.a
	g++ $(TESTPATH)test_main.cpp $(TESTPATH)test.cpp -o s21test.out $(LIBS) -L. -ls21_matrix_oop -g



s21_matrix_oop.a:
	g++ -c s21_matrix_oop.cpp
	ar rcs libs21_matrix_oop.a s21_matrix_oop.o
	ranlib libs21_matrix_oop.a

test:
	make s21_matrix_oop.a
	g++ $(TESTPATH)test_main.cpp $(TESTPATH)test.cpp -o s21test.out $(LIBS) -L. -ls21_matrix_oop
	make run_test

gcov_report:
	g++ --coverage s21_matrix_oop.cpp $(TESTPATH)test.cpp $(TESTPATH)test_main.cpp -o s21test.out $(LIBS)
	make run_test
	lcov -t "s21test" -o s21test.info -c -d .
	lcov --remove s21test.info -o s21test.info '/usr/*'
	lcov --remove s21test.info -o s21test.info '*test*'
	genhtml -o report s21test.info
	$(OPEN) report/index.html

run_test:
	./s21test.out

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info *.cfg ../Sample-Test1/*.cfg report

check:code_check code_style

code_check:
	cppcheck --quiet --enable=all --language=c++ --suppress=missingIncludeSystem --suppress=unusedFunction *.cpp *.h

code_style:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	cp ../materials/linters/CPPLINT.cfg ../Sample-Test1/
	python3 ../materials/linters/cpplint.py --quiet  --extension=cpp *.cpp *.h ../Sample-Test1/*.cpp

leaks:
	CK_FORK=no leaks --atExit --  ./s21test.out


