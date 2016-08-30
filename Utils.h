#include "stdafx.h"

bool isPointInRect(CPoint point, CRect dRect)
{
	return point.x >= dRect.left && point.x <= dRect.right
		&& point.y >= dRect.top && point.y <= dRect.bottom;
}