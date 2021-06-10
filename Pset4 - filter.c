#include "helpers.h"
#include <stdio.h>
#include <stdbool.h>

// Convert image to grayscale
int averageAndRound(int divisor, int dividend)
{
    return (dividend + (divisor/2))/divisor;
}

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
           int average =  averageAndRound(3, total);

           image[i][j].rgbtRed = average;
           image[i][j].rgbtBlue = average;
           image[i][j].rgbtGreen = average;
        }
    }

    return;
}

int cap(int value)
{
    if (value > 255)
    {
        return 255;
    }

    return value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {


            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            float sepiaBlue = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;

            int roundedRed = sepiaRed + 0.5;
            int roundedGreen = sepiaGreen + 0.5;
            int roundedBlue = sepiaBlue + 0.5;

             int cappedRed = cap(roundedRed);
              int cappedGreen = cap(roundedGreen);
               int cappedBlue = cap(roundedBlue);

           image[i][j].rgbtRed = cappedRed;
           image[i][j].rgbtBlue = cappedGreen;
           image[i][j].rgbtGreen = cappedBlue;

        }
    }


    return;
}


void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {

                swap(&image[i][j], &image[i][width - 1 - j]);

        }
    }
    return;
}


bool isValid(int i, int j, int height, int width)
{
        return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blurred_image_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int totalRed = 0;
     int totalBlue = 0;
      int totalGreen = 0;
      RGBTRIPLE tempPixel;
      int numberOfPixels = 0;

     for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;

            if (isValid(new_i, new_j, height, width))
            {
                totalRed += image[new_i][new_j].rgbtRed;
                totalBlue += image[new_i][new_j].rgbtBlue;
                totalGreen += image[new_i][new_j].rgbtGreen;
                numberOfPixels++;
            }
        }
    }

        tempPixel.rgbtRed =  (totalRed + numberOfPixels/2) / numberOfPixels;
        tempPixel.rgbtBlue =  (totalBlue + numberOfPixels/2) / numberOfPixels;
        tempPixel.rgbtGreen =  (totalGreen + numberOfPixels/2) / numberOfPixels;

    return tempPixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

   RGBTRIPLE pseudoImage[height][width];



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           pseudoImage[i][j] = get_blurred_image_pixel(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
          image[i][j] = pseudoImage[i][j];
        }
    }


    return;
}
