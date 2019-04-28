#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;


#define KC_XXX   KC_NO // three "XXX" for no operation

#define _DVORAK  0

enum custom_keycodes {
  DVORAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | ESC |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  | BSPC|
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | TAB |  '  |  ,  |  .  |  P  |  Y  |                |  F  |  G  |  C  |  R  |  L  |  /  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|  A  |  O  |  E  |  U  |  I  |                |  D  |  H  |  T  |  N  |  S  | RSFT|
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * | LCTL|  ;  |  Q  |  J  |  K  |  X  |     /    \     |  B  |  M  |  W  |  V  |  Z  | RCTL|
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \ LALT| LCMD| SPC  /        \  ENT |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
     TAB ,QUOT,COMM, DOT, P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
     LSFT, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,RSFT,
     LCTL,SCLN, Q  , J  , K  , X  , XXX,      XXX, B  , M  , W  , V  , Z  ,RCTL,
                       LALT,LCMD, SPC,         ENT, XXX, XXX
  )
};
