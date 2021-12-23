#ifndef UKEY_H
#define UKEY_H

#endif  // UKEY_H
#include <QString>
#include <cstring>

#include "type.h"

class uKey {
 private:
  UKEY_WIDTH width;  // Default width is 1U
  UKEY_VALUE value[4];
  UKEY_VALUE vicevalue[4];
  UKEY_STATUS status = _await;

 public:
  uKey(UKEY_WIDTH uw = _100U, UKEY_VALUE uv = _null);
  uKey(UKEY_WIDTH uw, UKEY_VALUE uv0, UKEY_VALUE uv1, UKEY_VALUE uv2,
       UKEY_VALUE uv3, UKEY_VALUE uvv0, UKEY_VALUE uvv1, UKEY_VALUE uvv2,
       UKEY_VALUE uvv3);
  ERROR_CODE registerLayer(int layer, UKEY_VALUE uv);
  QString getValue(int valueid);
  QString getViceValue(int valueid);
  UKEY_WIDTH getWidth();
};
