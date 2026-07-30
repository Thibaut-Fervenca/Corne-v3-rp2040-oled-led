/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    UG_ONLY = SAFE_RANGE,   // toggle: underglow-only <-> all LEDs
    RGB_RCT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_PGUP, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,  KC_END,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, UG_ONLY, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, RM_TOGG, RM_NEXT, RGB_RCT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

/* ==========================================================================
 *  OLED: animated UI
 *    boot   -> starfall, then a procedural octopus logo
 *    normal -> title / last key (scaled pop-in + star burst) / current layer
 *  Runs identically on both halves; the last key + layer are synced from the
 *  master to the slave over a split RPC transaction.
 * ========================================================================== */
#ifdef OLED_ENABLE

#include <string.h>
#include <math.h>
#include "transactions.h"   // split RPC: transaction_register_rpc / transaction_rpc_send
#include "oledfont_5x7.h"
#include "octo_bmp.h"

// Rotated logical canvas (OLED_ROTATION_270): 32 wide x 128 tall, y grows down.
#define DW 32
#define DH 128

// ------------------------------ shared state ------------------------------
// One "last key" per physical half. The master fills both (deciding the side
// from the matrix row) and syncs them to the slave; each OLED then shows only
// the key belonging to its own side.
typedef struct { char label[6]; uint8_t len; uint16_t seq; } keyside_t;
static keyside_t g_left  = {"", 0, 0};
static keyside_t g_right = {"", 0, 0};
static uint32_t  g_boot_time = 0;    // timer at power-on (start of boot anim)

#define BOOT_MS 1600     // total boot animation length

// ------------------------------- tiny PRNG --------------------------------
static uint16_t g_rng = 0xB33F;
static uint16_t prng(void) {
    g_rng ^= g_rng << 7;
    g_rng ^= g_rng >> 9;
    g_rng ^= g_rng << 8;
    return g_rng;
}
static int rr(int lo, int hi) { return lo + (int)(prng() % (uint16_t)(hi - lo + 1)); }

// ------------------------------ pixel helpers -----------------------------
static inline void px(int x, int y, bool on) {
    if (x < 0 || x >= DW || y < 0 || y >= DH) return;
    oled_write_pixel((uint8_t)x, (uint8_t)y, on);
}
static void hline(int x0, int x1, int y) {
    for (int x = x0; x <= x1; x++) px(x, y, true);
}

// --------------------------- scaled glyph text ----------------------------
static bool glyph_bit(char ch, int col, int row) {
    if (ch < 0x20 || ch > 0x7E) return false;
    uint8_t b = pgm_read_byte(&oled_kfont[(uint8_t)ch * 6 + col]);
    return (b >> row) & 1;
}
// Draw a char centered at (cx,cy), scaled by s100 percent (100 = native 5x7).
static void draw_char(int cx, int cy, char ch, int s100) {
    int sw = (5 * s100) / 100; if (sw < 1) sw = 1;
    int sh = (7 * s100) / 100; if (sh < 1) sh = 1;
    int x0 = cx - sw / 2, y0 = cy - sh / 2;
    for (int dy = 0; dy < sh; dy++) {
        int srow = dy * 7 / sh; if (srow > 6) srow = 6;
        for (int dx = 0; dx < sw; dx++) {
            int scol = dx * 5 / sw; if (scol > 4) scol = 4;
            if (glyph_bit(ch, scol, srow)) px(x0 + dx, y0 + dy, true);
        }
    }
}
// Draw a string centered on (cx,cy) at scale s100.
static void draw_string(int cx, int cy, const char *s, int s100) {
    int sw  = (5 * s100) / 100; if (sw < 1) sw = 1;
    int gap = s100 / 100;       if (gap < 1) gap = 1;
    int n   = (int)strlen(s);
    if (n == 0) return;
    int total = n * sw + (n - 1) * gap;
    int x = cx - total / 2 + sw / 2;
    for (int i = 0; i < n; i++) {
        draw_char(x, cy, s[i], s100);
        x += sw + gap;
    }
}

// ------------------------------ star engine -------------------------------
#define NSTARS 22
typedef struct { int16_t x8, y8, vx8, vy8; uint8_t life; uint8_t big; } star_t;
static star_t g_star[NSTARS];

