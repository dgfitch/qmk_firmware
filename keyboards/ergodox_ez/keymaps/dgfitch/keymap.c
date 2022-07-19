#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_steno.h"

/*
See cortex/notes/ergodox
*/


enum layers {
  STENO,    // virtual serial steno layer
  BASE,     // default "normal" qwerty layer
  MNAV,     // media keys
  WNAV,     // mouse, window manager and app control keys
  SYMB,     // symbols
  UNI1,     // unicode insanity begins
  UNI2,     // 2
  UNI3,     // 3
  NUMS,     // number and F keys
  NUMSALT,  // alt numbers on home row
  NUMSCTL,  // control numbers on home row
  TMUX,     // tmux control layer
};

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  TMUX0,
  TMUX1,
  TMUX2,
  TMUX3,
  TMUX4,
  TMUX5,
  TMUX6,
  TMUX7,
  TMUX8,
  TMUX9,
  TMUXB,
  TMUXC,
  TMUXH,
  TMUXJ,
  TMUXK,
  TMUXL,
  TMUXZ,
  TMUXQ,
  TMUXW,
  TMUXE,
  TMUXR,
  TMUXT,
  TMUXCMD,
};

enum unicode_names {
  EN,
  EM,
  SEC,
  PAR,
  BULL,
  NE,
  LTE,
  GTE,
  BANG,
  IRONY,
  PENTA,
  DELTA,
  BOWTIE,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  UPDN,
  SNEK,
  TREX,
  TURT,
  OCT,
  CORN,
  BRAIN,
  DIZZY,
  CHAT,
  ANGER,
  SHOUT,
  PIZZA,
  TACO,
  YAM,
  HOLE,
  HEART,
  SAX,
  TOOT,
  TUNE,
  FIRE,
  POOP,
  SKULL,
  CLOWN,
  SPRK,
  ZAP,
  WARN,
  DONT,
  BIO,
  RADIO,
  NO,
  NOPHONE,
  NOWALK,
  THDN,
  THUP,
  FSLF,
  FSRT,
  FSUP,
  FIST,
  METAL,
  PINCH,
  EAR,
  FOOT,
  LEG,
  NOSE,
  FLEX,
  NAIL,
  WRITE,
  PRAY,
  H1,
  H2,
  H3,
  H4,
  H5,
  DET,
  XD,
  WINK2,
  XDP,
  ZANY,
  LOL,
  SWEAT,
  SMILE,
  WINK,
  GRIN,
  GRIN2,
  GRIN3,
  BEAM,
  KEKE,
  NERD,
  COOL,
  HUG,
  WHAT,
  SMULE,
  THINK,
  BROW,
  BLAH,
  FLAT,
  BLANK,
  SLEEP,
  EESH,
  URGH,
  PLEA,
  SURP,
  MAD1,
  MAD2,
  FURY,
  SWEAR,
  DITZY,
  DRUNK,
  CRY1,
  CRY2,
  NAUS,
  PUKE,
  HOT,
  COLD,
  U1,
  U2,
  U3,
  U4,
  U5,
  U6,
  U7,
  U8,
  U9,
  U10,
};

