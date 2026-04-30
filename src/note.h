#pragma once

#include <QString>
#include <QDateTime>

class Note
{
private:
    QString m_title{};
    QString m_content{};
    QDateTime m_timestamp{};

public:
    Note() = default;
    explicit Note(const QString &title);

    void changeContent(const QString &newContent);
};
