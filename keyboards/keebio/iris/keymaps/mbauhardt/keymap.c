#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// keycodes
#define KC_XXX		KC_NO // three "XXX" for no operation
#define KC_DVRK2	MO(1) // switch to layer dvorak2 to have additional characters
#define KC_FN		MO(2) // fn keys, volume keys

// layer
#define _DVORAK		0
#define _DVORAK_2	1
#define _FN		2

enum custom_keycodes {
  DVORAK,
  DVORAK_2,
  FN
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
     * | LCTL|  ;  |  Q  |  J  |  K  |  X  | FN  /    \  FN |  B  |  M  |  W  |  V  |  Z  | RCTL|
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \ LALT| LCMD| SPC  /        \  ENT |     |DVRK2/
     *                       `----+-----+-----'          `-----+-----+----'
     */
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
     TAB ,QUOT,COMM, DOT, P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
     LSFT, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,RSFT,
     LCTL,SCLN, Q  , J  , K  , X  , FN,      FN, B  , M  , W  , V  , Z  ,RCTL,
                       LALT,LCMD, SPC,         ENT, XXX, DVRK2
  ),

  [_DVORAK_2] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |  `  |     |     |     |     |     |                |     |     |     |     |  [  |  ]  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |  =  |  \  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|     |     |     |     |     |                |     |     |     |     |  -  | RSFT|
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |     /    \     |     |     |     |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \     |     |      /        \      |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     GRV , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , LBRC, RBRC,
     XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , EQL , BSLS,
     LSFT, XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , MINS, RSFT,
     XXX , XXX , XXX , XXX , XXX , XXX , XXX ,    XXX , XXX ,  XXX , XXX , XXX , XXX , XXX ,
                         LALT ,LCMD , SPC ,          XXX , XXX, XXX
  ),

  [_FN] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |                | F7  |  F8 |  F9 | F10 | F11 | F12 |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|     |     |     |     |     |                |     |     |     |     |     | RSFT|
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |     /    \     |     |     |     |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \ LALT| LCMD|      /        \      | Vol+| Vol-/
     *                       `----+-----+-----'          `-----+-----+----'
     */
     F1  , F2  , F3  , F4  , F5  , F6  ,                F7  , F8  , F9  , F10 , F11 , F12 ,
     XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , XXX ,
     LSFT, XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , RSFT,
     XXX , XXX , XXX , XXX , XXX , XXX , XXX ,    XXX , XXX ,  XXX , XXX , XXX , XXX , XXX ,
                         LALT ,LCMD , XXX ,          XXX , VOLU, VOLD
  )
};