static int star_dead(void) {
    for (int i = 0; i < NSTARS; i++) if (!g_star[i].life) return i;
    return -1;
}
static void spawn_fall(void) {                 // a star drifting down from the top
    int i = star_dead(); if (i < 0) return;
    g_star[i].x8  = (int16_t)(rr(0, DW - 1) << 3);
    g_star[i].y8  = 0;
    g_star[i].vx8 = (int16_t)rr(-4, 4);
    g_star[i].vy8 = (int16_t)rr(6, 22);
    g_star[i].life = (uint8_t)rr(50, 110);
    g_star[i].big  = (prng() & 3) == 0;
}
static void spawn_burst(int cx, int cy, int n) { // stars radiating out from a point
    for (int k = 0; k < n; k++) {
        int i = star_dead(); if (i < 0) return;
        g_star[i].x8  = (int16_t)(cx << 3);
        g_star[i].y8  = (int16_t)(cy << 3);
        g_star[i].vx8 = (int16_t)rr(-34, 34);
        g_star[i].vy8 = (int16_t)rr(-34, 34);
        g_star[i].life = (uint8_t)rr(12, 26);
        g_star[i].big  = prng() & 1;
    }
}
static void stars_step_draw(void) {
    for (int i = 0; i < NSTARS; i++) {
        if (!g_star[i].life) continue;
        g_star[i].x8 += g_star[i].vx8;
        g_star[i].y8 += g_star[i].vy8;
        g_star[i].life--;
        int x = g_star[i].x8 >> 3, y = g_star[i].y8 >> 3;
        if (x < 0 || x >= DW || y < 0 || y >= DH) { g_star[i].life = 0; continue; }
        px(x, y, true);
        if (g_star[i].big && (g_star[i].life & 1)) {   // sparkle: little plus shape
            px(x - 1, y, true); px(x + 1, y, true);
            px(x, y - 1, true); px(x, y + 1, true);
        }
    }
}

// --------------------- octopus logo (scaled + rotated blit) ---------------------
// Draw the bitmap centered at (cx,cy), scaled by scale100 percent and rotated by
// angle_deg, using inverse-mapped nearest-neighbour sampling.
static void draw_octo_xform(int cx, int cy, int scale100, int angle_deg) {
    if (scale100 <= 0) return;
    float rad = (float)angle_deg * 0.0174533f;   // deg -> rad
    float cs = cosf(rad), sn = sinf(rad);
    float inv = 100.0f / (float)scale100;        // inverse scale
    int reach = (((OCTO_W > OCTO_H ? OCTO_W : OCTO_H) * scale100) / 100) / 2 + 3;
    for (int dy = -reach; dy <= reach; dy++) {
        for (int dx = -reach; dx <= reach; dx++) {
            int sx = (int)lroundf(( cs * dx + sn * dy) * inv + OCTO_W * 0.5f);
            int sy = (int)lroundf((-sn * dx + cs * dy) * inv + OCTO_H * 0.5f);
            if (sx >= 0 && sx < OCTO_W && sy >= 0 && sy < OCTO_H &&
                (octo_bmp[sy][sx >> 3] & (0x80 >> (sx & 7)))) {
                px(cx + dx, cy + dy, true);
            }
        }
    }
}

