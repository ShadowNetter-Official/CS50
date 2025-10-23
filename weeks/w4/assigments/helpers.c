#include "helpers.h"
#include <math.h>
#include <stdbool.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // get rgb of image pixels, sum up rgb to get average, set all pixels to average
    for (int row = 0; row < height; row++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            // for every pixel in image, get average, set colors to average
            BYTE average = round((image[row][pixel].rgbtBlue + image[row][pixel].rgbtGreen + image[row][pixel].rgbtRed) / 3.0);
            image[row][pixel].rgbtBlue = average;
            image[row][pixel].rgbtGreen = average;
            image[row][pixel].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // algorithm
    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    for (int row = 0; row < height; row++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            float red = image[row][pixel].rgbtRed;
            float blue = image[row][pixel].rgbtBlue;
            float green = image[row][pixel].rgbtGreen;
            int newred = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (newred > 255) { newred = 255; }

            int newgreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (newgreen > 255) { newgreen = 255; }

            int newblue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (newblue > 255) { newblue = 255; }

            image[row][pixel].rgbtBlue = newblue;
            image[row][pixel].rgbtGreen = newgreen;
            image[row][pixel].rgbtRed = newred;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*

    input:

    1 2 3 4
    5 6 7 8
    9 A B C

    output:

    4 3 2 1
    8 7 6 5
    C B A 9

    for every row

    start from end, append i to new array
    replace old row with new array

    */
   for (int row = 0; row < height; row++)
   {
        RGBTRIPLE newrow[width];
        int index = 0;
        for (int pixel = width - 1; pixel >= 0; pixel--)
        {
            newrow[index] = image[row][pixel];
            index++;
        }
        for (int i = 0; i < width; i++)
        {
            image[row][i] = newrow[i];
        }
   }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            float count = 0;
            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = pixel - 1; j <= pixel + 1; j++)
                {
                    if (i >= 0 && i < height && j >= 0 && j < width)
                    {
                        red += image[i][j].rgbtRed;
                        green += image[i][j].rgbtGreen;
                        blue += image[i][j].rgbtBlue;
                        count++;
                    }
                }
            }
            copy[row][pixel].rgbtRed = round(red / count);
            copy[row][pixel].rgbtGreen = round(green / count);
            copy[row][pixel].rgbtBlue = round(blue / count);
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = copy[k][l];
        }
    }
    return;
}

