CC_R = gcc

TARGETS = test01 test02 test03

OBJS = test01.o test02.o test03.o

SRCS = $(OBJS:.o=.c)

$(TARGETS): $(OBJS)
	$(CC_R) -o $@ $@.o

clean:
	rm $(OBJS) $(TARGETS)

run:
	test01
	test02
	test03
