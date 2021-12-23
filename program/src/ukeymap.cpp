#include "ukeymap.h"

ERROR_CODE uKeymap::readKeymapFromJSON(QString filepath) {
  QString val;
  QFile file;
  file.setFileName(filepath);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  val = file.readAll();
  file.close();
  QJsonObject qobj = QJsonDocument::fromJson(val.toUtf8()).object();
  QJsonValue qrows = qobj["rows"];
  QJsonArray qcols = qobj["cols"].toArray();
  QJsonArray qdata = qobj["data"].toArray();
  row = qrows.toInt();
  if (row != qcols.count()) assert(0);
  for (int i = 0; i < qcols.count(); i++) {
    cols.append(qcols[i].toInt());
  }
  for (int i = 0; i < qdata.count(); i++) {
    QJsonObject qtmp = qdata[i].toObject();
    ukey_list.append(
        uKey(static_cast<UKEY_WIDTH>(qtmp["width"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["valueLayer1"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["valueLayer2"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["valueLayer3"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["valueLayer4"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["viceValueLayer1"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["viceValueLayer2"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["viceValueLayer3"].toInt()),
             static_cast<UKEY_VALUE>(qtmp["viceValueLayer4"].toInt())));
  }

  return _NO_ERROR;
}

int uKeymap::length() {
  int total = 0;
  for (int i = 0; i < row; i++) {
    total += cols[i];
  }
  return total;
}

QString uKeymap::getValue(int id, int valueid) {
  return ukey_list[id].getValue(valueid);
}

QString uKeymap::getViceValue(int id, int valueid) {
  return ukey_list[id].getViceValue(valueid);
}

int uKeymap::getRowID(int id) {
  for (int i = 0; i < row; i++) {
    id -= cols[i];
    if (id <= 0) return i;
  }
  Q_ASSERT(0);
  return -1;
}

int uKeymap::getColID(int id) {
  for (int i = 0; i < getRowID(id); i++) {
    id -= cols[i];
  }
  return id;
}

UKEY_WIDTH uKeymap::getWidth(int id) { return ukey_list[id].getWidth(); }
