#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED


typedef struct Score
{
    SDL_Surface *fondScore;
    SDL_Rect posFond;
    SDL_Surface *texteScore;
    TTF_Font *police;
    SDL_Rect posScore;
    int scoreActuel;

} Score;

void initialiserScore(Score *score);
void afficherScore(SDL_Surface *ecran, Score *score, int s);
void initialiserScore2(  Score *score );

#endif