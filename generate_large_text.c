#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MB_TO_BYTES(mb) ((mb) * 1024 * 1024)
#define CHUNK_SIZE (1024 * 1024) // 1 MB chunks
#define BASE_TEXT_SIZE 10000     // 10 KB base text

void generate_large_file(const char *filename, long size_mb) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    // Initialize random seed
    srand(time(NULL));

    // Pre-generate a base text buffer
    char *base_text = malloc(BASE_TEXT_SIZE + 1);
    if (!base_text) {
        perror("Error allocating memory");
        fclose(fp);
        exit(1);
    }

    const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \n";
    for (int i = 0; i < BASE_TEXT_SIZE; i++) {
        base_text[i] = chars[rand() % 63]; // 62 chars + space + newline
    }
    base_text[BASE_TEXT_SIZE] = '\0';

    long target_size = MB_TO_BYTES(size_mb);
    long current_size = 0;

    printf("Generating %s...\n", filename);

    while (current_size < target_size) {
        // Write a chunk (up to 1 MB)
        long remaining = target_size - current_size;
        long write_size = remaining < CHUNK_SIZE ? remaining : CHUNK_SIZE;

        // Shuffle base_text for variety
        for (int i = 0; i < write_size && i < BASE_TEXT_SIZE; i++) {
            int j = rand() % BASE_TEXT_SIZE;
            char temp = base_text[i];
            base_text[i] = base_text[j];
            base_text[j] = temp;
        }

        size_t written = fwrite(base_text, 1, write_size < BASE_TEXT_SIZE ? write_size : BASE_TEXT_SIZE, fp);
        if (written == 0) {
            perror("Error writing to file");
            free(base_text);
            fclose(fp);
            exit(1);
        }

        current_size += written;

        // Progress feedback every ~10 MB
        if (current_size % (10 * 1024 * 1024) < CHUNK_SIZE) {
            printf("Progress: %.2f MB written\n", current_size / (1024.0 * 1024.0));
        }
    }

    free(base_text);
    fclose(fp);
    printf("Generated %s with size %.2f MB\n", filename, current_size / (1024.0 * 1024.0));
}

int main() {
    const char *filename = "large_test_file.txt";
    long size_mb = 100; // Target size: 100 MB

    generate_large_file(filename, size_mb);
    return 0;
}
