#include "MovementUtil.h"

int32 MovementUtil::RowNumberFromIndex(int32 BoardIndex)
{
	return BoardIndex / 8;
}

int32 MovementUtil::OffsetFromXY(int32 x, int32 y)
{
	return x + y * 8;
}

bool MovementUtil::CheckYOffsetValidity(int32 OriginIndex, int32 OffsetIndex, int32 yOffset)
{
	int32 originRowNumber = MovementUtil::RowNumberFromIndex(OriginIndex);
	int32 offsetRowNumber = MovementUtil::RowNumberFromIndex(OffsetIndex);

	return (offsetRowNumber - originRowNumber) == yOffset;
}

