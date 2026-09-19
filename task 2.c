/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to encrypt the image */
void encryptImage(const char *inputFile, const char *outputFile, int key)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char format[3];
    int width, height, maxValue;
    int r, g, b;

    /* Read image header */
    fscanf(in, "%2s", format);
    fscanf(in, "%d %d", &width, &height);
    fscanf(in, "%d", &maxValue);

    /* Write header */
    fprintf(out, "%s\n", format);
    fprintf(out, "%d %d\n", width, height);
    fprintf(out, "%d\n", maxValue);

    /* Encrypt every pixel */
    while (fscanf(in, "%d %d %d", &r, &g, &b) == 3)
    {
        r = (r + key) % 256;
        g = (g + key) % 256;
        b = (b + key) % 256;

        fprintf(out, "%d %d %d\n", r, g, b);
    }

    fclose(in);
    fclose(out);

    printf("Image encrypted successfully!\n");
    printf("Encrypted image: %s\n", outputFile);
}

/* Function to decrypt the image */
void decryptImage(const char *inputFile, const char *outputFile, int key)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char format[3];
    int width, height, maxValue;
    int r, g, b;

    /* Read image header */
    fscanf(in, "%2s", format);
    fscanf(in, "%d %d", &width, &height);
    fscanf(in, "%d", &maxValue);

    /* Write header */
    fprintf(out, "%s\n", format);
    fprintf(out, "%d %d\n", width, height);
    fprintf(out, "%d\n", maxValue);

    /* Decrypt every pixel */
    while (fscanf(in, "%d %d %d", &r, &g, &b) == 3)
    {
        r = (r - key + 256) % 256;
        g = (g - key + 256) % 256;
        b = (b - key + 256) % 256;

        fprintf(out, "%d %d %d\n", r, g, b);
    }

    fclose(in);
    fclose(out);

    printf("Image decrypted successfully!\n");
    printf("Decrypted image: %s\n", outputFile);
}

int main()
{
    int choice;
    int key;

    char inputFile[100];
    char outputFile[100];

    printf("=====================================\n");
    printf("     SIMPLE IMAGE ENCRYPTION TOOL\n");
    printf("=====================================\n");

    printf("\n1. Encrypt Image");
    printf("\n2. Decrypt Image");
    printf("\n3. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter input image file name: ");
        scanf("%99s", inputFile);

        printf("Enter output image file name: ");
        scanf("%99s", outputFile);

        printf("Enter encryption key (1-255): ");
        scanf("%d", &key);

        encryptImage(inputFile, outputFile, key);
    }
    else if (choice == 2)
    {
        printf("Enter encrypted image file name: ");
        scanf("%99s", inputFile);

        printf("Enter output image file name: ");
        scanf("%99s", outputFile);

        printf("Enter decryption key: ");
        scanf("%d", &key);

        decryptImage(inputFile, outputFile, key);
    }
    else if (choice == 3)
    {
        printf("Exiting program...\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}