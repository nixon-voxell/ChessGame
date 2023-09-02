#pragma once

#include "HoverType.generated.h"

UENUM()
enum struct HoverType : int32
{
	None = 0,
	Tile = 1,
	WhitePiece = 2,
	BlackPiece = 3,
};
