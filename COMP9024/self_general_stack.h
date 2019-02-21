#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define SELF_GENERAL_STACK

struct stack {
	int size;
	int cnt;
	int typeCode;
	void* data;
};

int configure_type(const char* typeName);
struct stack* initStack(const char* typeName);
void expand_stack_size(struct stack* current_stack);
void gpush_char(struct stack* current_stack, const char value);
void gpush_int(struct stack* current_stack, const int32_t value);
void gpush_double(struct stack* current_stack, const double value);
char gpeak_char(const struct stack* current_stack);
int32_t gpeak_int(const struct stack* current_stack);
double gpeak_double(const struct stack* current_stack);
int get_length(const struct stack* current_stack);
char gpop_char(struct stack* current_stack);
int32_t gpop_int(struct stack* current_stack);
double gpop_double(struct stack* current_stack);
char* gis_empty(const struct stack* current_stack);
void gprint_stack(const struct stack* current_stack);
void gdelete_stack(struct stack* current_stack);