const uint32_t PROGMEM unicode_map[] = {
  [EN]      = 0x2013,  // –
  [EM]      = 0x2014,  // 
  [SEC]     = 0x00A7,  // §
  [PAR]     = 0x00B6,  // ¶
  [BULL]    = 0x2022,  //  
  [NE]      = 0x2260,  // ≠
  [LTE]     = 0x2264,  // ≤
  [GTE]     = 0x2265,  // ≥
  [BANG]    = 0x203D,  // ‽
  [IRONY]   = 0x2E2E,  // ⸮
  [PENTA]   = 0x26E4,  // ⛤
  [DELTA]   = 0x25B3,  // △
  [BOWTIE]  = 0x22C8,  // ⋈
  [UP]      = 0x21E7,  // ⇧ 
  [DOWN]    = 0x21E9,  // ⇩
  [LEFT]    = 0x21E6,  // ⇦
  [RIGHT]   = 0x21E8,  // ⇨
  [UPDN]    = 0x21F3,  // ⇳
  [SNEK]    = 0x1F40D, // 🐍
  [TREX]    = 0x1F996, // 
  [TURT]    = 0x1F422, // 🐢
  [OCT]     = 0x1F419, // 🐙
  [CORN]    = 0x1F33D, // 🌽
  [BRAIN]   = 0x1F9E0, // 🧠
  [PIZZA]   = 0x1F355, // 
  [TACO]    = 0x1F32E, // 
  [DIZZY]   = 0x1F4AB, // 💫
  [CHAT]    = 0x1F4AC, // 💬
  [ANGER]   = 0x1F4A2, // 💢
  [SHOUT]   = 0x1F5EF, // 🗯️
  [YAM]     = 0x1F360, // 🍠
  [HOLE]    = 0x1F573, // 🕳️
  [HEART]   = 0x1F9E1, // 🧡
  [SAX]     = 0x1F3B7, // 🎷
  [TOOT]    = 0x1F3BA, // 🎺
  [TUNE]    = 0x1F3B6, // 🎶
  [FIRE]    = 0x1F525, // 🔥
  [POOP]    = 0x1F4A9, // 💩
  [SKULL]   = 0x1F480, // 💀
  [CLOWN]   = 0x1F921, // 🤡
  [SPRK]    = 0x2728,  // ✨
  [ZAP]     = 0x1F329, // 🌩️
  [WARN]    = 0x26A0,  // ⚠️
  [DONT]    = 0x26D4,  // ⛔
  [BIO]     = 0x2623,  // ☣️
  [RADIO]   = 0x2622,  // ☢️
  [NO]      = 0x1F6AB, // 🚫
  [NOPHONE] = 0x1F4F5, // 📵
  [NOWALK]  = 0x1F6B7, // 🚷
  [THDN]    = 0x1F44E, // 👎
  [THUP]    = 0x1F44D, // 👍
  [FSLF]    = 0x1F91B, // 🤛
  [FSRT]    = 0x1F91C, // 🤜
  [FSUP]    = 0x270A,  // ✊
  [FIST]    = 0x1F44A, // 👊
  [METAL]   = 0x1F918, // 🤘
  [PINCH]   = 0x1F90F, // 🤏
  [EAR]     = 0x1F442, // 👂
  [FOOT]    = 0x1F9B6, // 🦶
  [LEG]     = 0x1F9B5, // 🦵
  [NOSE]    = 0x1F443, // 👃
  [FLEX]    = 0x1F4AA, // 💪
  [NAIL]    = 0x1F485, // 💅
  [WRITE]   = 0x270D,  // ✍️
  [PRAY]    = 0x1F64F, // 🙏
  [H1]      = 0x261D,  // ☝️
  [H2]      = 0x270C,  // ✌️
  [H3]      = 0x1F450, // 👐
  [H4]      = 0x1F596, // 🖖
  [H5]      = 0x270B,  // ✋

  [DET]     = 0x1F64F, // 🕵️

  [XD]      = 0x1F606, // 😆
  [WINK2]   = 0x1F61C, // 😜
  [XDP]     = 0x1F61D, // 😝
  [ZANY]    = 0x1F92A, // 🤪
  [LOL]     = 0x1F602, // 😂
  [SWEAT]   = 0x1F605, // 😅

  [SMILE]   = 0x1F642, // 🙂
  [WINK]    = 0x1F609, // 😉
  [GRIN]    = 0x1F600, // 😀
  [GRIN2]   = 0x1F603, // 😃
  [GRIN3]   = 0x1F604, // 😄
  [BEAM]    = 0x1F601, // 😁
  [KEKE]    = 0x1F60A, // 😊

  [NERD]    = 0x1F913, // 🤓
  [COOL]    = 0x1F60E, // 😎
  [HUG]     = 0x1F917, // 🤗
  [WHAT]    = 0x1F62E, // 😮
  [SMULE]   = 0x1F643, // 🙃

  [THINK]   = 0x1F914, // 🤔
  [BROW]    = 0x1F928, // 🤨
  [BLAH]    = 0x1F610, // 😐
  [FLAT]    = 0x1F611, // 😑
  [BLANK]   = 0x1F636, // 😶
  [SLEEP]   = 0x1F634, // 😴

  [EESH]    = 0x1F62C, // 😬
  [URGH]    = 0x1F616, // 😖
  [PLEA]    = 0x1F97A, // 🥺
  [SURP]    = 0x1F633, // 😳

  [MAD1]    = 0x1F624, // 😤
  [MAD2]    = 0x1F620, // 😠
  [FURY]    = 0x1F621, // 😡
  [SWEAR]   = 0x1F92C, // 🤬
  [DITZY]   = 0x1F635, // 😵
  [DRUNK]   = 0x1F974, // 🥴

  [CRY1]    = 0x1F622, // 😢
  [CRY2]    = 0x1F62D, // 😭
  [NAUS]    = 0x1F922, // 🤢
  [PUKE]    = 0x1F92E, // 🤮
  [HOT]     = 0x1F975, // 🥵
  [COLD]    = 0x1F976, // 🥶

  [U1]      = 0x2776, // ❶
  [U2]      = 0x2777,
  [U3]      = 0x2778,
  [U4]      = 0x2779,
  [U5]      = 0x277A,
  [U6]      = 0x277B,
  [U7]      = 0x277C,
  [U8]      = 0x277D,
  [U9]      = 0x277E,
  [U10]      = 0x277F,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Steno to plover over serial
[STENO] = LAYOUT_ergodox(
       TO(BASE), STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  _______,  
       OSL(WNAV),STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, _______,  
       OSL(MNAV),STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,
       OSL(BASE),KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
       _______,  _______, _______, _______, KC_SPC,
                                      OSM(NUMS), OSM(NUMSALT),
                                                 OSM(NUMSCTL),
                                   STN_A,   STN_O,   TO(BASE),

       _______,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
       TO(BASE), STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
                 STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   OSL(SYMB),
                          OSL(BASE), _______, KC_NO,   KC_NO,   KC_NO,  
       OSL(NUMSALT), OSL(NUMS),
       OSL(NUMSCTL),
       _______,  STN_E,    STN_U
),

/* Base layer, normal-ish QWERTY except for outlying things like \:'"
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BASE   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | STEN   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | WNAV   |   Q  |   W  |   E  |   R  |   T  | STEN |           | STEN |   Y  |   U  |   I  |   O  |   P  | MNAV   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | MNAV   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   :  | BSLS   |
 * |--------+------+------+------+------+------| Alt  |           | Alt  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | SYMB   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | NUMS |CtlShf|CtlAlt| Ctrl | Space|                                       |Space | Ctrl |   '  |   "  | NUMS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.     ,---------------.
 *                                        |       | TMUX |     | TMUX |        |
 *                                 ,------|-------|------|     |------+--------+------.
 *                                 |      |       |^LGui |     |^RGui |        |      |
 *                                 |BSpace| Tab   |------|     |------| Esc    |Enter |
 *                                 |      |       | LGui |     | RGui |        |      |
 *                                 `---------------------'     `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        TO(BASE),     KC_1,         KC_2,             KC_3,           KC_4,   KC_5,   KC_NO,
        OSL(WNAV),    KC_Q,         KC_W,             KC_E,           KC_R,   KC_T,   TO(STENO),
        OSL(MNAV),    KC_A,         KC_S,             KC_D,           KC_F,   KC_G,
        KC_LSFT,      KC_Z,         KC_X,             KC_C,           KC_V,   KC_B,   OSM(MOD_LALT),
        TG(NUMS),     OSM(MOD_LCTL|MOD_LSFT),OSM(MOD_LCTL|MOD_LALT),OSM(MOD_LCTL), KC_SPC,
                                    OSL(TMUX), OSL(TMUX),
                                               OSM(MOD_LSFT|MOD_LGUI),
                                    KC_BSPC, KC_TAB, OSM(MOD_LGUI),
        // right hand
        KC_NO,      KC_6,   KC_7,         KC_8,         KC_9,        KC_0,        TO(STENO),
        TO(STENO),  KC_Y,   KC_U,         KC_I,         KC_O,        KC_P,        OSL(MNAV),
                    KC_H,   KC_J,         KC_K,         KC_L,        LSFT(KC_SCLN), KC_BSLS,
        OSM(MOD_RALT),KC_N, KC_M,         KC_COMM,      KC_DOT,      KC_SLSH,     OSL(SYMB),
                            KC_SPC, OSM(MOD_RCTL),     KC_QUOT,     KC_DQUO,     OSL(NUMS),
            OSL(TMUX), OSL(TMUX),
            OSM(MOD_LSFT|MOD_LGUI),
            OSM(MOD_LGUI), KC_ESC, KC_ENT
    ),

/* MNAV: Movement/nav keys, hold caps
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | CSL  | CSD  | CSU  | CSR  | VRSN | EEPROM |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |CtlBsp|Del   |PgUp  |Ins   |SftIns|      |           |      | CLeft| CDown| CUp  | CRght|      | \      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |CtSfHo|Home  |PgDown|End   |CtSfEn|------|           |------| Left | Down | Up   | Rght |      | \      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | WinN | WinM | Win, | Win. | Win/ |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Prev | Next |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.     ,---------------.
 *                                        |       |      |     |      |        |
 *                                 ,------|-------|------|     |------+--------+------.
 *                                 |      |       |      |     |      |        |      |
 *                                 | Del  |       |------|     |------| MUTE   | Play |
 *                                 |      |       |      |     |      |        |      |
 *                                 `---------------------'     `----------------------'
 */
[MNAV] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       LCTL(KC_TAB), LCTL(KC_BSPC), KC_DEL, KC_PGUP, KC_INS, LSFT(KC_INS), _______,
       KC_ESC,  LCTL(LSFT(KC_HOME)), KC_HOME, KC_PGDN, KC_END, LCTL(LSFT(KC_END)),
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______, _______, KC_DEL, _______, _______,

       _______, LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_DOWN)), LCTL(LSFT(KC_UP)), LCTL(LSFT(KC_RGHT)), VRSN, RESET,
       _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), _______, KC_BSLS,
                KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_BSLS,
       _______, LGUI(KC_N), LGUI(KC_M), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH), _______,
                         KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, _______,
       _______, _______, _______, _______, KC_MUTE, KC_MPLY
),

