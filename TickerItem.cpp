#include "File.h"
#include "TickerItem.h"
#include <QDebug>
#include <string>

// A TickerItem is instantiated by downloading newest data and assigning it to components
TickerItem::TickerItem(QString symbol) : tickerSymbol(symbol.toUpper()), infoDownloader(tickerSymbol) {
}

// load new data
std::vector<QString> TickerItem::downloadItemData() {
    return infoDownloader.getData();
}

// assigns parsed data from CSV file to TickerItem components
void TickerItem::assignNewItemData(std::vector<QString>& parsedCSV) {
    try {
        value = parsedCSV.at(2).toDouble();
        change = (value - parsedCSV.at(1).toDouble()) / value;
    }
    catch (const std::exception& e) { // Spelling error? Connection problems? Stock not existing anymore?
        qDebug() << tickerSymbol << ":\t TickerItem can not be loaded";
        qDebug() << e.what();
        return;
    }

    return;
}

QString TickerItem::buildColorblock(const QString& color) {
    return "<font color = \"" + color + "\">";
}

QString TickerItem::colorizeText(const QString& message, const QString& color) {
    return buildColorblock(color) + message + "</font>";
}

// Obvious getter methods
QString TickerItem::gettickerSymbol() { return tickerSymbol.mid(0, 9); }

QString TickerItem::getPrice() { return QString::number(value, 'd', 2); }

QString TickerItem::getChange() { return QString::number(change, 'd', 2); }

QString TickerItem::getChangeColor() { return (change < 0) ? "red" : "green"; }

QString TickerItem::getChangeSign() { return (change >= 0) ? "+" : ""; }

QString TickerItem::getChangeHTMLOutput() {
    return ("(" + colorizeText(getChangeSign() + getChange() + "%", getChangeColor()) + ")");
}

// Old toString method, for debug purposes
QString TickerItem::toString() {

    // Percentage shall be either in green or red color, depending on sign

    const QString tab("\t");

    return tickerSymbol.mid(0, 9) + tab
        + QString::number(value, 'd', 2)
        + tab + "("
        + colorizeText(getChangeSign() + QString::number(change, 'd', 2) + "%", getChangeColor())
        + ")";
}