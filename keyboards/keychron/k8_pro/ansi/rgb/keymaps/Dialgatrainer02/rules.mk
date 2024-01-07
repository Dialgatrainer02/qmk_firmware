VIA_ENABLE = yes

AUTO_SHIFT_ENABLE = yes
AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
REPEAT_KEY_ENABLE = yes


SRC += features/sentence_case.c

SRC += features/mouse_turbo_click.c \
        features/sentence_case.c
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

OPT_DEFS += -DDYNAMIC_KEYMAP_LAYER_COUNT=6

LTO_ENABLE = yes
