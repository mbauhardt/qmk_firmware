#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// layer keycodes
#define KC_XXX		KC_NO // three "XXX" for no operation
#define KC_DVRK2	MO(1) // switch to layer dvorak2 to have additional characters
#define KC_FN		TG(2) // fn keys, volume keys
#define KC_VIM		TG(3) // "VIM" mode, this layer is there to navigate in a browser or os related editor which is not vim based
#define KC_VSPC		LT(3, KC_SPC) // "VIM" mode, this layer is there to navigate in a browser or os related editor which is not vim based
#define KC_VENT		LT(3, KC_ENT) // "VIM" mode, this layer is there to navigate in a browser or os related editor which is not vim based

// VIM based shortcuts while working in a OS text editor or browser textfield
#define KC_ALTL		LALT(KC_LEFT)
#define KC_ALTR		LALT(KC_RGHT)
#define KC_CMDL		LCMD(KC_LEFT)
#define KC_CMDR		LCMD(KC_RGHT)
#define KC_CMDC		LCMD(KC_C)
#define KC_CMDX		LCMD(KC_X)
#define KC_CMDV		LCMD(KC_V)

// mod-tap's left
#define KC_SFTA		LSFT_T(KC_A)
#define KC_CTLO		LCTL_T(KC_O)
#define KC_ALTE		LALT_T(KC_E)
#define KC_CMDU		LCMD_T(KC_U)

// mod-tap's right
#define KC_SFTS		RSFT_T(KC_S)
#define KC_CTLN		RCTL_T(KC_N)
#define KC_ALTT		RALT_T(KC_T)
#define KC_CMDH		RCMD_T(KC_H)


// layer
#define _DVORAK		0
#define _DVORAK_2	1
#define _FN		2
#define _VIM		3

enum custom_keycodes {
  DVORAK,
  DVORAK_2,
  FN,
  VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | GESC|  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  | BSPC|
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | TAB |  '  |  ,  |  .  |  P  |  Y  |                |  F  |  G  |  C  |  R  |  L  |  /  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     | SFTA| CTLO| ALTE| CMDU|  I  |                |  D  | CMDH| ALTT| CTLN| SFTS|     |
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |  ;  |  Q  |  J  |  K  |  X  | VIM /    \  FN |  B  |  M  |  W  |  V  |  Z  |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \     |     | VSPC  /        \  VENT | DVRK2|DVRK2/
     *                       `----+-----+-----'          `-----+-----+----'
     */
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
     TAB ,QUOT,COMM, DOT, P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
     XXX ,SFTA,CTLO,ALTE,CMDU, I  ,                D  ,CMDH,ALTT,CTLN,SFTS, XXX,
     XXX ,SCLN, Q  , J  , K  , X  ,VIM,      FN, B  , M  , W  , V  , Z  ,   XXX,
                       XXX,XXX, VSPC,         VENT, DVRK2, DVRK2
  ),

  [_DVORAK_2] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |  `  |     |     |     |     |     |                |     |     |     |     |  [  |  ]  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |  =  |  \  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|     |     |     |     |     |                |     |     |     |     |     |  -  |
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |     /    \     |     |     |     |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \     |     |      /        \      |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     GRV , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , LBRC, RBRC,
     XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , EQL , BSLS,
     LSFT, XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , MINS,
     XXX , XXX , XXX , XXX , XXX , XXX , XXX ,    XXX , XXX , XXX , XXX , XXX , XXX,  XXX ,
                         LALT ,LCMD , SPC ,          XXX , XXX, XXX
  ),

  [_FN] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |  F1 |  F2 |  F3 |  F4 |  F5 |                |  F6 |  F7 |  F8 |  F9 | F10 | F11 |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |     | F12 |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|     |     |     |     |     |                |     |     |     |     |     | RSFT|
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |     /    \     |     |     |     |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \ LALT| LCMD|      /        \      | Vol+| Vol-/
     *                       `----+-----+-----'          `-----+-----+----'
     */
     XXX , F1  , F2  , F3  , F4  , F5  ,                F6  , F7  , F8  , F9  , F10 , F11 ,
     XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , F12 ,
     LSFT, XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , RSFT,
     XXX , XXX , XXX , XXX , XXX , XXX , XXX ,    FN , XXX ,  XXX , XXX , XXX , XXX , XXX,
                         LALT ,LCMD , XXX ,          XXX , VOLU, VOLD
  ),

  [_VIM] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     | HOME|     |                |     |     |     |     |  END| BSPC|
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |PASTE| COPY|                |     |     |     |     | RGHT|     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | LSFT|     |     |     |     |     |                | CUT | LEFT|     |     |     | RSFT|
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     | DOWN|  UP | DEL |     /    \     |  BW |     |  FW |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \     |     |      /        \  ENT |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     XXX , XXX , XXX , XXX , CMDR , XXX ,                XXX , XXX , XXX , XXX ,CMDL, BSPC,
     XXX , XXX , XXX , XXX , CMDV, CMDC,                XXX , XXX , XXX , XXX , RGHT, XXX ,
     LSFT, XXX , XXX , XXX , XXX , XXX ,                CMDX, LEFT, XXX , XXX , XXX , RSFT,
     XXX , XXX , XXX , DOWN,  UP , DEL , XXX ,    XXX , ALTL, XXX , ALTR, XXX , XXX , XXX ,
                         XXX , XXX, XXX ,          ENT , VIM, XXX
  ),
};