// ------------------------- last-key label mapping -------------------------
static void set_side_label(keyside_t *ks, const char *s) {
    uint8_t i = 0;
    for (; s[i] && i < 5; i++) ks->label[i] = s[i];
    ks->label[i] = '\0';
    ks->len      = i;
    ks->seq++;   // seq bump is what each OLED watches to trigger its pop-in
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == UG_ONLY) {           // toggle underglow-only vs all LEDs
        if (record->event.pressed) {
#ifdef RGB_MATRIX_ENABLE
            if (rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
            } else {
                rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                rgb_matrix_set_color_all(0, 0, 0);   // blank the per-key LEDs now
            }
#endif
        }
        return false;
    }
    if (keycode == RGB_RCT) {
        if (record->event.pressed) {
#ifdef RGB_MATRIX_ENABLE
            static const uint8_t reactive_modes[] = {
                RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE,
                RGB_MATRIX_SOLID_REACTIVE_MULTICROSS,
                RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS,
                RGB_MATRIX_SPLASH,
                RGB_MATRIX_SOLID_SPLASH,
            };
            static uint8_t reactive_idx = 0;
            rgb_matrix_mode(reactive_modes[reactive_idx]);
            reactive_idx = (reactive_idx + 1) % (sizeof(reactive_modes) / sizeof(reactive_modes[0]));
#endif
        }
        return false;
    }
    if (record->event.pressed) {
        char        buf[4];
        const char *s = NULL;
        bool        shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
        if (keycode >= KC_A && keycode <= KC_Z) {
            buf[0] = 'A' + (keycode - KC_A); buf[1] = '\0'; s = buf;
        } else if (keycode >= KC_1 && keycode <= KC_0) {
            int idx = keycode - KC_1;                 // KC_1..KC_0 are contiguous
            buf[0] = shift ? "!@#$%^&*()"[idx] : "1234567890"[idx];
            buf[1] = '\0'; s = buf;
        } else if (keycode >= KC_F1 && keycode <= KC_F12) {
            int n = keycode - KC_F1 + 1;
            buf[0] = 'F';
            if (n < 10) { buf[1] = '0' + n; buf[2] = '\0'; }
            else        { buf[1] = '1'; buf[2] = '0' + (n - 10); buf[3] = '\0'; }
            s = buf;
        } else {
            switch (keycode) {
                case KC_ENT:  s = "ENT"; break;
                case KC_ESC:  s = "ESC"; break;
                case KC_BSPC: s = "BSP"; break;
                case KC_TAB:  s = "TAB"; break;
                case KC_SPC:  s = "SPC"; break;
                case KC_DEL:  s = "DEL"; break;
                case KC_LEFT: s = "<";   break;
                case KC_RIGHT:s = ">";   break;
                case KC_UP:   s = "^";   break;
                case KC_DOWN: s = "v";   break;
                case KC_MINS: s = shift ? "_"  : "-";  break;
                case KC_EQL:  s = shift ? "+"  : "=";  break;
                case KC_LBRC: s = shift ? "{"  : "[";  break;
                case KC_RBRC: s = shift ? "}"  : "]";  break;
                case KC_BSLS: s = shift ? "|"  : "\\"; break;
                case KC_SCLN: s = shift ? ":"  : ";";  break;
                case KC_QUOT: s = shift ? "\"" : "'";  break;
                case KC_GRV:  s = shift ? "~"  : "`";  break;
                case KC_COMM: s = shift ? "<"  : ",";  break;
                case KC_DOT:  s = shift ? ">"  : ".";  break;
                case KC_SLSH: s = shift ? "?"  : "/";  break;
                case KC_EXLM: s = "!";   break;
                case KC_AT:   s = "@";   break;
                case KC_HASH: s = "#";   break;
                case KC_DLR:  s = "$";   break;
                case KC_PERC: s = "%";   break;
                case KC_CIRC: s = "^";   break;
                case KC_AMPR: s = "&";   break;
                case KC_ASTR: s = "*";   break;
                case KC_LPRN: s = "(";   break;
                case KC_RPRN: s = ")";   break;
                case KC_UNDS: s = "_";   break;
                case KC_PLUS: s = "+";   break;
                case KC_LCBR: s = "{";   break;
                case KC_RCBR: s = "}";   break;
                case KC_PIPE: s = "|";   break;
                case KC_TILD: s = "~";   break;
                case KC_LSFT: case KC_RSFT: s = "SFT"; break;
                case KC_LCTL: case KC_RCTL: s = "CTL"; break;
                case KC_LALT: case KC_RALT: s = "ALT"; break;
                case KC_LGUI: case KC_RGUI: s = "GUI"; break;
                case QK_BOOT:               s = "BOOT"; break;
                default: break;
            }
            // Momentary layer switches -> "L1", "L2", ...
            if (s == NULL && keycode >= QK_MOMENTARY && keycode <= QK_MOMENTARY_MAX) {
                buf[0] = 'L'; buf[1] = '0' + (char)(keycode & 0x0F); buf[2] = '\0'; s = buf;
            }
        }
        if (s != NULL) {
            // Rows 0..3 = left half, rows 4..7 = right half.
            keyside_t *ks = (record->event.key.row < (MATRIX_ROWS / 2)) ? &g_left : &g_right;
            set_side_label(ks, s);
        }
    }
    return true;
}

// ---------------------------- master -> slave sync ------------------------
typedef struct __attribute__((packed)) {
    uint16_t lseq; uint8_t llen; char llabel[5];
    uint16_t rseq; uint8_t rlen; char rlabel[5];
} keysync_t;

