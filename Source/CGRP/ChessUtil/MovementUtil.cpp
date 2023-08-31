#include "MovementUtil.h"

int32 MovementUtil::RowNumberFromIndex(int32 BoardIndex)
{
	return BoardIndex / 8;
}

int32 MovementUtil::OffsetFromXY(int32 x, int32 y)
{
	return x + y * 8;
}

