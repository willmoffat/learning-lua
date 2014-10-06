include ../Makefile.common

test: luatest

luatest: libmessage.so
	lua script.lua

# -c 	Do not link.
# -fpic Position Independent Code.
%.o:	%.c
	$(CC) $(CFLAGS) -c -fpic $<

%.so:	%.o
	$(CC) --shared $< -o $@ 
