#include QMK_KEYBOARD_H
#include "sendstring_uk.h"
#include "keymap_uk.h"

enum custom_keycodes 
{
    KC_DBL0 = SAFE_RANGE,
    KC_YELLOW,
    KC_GREEN,
    KC_GMAIL,
    KC_HMAIL,
    KC_UNI,
    KC_PHN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case KC_DBL0:
            if (record->event.pressed)
            {
                // when keycode KC_DBL0 is pressed
		        tap_code(KC_P0);
		        tap_code(KC_P0);
            }
            else
            {
                // when keycode KC_DBL0 is released
            }
            break;

        case KC_YELLOW:
            if (record->event.pressed)
            {
                //when yellow key is pressed
                rgb_matrix_enable_noeeprom();
                rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            }
            else
            {
                //when yellow key is not pressed
            }
            break;

        case KC_GREEN:
            if (record->event.pressed)
            {
                //when green key is pressed
                rgb_matrix_enable_noeeprom();
                rgb_matrix_sethsv_noeeprom(HSV_GREEN);
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            }
            else
            {
                //when green key is not poressed
            }
            break;

        case KC_GMAIL:
            if (record->event.pressed)
            {
                // when keycode KC_GMAIL is pressed
                SEND_STRING("");
            }
            else
            {
                // when keycode KC_GMAIL is released
            }
            break;

        case KC_HMAIL:
            if (record->event.pressed)
            {
                // when keycode KC_HMAIL is pressed
                SEND_STRING("");
            }
            else
            {
                // when keycode KC_HMAIL is released
            }
            break;

        case KC_UNI:
            if (record->event.pressed)
            {
                // when keycode KC_UNI is pressed
                SEND_STRING("");
            }
            else
            {
                // when keycode KC_UNI is released
            }
            break;
        case KC_PHN:
	        if(record->event.pressed)
			{
		        // when keycode KC_PHN is pressed
		        SEND_STRING("");
	         }
            else
            {
                // when keycode KC_PHN is released
            }
            break;
    }
    return true;
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) 
    {
        RGB prevColour = hsv_to_rgb(rgb_matrix_get_hsv());
        for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) 
        {
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW))
            {
                rgb_matrix_set_color(i, 255 - prevColour.r, 255 - prevColour.g, 255 - prevColour.b);
            }
        }
	    RGB_MATRIX_INDICATOR_SET_COLOR(3, 255 - prevColour.r, 255 - prevColour.g, 255 - prevColour.b);
    }
    
    if (host_keyboard_led_state().num_lock && layer_state_is(1))
    {
	    RGB prevColour = hsv_to_rgb(rgb_matrix_get_hsv());
    	RGB_MATRIX_INDICATOR_SET_COLOR(55, 255 - prevColour.r, 255 - prevColour.g, 255 - prevColour.b);
    }
    
    if (layer_state_is(1))
    {
	    RGB prevColour = hsv_to_rgb(rgb_matrix_get_hsv());
	    RGB_MATRIX_INDICATOR_SET_COLOR(70,  255 - prevColour.r, 192 - prevColour.g, 128 - prevColour.b);
    }

    if (layer_state_is(2))
    {
        RGB prevColour = hsv_to_rgb(rgb_matrix_get_hsv());
        RGB_MATRIX_INDICATOR_SET_COLOR(19,  255 - prevColour.r, 192 - prevColour.g, 128 - prevColour.b);
    } 

    if (layer_state_is(3))
    {
        RGB prevColour = hsv_to_rgb(rgb_matrix_get_hsv());
        RGB_MATRIX_INDICATOR_SET_COLOR(24,  255 - prevColour.r, 192 - prevColour.g, 128 - prevColour.b);
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, TG(1), KC_MPLY,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
    [1] = LAYOUT(
        KC_ESC, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_TRNS, KC_MPLY, 
        KC_GRV, TG(0), KC_TRNS, TG(2), TG(3), KC_5, KC_6, KC_7, KC_8, KC_PSLS, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_P7, KC_P8, KC_P9, KC_PAST, KC_P, KC_LBRC, KC_RBRC, KC_DEL,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_DBL0, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PPLS, KC_QUOT, KC_NUHS, KC_ENT, KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_P0, KC_P1, KC_P2, KC_3, KC_PDOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_NLCK, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
    [2] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_GMAIL, KC_HMAIL, KC_UNI, KC_PHN, KC_TRNS, KC_MUTE, 
        KC_GRV, TG(0), TG(1), KC_TRNS, TG(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_INS,
        KC_TAB, BL_TOGG, BL_ON, KC_TRNS, KC_TRNS, KC_INS, KC_PGUP, KC_PGDN, KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_PGUP,
        KC_CAPS, RGB_TOG, KC_YELLOW, KC_GREEN, KC_TRNS, KC_MYCM, KC_MAIL, KC_CALC, KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, RESET, KC_ENT, KC_PGDN,
        KC_LSFT, KC_TRNS, KC_MPRV, KC_MNXT, KC_MSEL, KC_TRNS, KC_BRIU, KC_BRID, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_RSFT, RGB_MOD, KC_SLEP, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPI, RGB_RMOD, RGB_SPD),
    [3] = LAYOUT(
        KC_ESC, TG(0), TG(1), TG(2), KC_4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_MPLY,
        KC_GRV, KC_1, KC_2, KC_3, KC_TRNS, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) 
{
      if (index == 0) 
      {
        switch(get_highest_layer(layer_state))
        {
            case 0:
                if (clockwise)
                {
                    tap_code16(KC_VOLU);
                }
                else
                {
                    tap_code16(KC_VOLD);
                }
                break;
            case 1:
                if (clockwise)
                {
                    tap_code16(KC_BRIU);
                } 
                else
                {
                    tap_code16(KC_BRID);
                }
                break;
            case 2:
                if (clockwise)
                {
                   rgb_matrix_increase_hue();
                }
                else
                {
                   rgb_matrix_decrease_hue();
                }
                break;
            case 3:
                if (clockwise) 
                {
                    tap_code16(KC_VOLU);
                } 
                else 
                {
                    tap_code16(KC_VOLD);
                }
                break;
        }
            
    }
    return true;
}
#endif
