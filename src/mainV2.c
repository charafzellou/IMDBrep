#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include "json-c/json.h"
//#include "sort.h"

struct Movie{
    unsigned int id;
    float voteAverage;
    char* title;
    char* originalLanguage;
    char* originalTitle;
    short adult;
    char* overview;
    char* releaseDate;
};

typedef struct Movie Movie;

unsigned int writeInFile(void *ptr, unsigned int sizeOfElement, unsigned int nbElements, FILE *outputStream){
    unsigned int written = fwrite(ptr, sizeOfElement, nbElements, outputStream);
    return(written);
}

void downloadJSON(void){
    CURL *curl;
    FILE * zipFile;
    CURLcode res;
    char *url = "http://api.themoviedb.org/3/movie/popular?api_key=21b9296f3b9bcb3628c55516f08d19a0&language=fr-FR&page=1";
    char *fileName = "movie_ids_10_19_2017.json";
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        zipFile = fopen(fileName, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeInFile);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, zipFile);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
    fclose(zipFile);
  }

  curl_global_cleanup();
}

void printMovie(Movie* movie){
    printf("Movie id : %u\nTitle : %s\nOverview : %s\nNote : %f",movie->id, movie->title, movie->overview, movie->voteAverage);
}

int main(int argc, char* argv[])
{
    char c;
    int flag = 1;
    int selectedId = 0;
    while(flag){
            printf("\n\t\t*****Main menu*****\
                   \n0 (Download zip file)\
                   \n1 (See movies)\
                   \n2 (Sort movies)\
                   \n3 (Get movie by id)\
                   \nOther (Exit)\n");
        c = getchar();
        switch(c){
            case '0': downloadJSON();
                break;
            case '1' : //Prrint movies
                break;
            case '2' : getchar();
                printf("\n- Sort :\
                       \n\t0 (by id)\
                       \n\t1 (by vote average)\
                       \n\t2 (by title)\
                       \n\tOther (return)\n");
                switch(getchar()){
                    /*case '0': sortById(movies, movies_size);
                        break;
                    case '1': sortByVoteAverage(movies, movies_size);
                        break;
                    case '2': sortByTitle(movies, movies_size);
                        break;*/
                    default:
                        break;
                }
                //getchar();
                break;
            case '3' : printf("\n- Id = ");
                scanf("%d", &selectedId);
                /*Movie* movie = getById(selectedId);
                if(getById(movieTab, movieTabSize, selectedId)==NULL){
                printf("No movie found at id %d", selectedID);
                }else{
                    printMovie(movie);
                }*/
                printf("\n\n");
                break;
            default: flag = 0;
                break;
        }
        getchar();
    }
    printf("\n\n**** end ****\n\n");
    return 0;
}
