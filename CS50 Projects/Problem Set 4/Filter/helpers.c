#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++){
        for (int j=0; j<width; j++){
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.00);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++){
        for (int j=0; j<width/2; j++){
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
     for(int i = 0; i<height; i++){
        for (int j=0; j<width; j++){
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            float counter = 0.00;
            
            for(int k = -1; k < 2; k++)
            {
                for(int h = -1; h < 2; h++)
                {
                    if(i+k < 0 || i+k > height-1 || j+h < 0 || j+h > width-1)
                    {
                        continue;
                    }
                    sumBlue += image [i+k][j+h].rgbtBlue;
                    sumRed += image [i+k][j+h].rgbtRed;
                    sumGreen += image [i+k][j+h].rgbtGreen;
                    
                    counter++;
                }
            }
            temp[i][j].rgbtBlue = round(sumBlue/counter);
            temp[i][j].rgbtRed = round(sumRed/counter);
            temp[i][j].rgbtGreen = round(sumGreen/counter);
            
        }
    }
    for(int i = 0; i<height; i++)
    {
        for (int j=0; j<width; j++){
            
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    
    for(int i = 0; i<height; i++){
        for (int j=0; j<width; j++){
        int iCoords[] = { i-1, i, i+1 };
        int jCoords[] = { j-1, j, j+1 };
        
        float Gx_red = 0;
        float Gx_blue = 0;
        float Gx_green = 0;
        
        float Gy_red = 0;
        float Gy_blue = 0;
        float Gy_green = 0;
        
        for(int k = 0; k < 3; k++)
            {
                for(int h = 0; h < 3; h++)
                {
                    int cur_i = iCoords[k];
                    int cur_j = jCoords[h];
                    
                    if(cur_i >= 0 && cur_i < height && cur_j >= 0 && cur_j < width)
                    {
                        RGBTRIPLE pixel = image [cur_i][cur_j];
                        
                        Gx_blue += Gx[k][h] * pixel.rgbtBlue;
                        Gx_red += Gx[k][h] * pixel.rgbtRed;
                        Gx_green += Gx[k][h] * pixel.rgbtGreen;
                        
                        Gy_blue += Gy[k][h] * pixel.rgbtBlue;
                        Gy_red += Gy[k][h] * pixel.rgbtRed;
                        Gy_green += Gy[k][h] * pixel.rgbtGreen;
                    }
                }
            }
        
        int finalBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
        int finalRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
        int finalGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
        
        temp[i][j].rgbtBlue = finalBlue > 255 ? 255: finalBlue;
        temp[i][j].rgbtRed = finalRed > 255 ? 255: finalRed;
        temp[i][j].rgbtGreen = finalGreen > 255 ? 255: finalGreen;
        
        }
    }
    
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++){
             
            image[i][j] = temp[i][j];
        }
    }
    return;
}
