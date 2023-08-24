#include "ChessBoardLayout.h"

FChessBoardLayout::FChessBoardLayout()
{
}

FChessBoardLayout::~FChessBoardLayout()
{
}

int32 FChessBoardLayout::GetPieceIndex(int32 BoardIndex)
{
	return (int32)this->Layout[BoardIndex];
}
