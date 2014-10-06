#include <stdio.h>
#include <math.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int l_sin(lua_State *L) {
  double d = luaL_checknumber(L, 1);
  lua_pushnumber(L, sin(d));
  return 1;
}

int main() {
  printf("Hello world\n");
  
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushcfunction(L, l_sin);
  lua_setglobal(L, "sin");

  if (luaL_dofile(L, "script.lua")) {
    lua_error(L);
  }

  lua_close(L);
  return 0;
}
