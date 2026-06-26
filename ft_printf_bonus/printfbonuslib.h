

typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int hash;
    int plus;
    int space;
    int width;
    int precision;
    char type;
} t_flags;

// PARSER
parse/
├── parse_flags.c
├── parse_width.c
├── parse_precision.c
├── parse_type.c
└── parse_format.c

void parse_flags(...);
void parse_width(...);
void parse_precision(...);
void parse_type(...);

// CONVERTER
convert/
├── print_char.c
├── print_str.c
├── print_ptr.c
├── print_int.c
├── print_uint.c
├── print_hex.c
└── print_percent.c

int print_char(char c, t_flags *f);
int print_str(char *s, t_flags *f);
int print_ptr(void *p, t_flags *f);
int print_int(int n, t_flags *f);
int print_uint(unsigned int n, t_flags *f);
int print_hex(unsigned int n, t_flags *f);
int print_percent(t_flags *f);