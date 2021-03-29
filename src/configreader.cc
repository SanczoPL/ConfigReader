#include "../include/configreader.h"

ConfigReader::ConfigReader() {
	Logger->trace("ConfigReader::ConfigReader()");
}

ConfigReader::~ConfigReader() {}

bool ConfigReader::readConfig(QString configPathWithName, QJsonObject& obj) {
	Logger->trace("ConfigReader::readConfig() try to load {}", (configPathWithName).toStdString());
	QFile jConfigFile{ configPathWithName };
	if (!jConfigFile.open(QIODevice::ReadOnly)) {
		Logger->error("Can not open json file:{}", (configPathWithName).toStdString());
		return false;
	}

	QJsonDocument jConfigDoc{ QJsonDocument::fromJson((jConfigFile.readAll())) };
	if (!jConfigDoc.isObject()) {
		Logger->error("Invalid json config file:{}", (configPathWithName).toStdString());
		return false;
	}
	obj = { jConfigDoc.object() };
	Logger->debug("{} load successful", (configPathWithName).toStdString());
	return true;
}

bool ConfigReader::readArray(QString configPathWithName, QJsonArray& array) {
	Logger->trace("ConfigReader::readConfig() try to load {}", (configPathWithName).toStdString());
	QFile jConfigFile{ configPathWithName };
	if (!jConfigFile.open(QIODevice::ReadOnly)) {
		Logger->error("Can not open json file:{}", (configPathWithName).toStdString());
		return false;
	}

	QJsonDocument jConfigDoc{ QJsonDocument::fromJson((jConfigFile.readAll())) };
	if (!jConfigDoc.isArray()) {
		Logger->error("Invalid array file:{}", (configPathWithName).toStdString());
		return false;
	}
	array = { jConfigDoc.array() };
	Logger->debug("{} load successful", (configPathWithName).toStdString());
	return true;
}