/* WNAV: Window movement/os nav keys, hold tab
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Alt-Tab|Alt+F4|Ctrl+W| WU   | WinR | WinT |      |           |      | WinY | WinU | WinI | WinO | WinP |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | WinA | WL   | WD   | WR   | WinG |------|           |------| ML   | MD   | MU   | MR   | Win1 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | WinZ | WinX | WinC | WinV | WinB |      |           |      | WinN | WinM | Win, | Win. | Win/ |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LGUI | APP  |                                       | MClk |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.     ,---------------.
 *                                        |Ctl+Spc|      |     |      |        |
 *                                 ,------|-------|------|     |------+--------+------.
 *                                 |      |       |      |     |      |        |      |
 *                                 |Ctl+BS|Alt+Spc|------|     |------| LClick | RClk |
 *                                 |      |       |      |     |      |        |      |
 *                                 `---------------------'     `----------------------'
 */
[WNAV] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       LALT(KC_TAB), LALT(KC_F4), LCTL(KC_W), KC_WH_U, LGUI(KC_R), LGUI(KC_T), _______,
       LGUI(KC_0), LGUI(KC_A),    KC_WH_L, KC_WH_D, KC_WH_R,    LGUI(KC_G),
       _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B), _______,
       _______, _______, _______, KC_LGUI, KC_APP,
                         LCTL(KC_SPC), _______, _______, LCTL(KC_BSPC), LALT(KC_SPC), _______, 

       _______, _______, _______, _______, _______, _______, _______,
       _______, LGUI(KC_Y), KC_ACL0, KC_ACL1, KC_ACL2, LGUI(KC_P), _______,
                KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    LGUI(KC_1),    _______,
       _______, LGUI(KC_N), LGUI(KC_M), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH), _______,
                         KC_BTN3, KC_BTN4, _______, _______, _______,
       _______, _______, _______, _______, KC_BTN1, KC_BTN2 
),


