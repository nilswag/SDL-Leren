srcs := $(shell find src/ -name "*.c")
objs := $(addprefix bin/, $(srcs:.c=.o))

target = bin/out.exe
cc = x86_64-w64-mingw32-gcc
cflags = -Wall
lflags = -lmingw32

.PHONY: all
all: $(target)
	@echo "done."

$(target): $(objs)
	@echo "linking ..."
	$(cc) $^ -o $@ -Ldependnecies/lib $(lflags)

bin/%.o: %.c
	@echo "compiling $<"
	@mkdir -p $(@D)
	$(cc) -c $< -o $@ -Isrc/ -Idependencies/include $(cflags)

.PHONY: clean
clean:
	@rm -fr $(target) bin/src
