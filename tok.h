/* neatcc tokenizer interface */
#define TOK2(a)		((a)[0] << 16 | (a)[1] << 8)
#define TOK3(a)		((a)[0] << 16 | (a)[1] << 8 | (a)[2])

enum tok {
	TOK_EOF,
	TOK_NAME = 256,
	TOK_NUM,
	TOK_VOID,
	TOK_STATIC,
	TOK_EXTERN,
	TOK_RETURN,
	TOK_UNSIGNED,
	TOK_SIGNED,
	TOK_SHORT,
	TOK_LONG,
	TOK_INT,
	TOK_CHAR,
	TOK_STRUCT,
	TOK_UNION,
	TOK_ENUM,
	TOK_TYPEDEF,
	TOK_IF,
	TOK_ELSE,
	TOK_FOR,
	TOK_WHILE,
	TOK_DO,
	TOK_SWITCH,
	TOK_CASE,
	TOK_SIZEOF,
	TOK_STR,
	TOK_BREAK,
	TOK_CONTINUE,
	TOK_DEFAULT,
	TOK_GOTO,
};

void tok_init(char *path);
int tok_see(void);
int tok_get(void);
char *tok_id(void);
int tok_num(long *n);
void tok_str(char **buf, int *len);
long tok_addr(void);
void tok_jump(long addr);

int cpp_init(char *path);
void cpp_addpath(char *s);
void cpp_define(char *name, char *def);
char *cpp_loc(long addr);
int cpp_read(char **buf, int *len);

void die(char *msg, ...);
void err(char *fmt, ...);