/* Symbol layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | UNI3   |   !  |   @  |   {  |   }  |   ~  |      |           |      |  +   |  _   |  -   |  #   |  %   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | UNI2   |   '  |   "  |   (  |   )  |   `  |------|           |------|  ^   |  '   |  "   |  $   |  ;   | ;      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | UNI1   |   =  |   *  |   [  |   ]  |      |      |           |      |  |   |  \   |  <   |  >   |  &   | \      |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),  _______,
       TG(UNI3),KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_TILD,_______,
       TG(UNI2),KC_QUOT,KC_DQUO,KC_LPRN,KC_RPRN,KC_GRV,
       TG(UNI1),KC_EQL, KC_ASTR,KC_LBRC,KC_RBRC,KC_NO,  _______,
       _______, X(NE),  _______,_______,_______,
                _______,_______,_______,X(DELTA), X(BULL), X(BOWTIE),

       _______, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8),LSFT(KC_9),   LSFT(KC_0), _______,
       _______, KC_PLUS, LSFT(KC_MINS), KC_MINS,   KC_HASH,      KC_PERC,  _______,
                KC_CIRC, X(EN),         X(EM),     KC_DLR,       KC_SCLN,  KC_SCLN,
       _______, KC_PIPE, KC_BSLS,       X(LTE),    X(GTE), KC_AMPR,  KC_BSLS,
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, X(SEC), X(PAR)
),

// UNICODE 1 (smilies/hands/body parts)
// https://emojipedia.org/people/
[UNI1] = LAYOUT_ergodox(
       _______, X(XD),   X(WINK2),X(XDP),  X(ZANY), X(LOL),  X(SWEAT),
       TO(UNI3),X(SMILE),X(WINK), X(GRIN), X(GRIN3),X(BEAM), X(KEKE),
       TO(UNI2),X(NERD), X(COOL), X(HUG),  X(WHAT), X(SMULE),
       TO(BASE),X(THINK),X(BROW), X(BLAH), X(FLAT), X(BLANK),X(SLEEP),
       KC_NO,   X(EESH), X(URGH), X(PLEA), X(SURP),
                X(MAD1), X(MAD2), X(FURY), X(DRUNK),X(DITZY),X(SWEAR),

       _______, X(H1),   X(H2),   X(H3),   X(H4),   X(H5),   _______,
       _______, X(EAR),  X(FOOT), X(LEG),  X(NOSE), X(PINCH),X(DET),
                X(FSLF), X(THDN), X(THUP), X(FSRT), X(FIST), X(FSUP),
       _______, X(NAIL), X(METAL),X(FLEX), X(PRAY), X(WRITE),TO(BASE),
                         _______, _______, _______, _______, _______,
       X(CRY1), X(CRY2), X(NAUS), X(PUKE), TO(BASE),  X(COLD)
),

// UNICODE 2 (nouns)
// https://emojipedia.org/objects/
[UNI2] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       TO(UNI3),_______, _______, _______, _______, X(TACO), _______,
       TO(BASE),_______, X(SKULL),_______, _______, _______,
       TO(UNI1),_______, _______, _______, _______, _______, _______,
       KC_NO,   _______, _______, _______, _______,
                _______, _______, _______, X(TREX), X(TURT), _______,

       _______, _______, _______, _______, _______, _______, _______,
       _______, X(YAM),  _______, _______, _______, X(PIZZA),X(POOP),
                X(HOLE), _______, _______, X(HEART),_______, _______,
       _______, _______, _______, _______, _______, _______, TO(BASE),
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, TO(BASE), _______
),

// UNICODE 3 (verbs left, useful symbols right)
[UNI3] = LAYOUT_ergodox(
       _______, X(U1),   X(U2),   X(U3),   X(U4),   X(U5), _______,
       TO(BASE),X(WARN), X(DONT), X(NO),   X(BIO),  X(HEART),_______,
       TO(UNI2),X(SPRK), X(SAX),  X(TUNE), X(FIRE), X(TOOT),
       TO(UNI1),X(ZAP),  X(ANGER),X(CHAT), X(SHOUT),X(DIZZY),_______,
       KC_NO,   _______, _______, _______, _______,
                _______, _______, _______, X(TREX), X(TURT), _______,

       _______, X(U6),   X(U7),   X(U8),   X(U9),   X(U10), _______,
       _______, _______, _______, _______, _______, _______, _______,
                X(LEFT), X(DOWN), X(UP),   X(RIGHT),X(UPDN), _______,
       _______, _______, _______, _______, _______, _______, TO(BASE),
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, TO(BASE), _______
),


/* NUMS*: Numbers layers for easy numbers and function keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BASE   | F1   | F2   | F3   | F4   | F5   |      |           |      | F6   | F7   | F8   | F9   | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F1   | F2   | F3   | F4   | F5   |      |           |      | F6   | F7   | F8   | F9   | F10  |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F11  | F12  | F13  | F14  | F15  |      |           |      | F16  | F17  | F18  | F19  | F20  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.     ,---------------.
 *                                        |       |      |     |      |        |
 *                                 ,------|-------|------|     |------+--------+------.
 *                                 |      |       |      |     |      |        |      |
 *                                 |      |       |------|     |------|        |      |
 *                                 |      |       |      |     |      |        |      |
 *                                 `---------------------'     `----------------------'
 */
