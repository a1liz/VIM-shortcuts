#ifndef TYPE_H
#define TYPE_H

/*
 * key_width
*/
enum UKEY_WIDTH {
    _EMPTY=0, _100U, _125U, _150U, _175U, _200U, _225U, _275U, _600U, _625U, _700U
};

enum UKEY_STATUS {
    _await=0, _press, _hold
};

enum ERROR_CODE {
    _NO_ERROR=0, _VALUE_ERROR
};

enum UKEY_VALUE {
    _null=0,
    _a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,
    _n,_o,_p,_q,_r,_s,_t,_u,_v,_w,_x,_y,_z,
    _A,_B,_C,_D,_E,_F,_G,_H,_I,_J,_K,_L,_M,
    _N,_O,_P,_Q,_R,_S,_T,_U,_V,_W,_X,_Y,_Z,
    _1,_2,_3,_4,_5,_6,_7,_8,_9,_0,
    _exclamation_mark,_at,_pound,_dollar,
    _percent,_carat,_and,_asterisk,
    _left_parenthesis,_right_parenthesis,
    _F1,_F2,_F3,_F4,_F5,_F6,
    _F7,_F8,_F9,_F10,_F11,_F12,
    _enter, _esc, _backspace, _tab, _space, _caps,_menu,
    _ctrl, _shift, _alt, _cmd, _rctrl, _rshift, _ralt, _rcmd,
    _dash, _equal, _open_bracket, _close_bracket, _backslash,
    _semicolon, _single_quote, _back_quote, _comma, _dot, _slash,
    _underscore, _plus, _open_brace, _close_brace, _pipe, _colon,
    _double_quotes, _tilde, _less_than, _greater_than, _question_mark,
    _insert, _home, _page_up, _delete, _end, _page_down,
    _right, _left, _down, _up, _temp_layer2, _temp_layer3, _temp_layer4,
};

#endif // TYPE_H
