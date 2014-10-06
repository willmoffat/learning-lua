/*
 * C program calling Lua script. 'rand' function provided by C.
 */
#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int l_rand(lua_State *L) {
  lua_pushnumber(L, 0.5);  // Randomly chosen!
  return 1;
}

int main() {
  printf("Hello world\n");
  
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushcfunction(L, l_rand);
  lua_setglobal(L, "rand");

  if (luaL_dofile(L, "script.lua")) {
    lua_error(L);
  }

  lua_close(L);
  return 0;
}