[NUMS] = LAYOUT_ergodox(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
       _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
       _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,

       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
       _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, TO(BASE), _______
),
/* Numbers nav layer for ALT */
[NUMSALT] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       LALT(KC_0), LALT(KC_1),    LALT(KC_2),    LALT(KC_3),    LALT(KC_4),    LALT(KC_5),
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,

       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                LALT(KC_6),    LALT(KC_7),    LALT(KC_8),    LALT(KC_9),    LALT(KC_0),    _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, TO(BASE), _______
),
/* Numbers nav layer for CTL */
[NUMSCTL] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       LCTL(KC_0), LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),    LCTL(KC_4),    LCTL(KC_5),
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,

       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                LCTL(KC_6),    LCTL(KC_7),    LCTL(KC_8),    LCTL(KC_9),    LCTL(KC_0),    _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______, _______, _______, TO(BASE), _______
),

// TMUX layout
[TMUX] = LAYOUT_ergodox(
       _______, TMUX1,   TMUX2,   TMUX3,   TMUX4,   TMUX5, _______,
       TMUXB,   TMUXB,   TMUXB,   TMUXB,   TMUXB,   TMUXB, _______,
       TMUX0,   TMUX1,   TMUX2,   TMUX3,   TMUX4,   TMUX5,
       _______, TMUXZ,   _______, TMUXC,   _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______, _______, _______, 

       _______, TMUX6, TMUX7, TMUX8, TMUX9, TMUX0, _______,
       _______, _______, _______, _______, _______, _______, _______,
                TMUXH,   TMUXJ,   TMUXK,   TMUXL,   TMUXCMD,   _______,
       LCTL(KC_BSLS), _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______, _______, TMUXB, TO(BASE), _______ 
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case TMUX0:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_0));
        break;
      case TMUX1:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_1));
        break;
      case TMUX2:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_2));
        break;
      case TMUX3:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_3));
        break;
      case TMUX4:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_4));
        break;
      case TMUX5:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_5));
        break;
      case TMUX6:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_6));
        break;
      case TMUX7:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_7));
        break;
      case TMUX8:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_8));
        break;
      case TMUX9:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_9));
        break;
      case TMUXH:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_P));
        break;
      case TMUXJ:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_N));
        break;
      case TMUXK:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_P));
        break;
      case TMUXL:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_N));
        break;
      case TMUXB:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_B));
        break;
      case TMUXC:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_C));
        break;
      case TMUXZ:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_Z));
        break;
      case TMUXQ:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_Q));
        break;
      case TMUXW:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_W));
        break;
      case TMUXE:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_E));
        break;
      case TMUXR:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_R));
        break;
      case TMUXT:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(SS_TAP(X_T));
        break;
      case TMUXCMD:
        SEND_STRING(SS_LCTRL("b"));
        SEND_STRING(":");
        break;
    }
  }
  return true;
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case STENO:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          ergodox_right_led_3_on();
          break;
      case NUMS:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          break;
      case NUMSALT:
      case NUMSCTL:
          ergodox_right_led_1_on();
          ergodox_right_led_3_on();
          break;
      case SYMB:
      case UNI1:
          ergodox_right_led_1_on();
          break;
      case MNAV:
      case WNAV:
      case TMUX:
      case UNI2:
          ergodox_right_led_2_on();
          break;
      case UNI3:
          ergodox_right_led_3_on();
          break;
      default:
        break;
    }

  return state;
};
