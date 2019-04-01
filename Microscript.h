
void init_binaryclock(void);
void var_set(const char *variable, uint16_t currentNumber);
void time_set(const char *variable, uint16_t currentTime[]);
void parse_binaryclock(const char* p, uint16_t len, uint8_t is_eof);
void var_display(const char *variable);

enum {
  TYPE_NUMBER,
  TYPE_TIME
} binaryclock_types;
