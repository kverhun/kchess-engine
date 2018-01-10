#include "Common.h"

bool Chess::IsPositionOnBoard(const TPosition & i_pos)
{
    return i_pos.first >= 0 && i_pos.first <= 7
        && i_pos.second >= 0 && i_pos.second <= 7;
}
