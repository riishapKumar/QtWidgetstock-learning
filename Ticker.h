#pragma once

#include "File.h"
#include "TickerItem.h"
#include <vector>
#include <QThread>


enum WhatData { SYMBOLS, PRICES, CHANGES };

class Ticker {
    static std::vector<TickerItem> ticker;
    static std::vector<QString> loadedTickerSymbols;

    QString dataToString(const WhatData& whatData);
    Ticker();
    static void refresh();
    static void loadTickersFromVector(const std::vector<QString>& tickerVec);
    static File savedTickers;


public:
    ~Ticker();
    std::vector<QString> getAllTickerSymbols();
    QString symbolsToString();
    QString priceToString();
    QString changeToString();
    QString toString();
    static Ticker& getInstance();
    static std::vector<QString> loadTickerSymbolsFromSettingsFile();

};
