#include "shader_loader.h"
char * load_shader(const char * file_path) {
    FILE * file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", file_path);
        return NULL;
    }
    int fd = fileno(file);
    if (fd == -1) {
        printf("Invalid stream.\n");
        fclose(file);
        return NULL;
    }
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        printf("Failed to get file stat.\n");
        fclose(file);
        return NULL;
    }
    size_t file_size = file_stat.st_size;
    char * file_content = (char *)(malloc(sizeof(char) * (file_size + 1)));
    if (file_content == NULL) {
        printf("Failed to allocate memory.\n");
        fclose(file);
        return NULL;
    }
    if (read(fd, file_content, file_size) != file_size) {
        printf("Failed to read file.\n");
        free(file_content);
        fclose(file);
        return NULL;
    }
    fclose(file);
    file_content[file_size] = '\0';
    return file_content;
}

void free_shader(const char * shader_content) {
    free((void *)shader_content);
}

