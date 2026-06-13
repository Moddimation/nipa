CC      = gcc
CFLAGS  = -O3 -Wno-missing-braces -std=c99 -I.
LDFLAGS = -lz

TARGET  = nipa

SRCS = nipa.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET) install

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

install:
	sudo cp $(TARGET) /usr/local/bin/nipa

.PHONY: all clean install
