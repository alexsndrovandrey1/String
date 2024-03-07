all: gcov_report

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
else ifeq ($(UNAME), Darwin)
GCOV_FLAGS := -fprofile-arcs -ftest-coverage -lgcov
endif

test:
	gcc -c $(GCOV_FLAGS) s21_string.c
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a
	gcc -c test.c
	gcc test.o s21_string.a -lcheck -lsubunit $(GCOV_FLAGS) -lm -o test
	rm -rf *.o *.a
	./test

s21_string.a:
	gcc -c s21_string.c
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a

gcov_report: test
	lcov -o s21_string.info -c -d .
	genhtml -o report s21_string.info
ifeq ($(UNAME), Darwin)
	open report/index.html
else ifeq ($(UNAME), Linux)
	xdg-open report/index.html
endif
	rm -rf *.o *.a *.gcno *.gcda *.info test

clean: 
	rm -rf *.o *.a *.gcno *.gcda *.info report test