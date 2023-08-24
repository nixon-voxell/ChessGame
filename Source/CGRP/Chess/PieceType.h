#pragma once

UENUM()
enum struct PieceType : int32
{
	None = 0,

	WhitePawn = 1,
	WhiteRook = 2,
	WhiteKnight = 3,
	WhiteBishopPiece = 4,
	WhiteQueenPiece = 5,
	WhiteKingPiece = 6,

	BlackPawn = -1,
	BlackRook = -2,
	BlackKnight = -3,
	BlackBishopPiece = -4,
	BlackQueenPiece = -5,
	BlackKingPiece = -6,
};
