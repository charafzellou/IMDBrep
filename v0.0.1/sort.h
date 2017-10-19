#ifndef FT_H
#define FT_H

void sortByTitle(Movie* m1; int compt);

void sortByVoteAverage(Movie* m1; int compt);

void sortById(Movie* m1; int compt);

void cutDate(char* date, char* year, char* month, char* day);

void sortByReleaseDate(Movie* m1; int compt);

Movie* getById(Movie* m1, unsigned int index, int taille);

#endif
