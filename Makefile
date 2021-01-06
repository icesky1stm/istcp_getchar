### 基本参数定义
BIN  := \
istcp_getchar \

OBJ  += istcp.o
OBJ  += istcp_getchar.o

LIBS :=

CFLAGS  += -Wall -std=c99 -I./

LDFLAGS +=

.SUFFIXES: .c .so .o

.PHONY: all
all: $(BIN)

.PHONY: $(BIN)
$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o $(BIN)

%.c:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@ $<

