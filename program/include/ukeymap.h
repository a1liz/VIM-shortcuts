#ifndef UKEYMAP_H
#define UKEYMAP_H
#include <QFile>
#include <QHash>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QList>

#include "ukey.h"
#endif  // UKEYMAP_H

class uKeymap {
 private:
  int row;
  QList<int> cols;
  QList<uKey> ukey_list;

 public:
  uKeymap(QString filepath) { readKeymapFromJSON(filepath); }
  ERROR_CODE readKeymapFromJSON(QString filepath);
  int length();
  QString getValue(int id, int valueid);
  QString getViceValue(int id, int valueid);
  int getRowID(int id);
  int getColID(int id);
  UKEY_WIDTH getWidth(int id);
};
