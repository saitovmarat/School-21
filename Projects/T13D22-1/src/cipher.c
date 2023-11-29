#include "logger.h"
#define MAX_PATH_LENGTH 2048
int printFileContents(const char* filename);
int writeToFile(const char* filename, char* text);
void CaesarShift(char* fileContent, int shift);
int processFiles(char* directory, int shift);

int main() {
    int choice = 0;
    char filename[100];
    char directoryPath[100];
    char text[100];
    int shift;
    char message[MAX_PATH_LENGTH];
    FILE* file = log_init("logs.txt");
    while (choice != -1) {
        if (scanf("%d", &choice) != 1) {
            printf("n/a\n");
            while (getchar() != '\n') {
            }
            continue;
        }
        if (choice == 1) {
            scanf(" %99[^\n]", filename);
            if (printFileContents(filename)) {
                sprintf(message, "Файл \"%s\" открыт и выведен", filename);
                logcat(file, message, info);
            } else {
                sprintf(message, "Файл \"%s\" не открыт", filename);
                logcat(file, message, warning);
            }
        } else if (choice == 2) {
            scanf(" %99[^\n]", text);
            if (writeToFile(filename, text)) {
                sprintf(message, "В файл \"%s\" записана строка \"%s\"", filename, text);
                logcat(file, message, trace);
            } else {
                sprintf(message, "В файл \"%s\" не записана строка \"%s\"", filename, text);
                logcat(file, message, error);
            }
            printFileContents(filename);
        } else if (choice == 3) {
            scanf(" %99[^\n]", directoryPath);
            scanf("%d", &shift);
            if (processFiles(directoryPath, shift)) {
                sprintf(message,
                        "Директория \"%s\" открыта, в ней все файлы .c изменены и все .h файлы очищены",
                        directoryPath);
                logcat(file, message, info);
            } else {
                sprintf(message, "Директория \"%s\" не открыта", directoryPath);
                logcat(file, message, error);
            }
        } else if (choice == -1)
            break;
        else
            printf("n/a\n");
    }
    log_close(file);
    return 0;
}
int printFileContents(const char* filename) {
    FILE* input = fopen(filename, "r");
    if (input) {
        char buffer[256];
        int isEmpty = 1;
        while ((fgets(buffer, 256, input)) != NULL) {
            isEmpty = 0;
            printf("%s", buffer);
        }
        fclose(input);
        if (isEmpty) {
            printf("n/a\n");
            return 0;
        } else {
            printf("\n");
        }
    } else {
        printf("n/a\n");
        return 0;
    }
    return 1;
}
int writeToFile(const char* filename, char* text) {
    FILE* input = fopen(filename, "r");
    if (!input) {
        return 0;
    }
    fclose(input);
    FILE* output = fopen(filename, "a");
    if (output) {
        fputs(text, output);
        fclose(output);
    } else {
        printf("n/a\n");
    }
    return 1;
}
void CaesarShift(char* fileContent, int shift) {
    for (int i = 0; fileContent[i] != '\0'; i++) {
        if (fileContent[i] >= 'A' && fileContent[i] <= 'Z') {
            fileContent[i] = ((fileContent[i] - 'A' + shift) % 26) + 'A';
        } else if (fileContent[i] >= 'a' && fileContent[i] <= 'z') {
            fileContent[i] = ((fileContent[i] - 'a' + shift) % 26) + 'a';
        }
    }
}
int processFiles(char* directory, int shift) {
    DIR* dir;
    struct dirent* ent;
    dir = opendir(directory);
    if (dir == NULL) {
        return 0;
    }
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, ent->d_name);
            FILE* file = fopen(filePath, "r+");
            if (strstr(ent->d_name, ".c") == NULL) {
                fclose(file);
                file = fopen(filePath, "w");
            }
            if (file == NULL) {
                printf("Ошибка открытия файла: %s\n", ent->d_name);
                continue;
            }
            fseek(file, 0, SEEK_END);
            long fileSize = ftell(file);
            rewind(file);

            char* fileContent = (char*)malloc(fileSize + 1);
            fread(fileContent, 1, fileSize, file);
            fileContent[fileSize] = '\0';

            CaesarShift(fileContent, shift);

            rewind(file);
            fwrite(fileContent, 1, fileSize, file);
            fclose(file);
            free(fileContent);
        }
    }
    closedir(dir);
    return 1;
}
