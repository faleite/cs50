#include "math.h"
#include "helpers.h"



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // define var for store the average
    int average;

    // iterate in each byte in line
    for (int i = 0; i < height; i++)
    {
        // iterate in each byte in column
        for (int j = 0; j < width; j++)
        {
            // RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate the average
            average = round((blue + green + red) / 3.0);

            // change the color for a gray scale
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // define var for store types of the sepia
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    // iterate in each byte in line
    for (int i = 0; i < height; i++)
    {
        // iterate in each byte in column
        for (int j = 0; j < width; j++)
        {
            // RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate the color sepia in red
            sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);

            // Calculate the color sepia in green
            sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            // Calculate the color sepia in blue
            sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // change the color for sepia
            // get the minor value using fmin()
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;

    // iterate in each byte in line
    for (int i = 0; i < height; i++)
    {
        // iterate in each byte in column
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixels
            tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary copy of the image
    RGBTRIPLE tmp[height][width];

    // copy image
    // iterate in each byte in line
    for (int i = 0; i < height; i++)
    {
        // iterate in each byte in column
        for (int j = 0; j < width; j++)
        {
            // copy image
            tmp[i][j] = image[i][j];
        }
    }

    // iterate in each byte in line
    for (int i = 0; i < height; i++)
    {
        // iterate in each byte in column
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // iterate for each pixels neighbouring
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // check if neighbouring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) ||
                        currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
                tmp[i][j].rgbtRed = round(totalRed / counter);
                tmp[i][j].rgbtGreen = round(totalGreen / counter);
                tmp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }
    // copy pixels blur into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }
    return;
}
