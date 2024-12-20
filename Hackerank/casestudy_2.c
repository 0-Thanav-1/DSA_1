#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct File {
    char* filename;
    struct File* next;
} File;

typedef struct Directory {
    char* directoryName;
    struct Directory* subdirectories;
    struct Directory* next;
    File* files;
    struct Directory* parent;
} Directory;

typedef struct FileSystem {
    Directory* rootDirectory;
} FileSystem;

File* create_file(const char* filename) {
    File* newFile = (File*)malloc(sizeof(File));
    if (!newFile) {
        perror("Failed to allocate memory for new file");
        exit(EXIT_FAILURE);
    }
    newFile->filename = strdup(filename);
    newFile->next = NULL;
    return newFile;
}

Directory* create_directory(const char* directoryName, Directory* parent) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    if (!newDir) {
        perror("Failed to allocate memory for new directory");
        exit(EXIT_FAILURE);
    }
    newDir->directoryName = strdup(directoryName);
    newDir->subdirectories = NULL;
    newDir->files = NULL;
    newDir->next = NULL;
    newDir->parent = parent;
    return newDir;
}

FileSystem* create_filesystem(const char* rootName) {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    if (!fs) {
        perror("Failed to allocate memory for file system");
        exit(EXIT_FAILURE);
    }
    fs->rootDirectory = create_directory(rootName, NULL);
    return fs;
}

int add_file(Directory* dir, const char* filename) {
    if (!dir) {
        printf("Directory is NULL\n");
        return 0;
    }

    File* current = dir->files;
    while (current) {
        if (strcmp(current->filename, filename) == 0) {
            return 0;
        }
        current = current->next;
    }

    File* newFile = create_file(filename);
    newFile->next = dir->files;
    dir->files = newFile;
    return 1;
}

Directory* add_subdirectory(Directory* dir, const char* directoryName) {
    if (!dir) {
        printf("Directory is NULL\n");
        return NULL;
    }

    Directory* current = dir->subdirectories;
    while (current) {
        if (strcmp(current->directoryName, directoryName) == 0) {
            return NULL;
        }
        current = current->next;
    }

    Directory* newDir = create_directory(directoryName, dir);
    newDir->next = dir->subdirectories;
    dir->subdirectories = newDir;
    return newDir;
}

Directory* getDirectSubdirectory(Directory* parent, const char* dirName) {
    Directory* subDir = parent->subdirectories;
    while (subDir) {
        if (strcmp(subDir->directoryName, dirName) == 0) {
            return subDir;
        }
        subDir = subDir->next;
    }
    return NULL;
}

void print_filesystem_recursive(Directory* dir, int level) {
    if (!dir) return;

    for (int i = 0; i < level; ++i) {
        printf("  ");
    }
    printf("[Dir] %s\n", dir->directoryName);

    File* currentFile = dir->files;
    while (currentFile) {
        for (int i = 0; i < level + 1; ++i) {
            printf("  ");
        }
        printf("- %s\n", currentFile->filename);
        currentFile = currentFile->next;
    }

    Directory* currentDir = dir->subdirectories;
    while (currentDir) {
        print_filesystem_recursive(currentDir, level + 1);
        currentDir = currentDir->next;
    }
}

void print_filesystem(FileSystem* fs) {
    if (!fs || !fs->rootDirectory) {
        printf("File system is empty.\n");
        return;
    }
    print_filesystem_recursive(fs->rootDirectory, 0);
}

void print_directory_contents(Directory* dir) {
    if (!dir) {
        printf("Directory is NULL.\n");
        return;
    }

    printf("Contents of directory '%s':\n", dir->directoryName);

    Directory* currentDir = dir->subdirectories;
    if (currentDir) {
        printf("  Subdirectories:\n");
        while (currentDir) {
            printf("    - %s (Directory)\n", currentDir->directoryName);
            currentDir = currentDir->next;
        }
    } else {
        printf("  No subdirectories.\n");
    }

    File* currentFile = dir->files;
    if (currentFile) {
        printf("  Files:\n");
        while (currentFile) {
            printf("    - %s (File)\n", currentFile->filename);
            currentFile = currentFile->next;
        }
    } else {
        printf("  No files.\n");
    }
}

void trim_newline(char* str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len == 0) return;
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    FileSystem* fs = create_filesystem("root");
    Directory* head = fs->rootDirectory;
    Directory* dir = NULL;

    char input[256];

    printf("Welcome to the In-Memory File System!\n");
    printf("Available commands:\n");
    printf("  cd <directory_name>\n");
    printf("  mkdir <directory_name>\n");
    printf("  touch <file_name>\n");
    printf("  ls\n");
    printf("  exit\n\n");

    while (1) {
        printf(">> ");

        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        trim_newline(input);

        if (strlen(input) == 0) {
            continue;
        }

        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");

        if (strcmp(command, "cd") == 0) {
            if (!argument) {
                printf("Error: 'cd' command requires a directory name.\n");
                continue;
            }

            if (strcmp(argument, "..") == 0) {
                if (head != fs->rootDirectory) {
                    head = head->parent;
                    printf("Switched to parent directory %s\n", head->directoryName);
                } else {
                    printf("You are already at the root directory.\n");
                }
                continue;
            }

            dir = getDirectSubdirectory(head, argument);
            if (dir) {
                printf("Switched to directory %s\n", argument);
                head = dir;
            } else {
                printf("No such subdirectory here.\n");
            }

        } else if (strcmp(command, "mkdir") == 0) {
            if (!argument) {
                printf("Error: 'mkdir' command requires a directory name.\n");
                continue;
            }

            dir = add_subdirectory(head, argument);
            if (dir) {
                printf("Created subdirectory %s\n", argument);
            } else {
                printf("Subdirectory with name %s already exists.\n", argument);
            }

        } else if (strcmp(command, "touch") == 0) {
            if (!argument) {
                printf("Error: 'touch' command requires a file name.\n");
                continue;
            }

            int x = add_file(head, argument);
            if (x) {
                printf("Created file %s\n", argument);
            } else {
                printf("File with name %s already exists.\n", argument);
            }

        } else if (strcmp(command, "ls") == 0) {
            print_directory_contents(head);

        } else if (strcmp(command, "print") == 0) {
            print_filesystem(fs);

        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the File System. Goodbye!\n");
            break;

        } else {
            printf("Error: Unknown command '%s'.\n", command);
        }
    }

    return 0;
}
