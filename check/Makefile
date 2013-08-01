CC = gcc
AR = ar
STRIP = strip
LCOV = lcov
GENHTML = genhtml

CFLAGS += -O2
LDFLAGS += -lcheck

CFLAGS += -I.

all: release

compile: test_runner

test: compile
	./test_runner

release: compile test
	${STRIP} test_runner

coverage: CFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory . --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/rectangle.c" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf *.o test_runner *.info *.gcda *.gcno coverage*

test_runner: rectangle_test.o rectangle.o test_runner.o
	${CC} -o test_runner rectangle.o *_test.o test_runner.o ${LDFLAGS}

test_runner.o: test_runner.c

rectangle_test.o: rectangle_test.c rectangle.h

rectangle.o: rectangle.c rectangle.h

.PHONY: clean generate.coverage.report
