#pragma once

class MovementUtil
{
public:
	static int32 RowNumberFromIndex(int32 BoardIndex);
	static int32 OffsetFromXY(int32 x, int32 y);
	static bool CheckYOffsetValidity(int32 OriginIndex, int32 OffsetIndex, int32 yOffset);
	static FVector GetGridLocation(int32 Count, int32 Width, double Size);
};
