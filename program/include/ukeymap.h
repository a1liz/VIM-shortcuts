#ifndef UKEYMAP_H
#define UKEYMAP_H
#include "ukey.h"
#include <QHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QList>
#endif // UKEYMAP_H

class uKeymap
{
private:
    int row,total;
    QList<int> cols;
    QList<uKey> ukey_list;
public:
    uKeymap(QString filepath){ readKeymapFromJSON(filepath);}
    ERROR_CODE readKeymapFromJSON(QString filepath);
};
