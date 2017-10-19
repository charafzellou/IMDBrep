#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include "json-c/json.h"

unsigned int writeInFile(void *ptr, unsigned int sizeOfElement, unsigned int nbElements, FILE *outputStream){
    unsigned int written = fwrite(ptr, sizeOfElement, nbElements, outputStream);
    return(written);
}

void downloadZipFile(void){
    CURL *curl;
    FILE * zipFile;
    CURLcode res;
    char *url = "https://api.themoviedb.org/3/movie/popular?api_key=21b9296f3b9bcb3628c55516f08d19a0&language=fr-FR&page=1";
    char *fileName = "movie_ids_10_19_2017.json.gz";
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        zipFile = fopen(fileName, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeInFile);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, zipFile);

#ifdef SKIP_PEER_VERIFICATION
    /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
    /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

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
            case '0': downloadZipFile();
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
