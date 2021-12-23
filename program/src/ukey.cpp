#include "ukey.h"

QString ukey_string[] = {
    "null", "a",         "b",     "c",         "d",    "e",       "f",
    "g",    "h",         "i",     "j",         "k",    "l",       "m",
    "n",    "o",         "p",     "q",         "r",    "s",       "t",
    "u",    "v",         "w",     "x",         "y",    "z",       "A",
    "B",    "C",         "D",     "E",         "F",    "G",       "H",
    "I",    "J",         "K",     "L",         "M",    "N",       "O",
    "P",    "Q",         "R",     "S",         "T",    "U",       "V",
    "W",    "X",         "Y",     "Z",         "1",    "2",       "3",
    "4",    "5",         "6",     "7",         "8",    "9",       "0",
    "!",    "@",         "#",     "$",         "%",    "^",       "&",
    "*",    "(",         ")",     "f1",        "f2",   "f3",      "f4",
    "f5",   "f6",        "f7",    "f8",        "f9",   "f10",     "f11",
    "f12",  "enter",     "esc",   "backspace", "tab",  "space",   "caps",
    "menu", "ctrl",      "shift", "alt",       "cmd",  "rctrl",   "rshift",
    "ralt", "rcmd",      "-",     "=",         "[",    "]",       "\\",
    ";",    "'",         "`",     ",",         ".",    "/",       "_",
    "+",    "{",         "}",     "|",         ":",    "\"",      "~",
    "<",    ">",         "?",     "insert",    "home", "page up", "delete",
    "end",  "page down", "right", "left",      "down", "up",      "LM2",
    "LM3",  "LM4"};

uKey::uKey(UKEY_WIDTH uw, UKEY_VALUE uv) {
  width = uw;
  value[0] = uv;
  value[1] = value[2] = value[3] = _null;
  vicevalue[0] = vicevalue[1] = vicevalue[2] = vicevalue[3] = _null;
}

uKey::uKey(UKEY_WIDTH uw, UKEY_VALUE uv0, UKEY_VALUE uv1, UKEY_VALUE uv2,
           UKEY_VALUE uv3, UKEY_VALUE uvv0, UKEY_VALUE uvv1, UKEY_VALUE uvv2,
           UKEY_VALUE uvv3) {
  width = uw;
  value[0] = uv0;
  value[1] = uv1;
  value[2] = uv2;
  value[3] = uv3;
  vicevalue[0] = uvv0;
  vicevalue[1] = uvv1;
  vicevalue[2] = uvv2;
  vicevalue[3] = uvv3;
}

ERROR_CODE uKey::registerLayer(int layer, UKEY_VALUE uv) {
  value[layer] = uv;
  return _NO_ERROR;
}

QString uKey::getValue(int valueid) {
  if (valueid > 3 || valueid < 0) Q_ASSERT(0);
  return ukey_string[value[valueid]];
}

QString uKey::getViceValue(int valueid) {
  if (valueid > 3 || valueid < 0) Q_ASSERT(0);
  return ukey_string[vicevalue[valueid]];
}

UKEY_WIDTH uKey::getWidth() { return width; }
