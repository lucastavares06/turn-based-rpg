#ifndef TERMINAL_H
#define TERMINAL_H

#ifdef __cplusplus
extern "C" {
#endif

    void clear_screen(void);

    void flush_stdin(void);

    void wait_any_key(void);

#ifdef __cplusplus
}
#endif

#endif
