#ifndef UKEYMAP_H
#define UKEYMAP_H
#include "ukey.h"
#include <QHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#endif // UKEYMAP_H

class ukeymap
{
private:
    int row,total;
    QList<int> cols;
    QList<ukey> ukey_list;
public:
    ukeymap(QString filepath){ readKeymapFromJSON(filepath);}
    ERROR_CODE readKeymapFromJSON(QString filepath);
};
