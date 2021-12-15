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
    if (row != qcols.count())
        assert(0);
    for(int i = 0; i < qcols.count(); i++) {
        cols.append(qcols[i].toInt());
    }
    for(int i = 0; i < qdata.count(); i++) {
        QJsonObject qtmp = qdata[i].toObject();
        ukey_list.append(uKey(static_cast<UKEY_WIDTH>(qtmp["width"].toInt()), static_cast<UKEY_VALUE>(qtmp["valueLayer1"].toInt()),
                              static_cast<UKEY_VALUE>(qtmp["valueLayer2"].toInt()), static_cast<UKEY_VALUE>(qtmp["valueLayer3"].toInt()),
                              static_cast<UKEY_VALUE>(qtmp["valueLayer4"].toInt()), static_cast<UKEY_VALUE>(qtmp["viceValueLayer1"].toInt()),
                              static_cast<UKEY_VALUE>(qtmp["viceValueLayer2"].toInt()), static_cast<UKEY_VALUE>(qtmp["viceValueLayer3"].toInt()),
                              static_cast<UKEY_VALUE>(qtmp["viceValueLayer4"].toInt())
                                  ));
    }

    return _NO_ERROR;
}
