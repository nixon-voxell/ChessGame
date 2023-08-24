#include "ChessBoardLayout.h"

FChessBoardLayout::FChessBoardLayout()
{
}

FChessBoardLayout::~FChessBoardLayout()
{
}

int32 FChessBoardLayout::GetItemIndex(int32 BoardIndex)
{
	return this->Layout[BoardIndex];
}
