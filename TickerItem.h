#pragma once

#include "TickerInfoDownloader.h"
#include <QString>
#include <vector>

class TickerItem {

    QString tickerSymbol;
    double value;
    QString currency;
    double change;
    std::vector<QString> itemData;

    TickerInfoDownloader infoDownloader;

    QString buildColorblock(const QString& color);
    QString colorizeText(const QString& message, const QString& color);

public:
    explicit TickerItem(QString symbol);
    QString toString();
    QString gettickerSymbol();
    QString getPrice();
    QString getChange();
    QString getChangeColor();
    QString getChangeSign();
    QString getChangeHTMLOutput();

    std::vector<QString> downloadItemData();
    void assignNewItemData(std::vector<QString>& parsedCSV);

protected:

};