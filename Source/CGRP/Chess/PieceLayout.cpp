#include "PieceLayout.h"

PieceType FPieceLayout::GetPieceType(int32 BoardIndex)
{
	APieceItem* piece = this->Layout[BoardIndex];

	if (piece == NULL)
	{
		return PieceType::None;
	}

	return this->Layout[BoardIndex]->Type;
}

void FPieceLayout::MovePiece(int32 OriginIndex, int32 TargetIndex)
{
	APieceItem* originPiece = this->Layout[OriginIndex];
	APieceItem* targetPiece = this->Layout[TargetIndex];

	if (targetPiece != NULL)
	{
		// Signifies that it is dead (out of the board)
		targetPiece->BoardIndex = -1;
	}

	if (originPiece != NULL)
	{
		// Update board index
		originPiece->BoardIndex = TargetIndex;
	}

	// Transfer piece to new location
	this->Layout[TargetIndex] = this->Layout[OriginIndex];
	// Empty origin piece location
	this->Layout[OriginIndex] = NULL;
}

void FPieceLayout::SetPiece(int32 BoardIndex, APieceItem* PieceItem)
{
	this->Layout[BoardIndex] = PieceItem;
}

FPieceLayout::FPieceLayout()
{
	this->Layout.SetNum(64, true);
}

FPieceLayout::~FPieceLayout()
{
	this->Layout.Empty();
}
