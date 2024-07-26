#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

// Function prototypes. Don't change these.
uint8_t *read_card(char *fname, int *size);
void save_jpeg(uint8_t *data, int size, char *filename);
void recover(uint8_t *data, int size);

#define RAW_FILE "card.raw"

int main()
{
    // Read the card.raw file into an array of bytes (uint8_t)
    int card_length;
    uint8_t *card_data = read_card(RAW_FILE, &card_length);
    
    // Recover the images
    recover(card_data, card_length);
}

uint8_t *read_card(char *filename, int *size)
{
    struct stat st;
    if (stat(filename, &st) == -1)
    {
        fprintf(stderr, "Can't get info about %s\n", filename);
        exit(1);
    }
    int len = st.st_size;
    uint8_t *raw = malloc(len * sizeof(uint8_t));
    
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        fprintf(stderr, "Can't open %s for reading\n", filename);
        exit(1);
    }
    
    fread(raw, 1, len, fp);
    fclose(fp);
    
    *size = len;
    return raw;
}

void save_jpeg(uint8_t *data, int size, char *filename)
{
    static int file_count = 0;

    file_count++;
    if (file_count >= 100)
    {
        fprintf(stderr, "Warning: Your program was terminated.\n");
        fprintf(stderr, "  To prevent a large number of files from being created,\n");
        fprintf(stderr, "  program execution was stopped after save_jpeg was called\n");
        fprintf(stderr, "  100 times. You likely have a bug in your program.\n");
        exit(1);
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        fprintf(stderr, "Can't write to %s\n", filename);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    fclose(fp);   
}



void recover(uint8_t *data, int size) {
    int jpeg_found = 0;
    uint8_t *jpeg_start = NULL;
    char filename[8];
    int file_index = 0;

    for (int i = 0; i < size - 512; i += 512) {
        //check for start of jpg
        if ((data[i] == 255 && data [i+1] == 216 && data [i+2] == 255 && data [i+3] == 224 || data[i+3] == 225)) {
            //if already found jpg, save previous
            if (jpeg_found) {
                //calc size of jpg
                int jpeg_size = jpeg_start - data - (file_index * 512) + i;
                sprintf(filename, "%03d.jpg", file_index++);
                save_jpeg(jpeg_start, jpeg_size, filename);
                jpeg_found = 0; // reset since starting to track new jpg
            }

            //update to mark the start of new jpg

            jpeg_start = data + i; // upstate start to current position
            jpeg_found = 1; // currently tracking
        }
        //save last jpg if found
        if (jpeg_found) {
            int jpeg_size = data + size - jpeg_start; //size of last jpg
            sprintf(filename, "%03d.jpg", file_index);
            save_jpeg(jpeg_start, jpeg_size, filename);
        }
    }
}
