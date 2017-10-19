#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include "json-c/json.h"

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

int main(int argc, char* argv[])
{
    char c;
    int flag = 1;
    while(flag){
            printf("0 (Download zip file)\n\
                   Q (Exit)");
        c = getchar();
        switch(c){
            case '0': downloadJSON();
                break;
            case 'q' :
            case 'Q' : flag = 0;
                break;
            default: printf("Unknown choice !\n");
                break;
        }
        getchar();
    }
    printf("\n\n**** end ****\n\n");
    return 0;
}
