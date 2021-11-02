/**
 * @authors Yoan Laurain ; Hugo Carricart ; Nathan Lesourd
 * @brief Header de Echiquier
 * @file Echiquier.h
 * @date 26/10/2021
 * @version 0.5
 */

#if !defined Echiquier_h
#define Echiquier_h
#include "Piece.h"

class Echiquier
{
   private:
    Piece *m_cases[64];

   public:

    Echiquier();
    Piece *getPiece( int x, int y );
    bool placer( Piece *p );
    void deplacer( Piece *p, int x, int y );
    void enleverPiece( int x, int y );
    bool VerifMoveRoiRoque(Roi *r, int x ,int y);
    void deplacementRoque( Roi *r, Tour *p);
};

#endif
