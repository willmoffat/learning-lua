/*
 * Trivial C program calling a Lua script.
 */

#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main() {
  printf("Hello world from C\n");
  
  // Embed Lua.
  lua_State *L = luaL_newstate();
  
  // Load the standard libs. Without this you get the error:
  //   "attempt to call global `print' (a nil value)"
  luaL_openlibs(L);

  // Run the script.
  if (luaL_dofile(L, "script.lua")) {
    // Display error.
    lua_error(L);
  }
  // Free resources.
  lua_close(L);

  return 0;
}
