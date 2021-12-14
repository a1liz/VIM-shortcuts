#include "ukey.h"

QString ukey_string[]= {
    "null",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
    "f1", "f2", "f3", "f4", "f5", "f6",
    "f7", "f8", "f9", "f10", "f11", "f12",
    "enter", "esc", "backspace", "tab", "space",
    "caps", "menu", "ctrl", "shift", "alt", "cmd",
    "rctrl", "rshift", "ralt","rcmd",
    "-", "=", "[", "]", "\\", ";", "'", "`", ",", ".", "/",
    "_", "+", "{", "}", "|", ":", "\"", "~", "<", ">", "?",
    "insert", "home", "page up", "delete", "end", "page down",
    "right", "left", "down", "up", "LM2", "LM3", "LM4"
};

ERROR_CODE ukey::registerLayer(int layer, UKEY_VALUE uv) {
    value[layer] = uv;
    return _NO_ERROR;
}
