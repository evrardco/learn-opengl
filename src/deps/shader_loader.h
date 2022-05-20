#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char * load_shader(const char * filename);
void free_shader(const char * shader);
