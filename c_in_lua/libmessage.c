// http://stackoverflow.com/questions/19118176/lua-5-2-cant-access-function-in-c-library?rq=1
// http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

#include "lua.h"
#include "lauxlib.h"

static int l_greet(lua_State *L)
{
  const char *result = "C hello world!";
  lua_pushstring(L, result);
  return 1;
}

static const luaL_Reg libmessage [] = {
  {"greet", l_greet},
  {NULL, NULL}  /* sentinel */
};

int luaopen_libmessage(lua_State *L) {
  luaL_newlibtable(L, libmessage);
  luaL_setfuncs(L, libmessage, 0);
  return 1;
}
