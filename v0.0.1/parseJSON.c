#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseJSON.h"

int parseJSON(){
	
    FILE* theJSON = fopen("weather.json", "r");
    int jump = 0;
    if(theJSON == NULL)
    {
        fprintf(stderr,"\nERROR, \ncannot open the weather file");
        return -1;
    }
    char weather[4] = "", temp_now[7] = "", pressure[5] = "", humidity[3] = "", temp_min[7] = "", temp_max[7] = "",
        visibility[6] = "", wind_speed[4] = "", wind_degree[4] = "", sun_sunrise[11] = "", sun_sunset[11] = "", lecture[100];

    fseek(theJSON, 0, SEEK_SET);

    fseek(theJSON, 51, SEEK_CUR);
    fread(weather, 3, 1, theJSON);
    char actual_char = "";

    while(jump < 5){
        actual_char = fgetc(theJSON);
        if(actual_char == ','){
            jump++;
        }
    }
    jump = 0;
    while(jump < 2){
        actual_char = fgetc(theJSON);
         if(actual_char == ':'){
            jump++;
        }
    }

    int i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        temp_now[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }

    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        pressure[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
     i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        humidity[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

     while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
     i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        temp_min[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
     i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != '}')
    {
        temp_max[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        visibility[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    jump = 0;
    while(jump < 2){
        actual_char = fgetc(theJSON);
         if(actual_char == ':'){
            jump++;
        }
    }
    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        wind_speed[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != '}')
    {
        wind_degree[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

     jump = 0;
    while(jump < 9){
        actual_char = fgetc(theJSON);
         if(actual_char == ':'){
            jump++;
        }
    }
    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != ',')
    {
        sun_sunrise[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    while(actual_char != ':'){
        actual_char = fgetc((theJSON));
    }
    i = 0;
    actual_char = fgetc(theJSON);
    while(actual_char != '}')
    {
        sun_sunset[i] = actual_char;
        actual_char = fgetc(theJSON);
        i++;
    }

    fclose(theJSON);
}
