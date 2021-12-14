#include "ukeymap.h"

ERROR_CODE ukeymap::readKeymapFromJSON(QString filepath) {
    QString val;
    QFile file;
    file.setFileName(filepath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    //qWarning() << val;
    QJsonObject qobj = QJsonDocument::fromJson(val.toUtf8()).object();
    qobj["rows"];
    QJsonValue qrows = qobj["rows"];
// TODO: parsing QJsonObject
    // QJsonArray qcols = qobj["cols"].toArray();
    // QJsonValue qdata = qobj.value(QString("data"));

    // row = qrows.toInt();
    // cols = qcols.toArray();


    return _NO_ERROR;
}
