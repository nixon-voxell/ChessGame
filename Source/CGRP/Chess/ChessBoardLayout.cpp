#include "ChessBoardLayout.h"

FChessBoardLayout::FChessBoardLayout()
{
	this->Layout.SetNum(64, true);
}

FChessBoardLayout::~FChessBoardLayout()
{
}

int32 FChessBoardLayout::GetPieceIndex(int32 BoardIndex)
{
	return (int32)this->Layout[BoardIndex];
}
