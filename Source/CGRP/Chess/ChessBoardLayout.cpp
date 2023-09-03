#include "ChessBoardLayout.h"


void FChessBoardLayout::CopyBoardLayout(FChessBoardLayout* BoardLayout)
{
	this->Layout.Empty();

	for (int l = 0; l < BoardLayout->Layout.Num(); l++)
	{
		this->Layout.Add(BoardLayout->Layout[l]);
	}
}

int32 FChessBoardLayout::GetPieceIndex(int32 BoardIndex)
{
	return (int32)this->Layout[BoardIndex];
}

void FChessBoardLayout::MovePiece(int32 OriginIndex, int32 TargetIndex)
{
	// Transfer piece to new location
	this->Layout[TargetIndex] = this->Layout[OriginIndex];
	// Empty origin piece location
	this->Layout[OriginIndex] = PieceType::None;
}

FChessBoardLayout::FChessBoardLayout()
{
	this->Layout.SetNum(64, true);
}

FChessBoardLayout::~FChessBoardLayout()
{
	this->Layout.Empty();
}