static void apply_side(keyside_t *ks, uint16_t seq, uint8_t len, const char *label) {
    ks->seq = seq;
    ks->len = len > 5 ? 5 : len;
    for (uint8_t i = 0; i < ks->len; i++) ks->label[i] = label[i];
    ks->label[ks->len] = '\0';
}

static void keysync_slave_handler(uint8_t in_len, const void *in_data, uint8_t out_len, void *out_data) {
    (void)in_len; (void)out_len; (void)out_data;
    const keysync_t *m = (const keysync_t *)in_data;
    apply_side(&g_left,  m->lseq, m->llen, m->llabel);
    apply_side(&g_right, m->rseq, m->rlen, m->rlabel);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last = 0;
        if (timer_elapsed32(last) > 50) {
            keysync_t m;
            m.lseq = g_left.seq;  m.llen = g_left.len;
            m.rseq = g_right.seq; m.rlen = g_right.len;
            for (uint8_t i = 0; i < 5; i++) {
                m.llabel[i] = (i < g_left.len)  ? g_left.label[i]  : 0;
                m.rlabel[i] = (i < g_right.len) ? g_right.label[i] : 0;
            }
            transaction_rpc_send(USER_SYNC_KEY, sizeof(m), &m);
            last = timer_read32();
        }
    }
}

// ------------------------------- lifecycle --------------------------------
void keyboard_post_init_user(void) {
    g_rng      ^= (uint16_t)timer_read32() | 1u;
    g_boot_time = timer_read32();
    transaction_register_rpc(USER_SYNC_KEY, keysync_slave_handler);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    (void)rotation;
    // Both halves vertical + identical. If the right OLED reads upside-down,
    // change this to OLED_ROTATION_90 for the non-master side.
    return OLED_ROTATION_270;
}

// Pop-in scale (percent) following 0 -> 1.3 -> 0.8 -> 1.0 over ~300 ms.
static int popin_scale(uint32_t e) {
    if (e < 120) return (int)(130 * e / 120);
    if (e < 210) return 130 - (int)((50 * (e - 120)) / 90);
    if (e < 300) return 80  + (int)((20 * (e - 210)) / 90);
    return 100;
}

static const char *layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:  return "BASE";
        case 1:  return "NUMS";
        case 2:  return "SYMB";
        case 3:  return "FUNC";
        default: return "????";
    }
}

bool oled_task_user(void) {
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }

    oled_clear();
    uint32_t be = timer_elapsed32(g_boot_time);

    // ---- boot: octopus pops in (0->1.3->0.8->1.0 over 0.6s) with a small
    //      wobble, then holds at full size; "CORNE" shown throughout ----
    if (be < BOOT_MS) {
        int s, ang;
        if (be < 600) {
            s   = popin_scale(be / 2);                            // 0.6s pop-in
            ang = (int)lroundf(5.0f * sinf((float)be * 0.0314f)); // +/-5 deg wobble
        } else {
            s = 100; ang = 0;
        }
        draw_octo_xform(16, 46, s, ang);
        draw_string(16, 100, "CORNE", 100);
        return false;
    }

    // ---- normal UI ----
    led_t leds = host_keyboard_led_state();
    draw_string(DW / 2, 6, leds.caps_lock ? "CAPS" : "CRKBD", 100);
    hline(2, DW - 3, 13);

    if ((prng() & 15) == 0) spawn_fall();   // gentle ambient life
    stars_step_draw();

    // Show only the key that belongs to THIS half.
    keyside_t      *mine = is_keyboard_left() ? &g_left : &g_right;
    static uint16_t shown_seq = 0;
    static uint32_t key_time  = 0;
    static bool     have_key  = false;
    if (mine->seq != shown_seq) {           // a new key landed on this half
        shown_seq = mine->seq;
        have_key  = (mine->len > 0);
        key_time  = timer_read32();
        spawn_burst(DW / 2, DH / 2, 12);
    }
    if (have_key) {
        int base = (mine->len <= 1) ? 340 : (mine->len == 2) ? 230 : (mine->len == 3) ? 155 : 120;
        int disp = base * popin_scale(timer_elapsed32(key_time)) / 100;
        if (disp < 20) disp = 20;
        draw_string(DW / 2, DH / 2, mine->label, disp);
    }

    hline(2, DW - 3, 103);
    draw_string(DW / 2, 116, layer_name(), 150);
    return false;
}

#endif // OLED_ENABLE
