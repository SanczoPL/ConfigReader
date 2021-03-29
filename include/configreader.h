#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <stdio.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>

#include "includespdlog.h"

class ConfigReader : public QObject
{
public:
	ConfigReader();
	~ConfigReader();
	bool readConfig(QString configPathWithName, QJsonObject& obj);
	bool readArray(QString configPathWithName, QJsonArray& array);
};
#endif //CONFIG_READER_H
