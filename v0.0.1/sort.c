#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include "json-c/json.h"
#include "sort.h"

void sortByTitle(movie* m1; int compt){
    movie* movie;

    movie= malloc(sizeof(movie*));

    int i,j;

    for(i = 0; i < compt; i++){
        for(j = 1; j < compt; j++){
            if(m1[j]->title[0] < m1[j-1]->title[0]){
                movie = m1[j]->title[0];
                m1[j]->title[0] = m1[j-1]->title[0];
                m1[j-1]->title[0] = movie;
            }
        }
    }
    free(movie);

}



void sortByVoteAverage(movie* m1; int compt){
    movie* movie;

    movie= malloc(sizeof(movie*));

    int i,j;

    for(i = 0; i < compt; i++){
        for(j = 1; j < compt; j++){
            if(m1[j]->vote < m1[j-1]->vote){
                movie = m1[j]->vote;
                m1[j]->vote = m1[j-1]->vote;
                m1[j-1]->vote = movie;
            }
        }
    }
    free(movie);

}



void sortById(movie* m1; int compt){
    movie* movie;

    movie= malloc(sizeof(movie*));

    int i,j;

    for(i = 0; i < compt; i++){
        for(j = 1; j < compt; j++){
            if(m1[j]->id < m1[j-1]->id){
                movie = m1[j]->id;
                m1[j]->id = m1[j-1]->id;
                m1[j-1]->id = movie;
            }
        }
    }
    free(movie);

}




void cutDate(char* date, char* year, char* month, char* day){

    int i;
    int m = 0;
    int d = 0;
    int compt = 0;
    int length = strlen(date);

    for(i = 0; i < length; i++){
        if(date[i] == '-'){
            compt++;
        }
        else if(compt == 0){
            year[i] == date[i];
        }
        else if(compt == 1){
            month[m] == date[i];
            m++;
        }
        else if(compt == 2){
            day[d] == date[i];
            d++;
        }
    }

}


void sortByReleaseDate(Movie* m1; int compt){
    Movie* movie;

    Movie = malloc(sizeof(Movie*));

    char* year1;
    char* month1;
    char* day1;
    year1 = malloc(sizeof(char*));
    month1 = malloc(sizeof(char*));
    day1 = malloc(sizeof(char*));

    char* year2;
    char* month2;
    char* day2;
    year2 = malloc(sizeof(char*));
    month2 = malloc(sizeof(char*));
    day2 = malloc(sizeof(char*));

    int i,j;

    for(i = 0; i < compt; i++){
        for(j = 1; j < compt; j++){
                cutDate(date[j],year1,month1,day1);
                cutDate(date[j-1],year2,month2,day2);
            if(year1 < year2){
                movie = m1[j]->releaseDate[0];
                m1[j]->releaseDate[0] = m1[j-1]->releaseDate[0];
                m1[j-1]->releaseDate[0] = movie;
            }
            else if(month1 < month2){
                movie = m1[j]->releaseDate[0];
                m1[j]->releaseDate[0] = m1[j-1]->releaseDate[0];
                m1[j-1]->releaseDate[0] = movie;
            }
            else if(day1 < day2){
                movie = m1[j]->releaseDate[0];
                m1[j]->releaseDate[0] = m1[j-1]->releaseDate[0];
                m1[j-1]->releaseDate[0] = movie;
            }
        }
    }

    free(movie);
    free(year1);
    free(month1);
    free(day1);
    free(year2);
    free(month2);
    free(day2);

}
