#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// layer keycodes
#define KC_XXX		KC_NO // three "XXX" for no operation
#define KC_NUM		MO(1) // switch to layer num to have numbers and additional characters
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
#define KC_SFT1		LSFT_T(KC_1)
#define KC_SFTA		LSFT_T(KC_A)
#define KC_CTLO		LCTL_T(KC_O)
#define KC_ALTE		LALT_T(KC_E)
#define KC_CMDU		LCMD_T(KC_U)

// mod-tap's right
#define KC_SFT0		RSFT_T(KC_0)
#define KC_SFTS		RSFT_T(KC_S)
#define KC_CTLN		RCTL_T(KC_N)
#define KC_ALTT		RALT_T(KC_T)
#define KC_CMDH		RCMD_T(KC_H)


// layer
#define _DVORAK		0
#define _NUM		1
#define _FN		2
#define _VIM		3

enum custom_keycodes {
  DVORAK,
  NUM,
  FN,
  VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | GESC|  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | TAB |  '  |  ,  |  .  |  P  |  Y  |                |  F  |  G  |  C  |  R  |  L  |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     | SFTA| CTLO| ALTE| CMDU|  I  |                |  D  | CMDH| ALTT| CTLN| SFTS|     |
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |  ;  |  Q  |  J  |  K  |  X  | VIM /    \     |  B  |  M  |  W  |  V  |  Z  |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \  FN | DEL | VSPC  /        \ VENT| BSPC| NUM /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , XXX,
     TAB ,QUOT,COMM, DOT, P  , Y  ,                F  , G  , C  , R  , L  , XXX,
     XXX ,SFTA,CTLO,ALTE,CMDU, I  ,                D  ,CMDH,ALTT,CTLN,SFTS, XXX,
     XXX ,SCLN, Q  , J  , K  , X  ,VIM,       XXX, B  , M  , W  , V  , Z  , XXX,
                        FN, DEL,VSPC,         VENT, BSPC, NUM
  ),

  [_NUM] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |  `  |     |     |     |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |  =  |  -  |     |                |     |  /  |  \  |  [  |  ]  |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     | SFT1|  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  | SFT0|     |
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |     /    \     |     |     |     |  ٍ   |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \     |     |      /        \      |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     GRV , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , XXX,
     XXX , XXX , XXX , EQL , MINS, XXX ,                XXX , SLSH ,BSLS, LBRC, RBRC, XXX,
     XXX , SFT1,  2  ,  3  ,  4  ,  5  ,                 6  ,  7  ,  8  ,  9  , SFT0, XXX,
     XXX , XXX , XXX , XXX , XXX , XXX , XXX ,    XXX , XXX , XXX , XXX , XXX , XXX , XXX ,
                         XXX ,XXX, XXX ,          XXX , XXX, XXX
  ),

  [_FN] = LAYOUT_kc(
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |  F1 |  F2 |  F3 |  F4 |  F5 |                |  F6 |  F7 |  F8 |  F9 | F10 |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     | F11 | F12 |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     | LSFT| LCTL| LALT| LCMD|     |                |     | RCMD| RALT| RCTL| RSFT|     |
     * +-----+-----+-----+-----+-----+-----+-----.    ,-----+-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |Vol+ /    \     |     |     |     |     |     |     |
     * +-----+-----+-----+--+--+-----+-----+----/      \----+-----+-----+--+--+-----+-----+-----+
     *                      \  L0 |     | Vol- /        \      |     |     /
     *                       `----+-----+-----'          `-----+-----+----'
     */
     XXX , F1  , F2  , F3  , F4  , F5  ,                F6  , F7  , F8  , F9  , F10 , XXX ,
     XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , F11 , F12 , XXX ,
     XXX , LSFT, LCTL, LALT, LCMD, XXX ,                XXX , RCMD, RALT, RCTL, RSFT, XXX ,
     XXX , XXX , XXX , XXX , XXX , XXX , VOLU,    FN , XXX ,  XXX , XXX , XXX , XXX , XXX,
                            FN, XXX , VOLD,          XXX , XXX , XXX
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
