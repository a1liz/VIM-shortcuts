#ifndef UKEY_H
#define UKEY_H

#endif // UKEY_H
#include <cstring>
#include <QString>
#include "type.h"

class ukey
{
private:
    UKEY_WIDTH width; // Default width is 1U
    UKEY_VALUE value[4];
    UKEY_STATUS status = _await;


public:
    ukey(UKEY_VALUE uv=_null, UKEY_WIDTH uw = _100U) {value[0]=uv; width=uw;}
    ERROR_CODE registerLayer(int layer, UKEY_VALUE uv);

};
