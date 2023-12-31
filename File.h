#pragma once

#include <vector>
#include <QFile>
#include <QString>

using constStr = const QString;

class File
{
protected:

    QString fileName;
    QFile file;
    std::vector<QString> fileContent;


public:

    File(constStr& fileName);
    ~File();

    bool fileIsValid();
    std::vector<QString> loadContents();
    bool saveContentsToFile(const std::vector<QString>& vec);
    static void makeSaveDir();

    static constStr getSaveDir();
    static constStr getFileInSaveDir(constStr& fileName);
    static constStr getSaveName();
    static constStr getTempFile();
    static constStr getCSVFileLocation();
    static constStr getSettingsFile();


};
