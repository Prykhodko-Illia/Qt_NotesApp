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

    QString getTitle() const;
    QString getContent() const;
    QDateTime getTimestamp() const;

    void changeTitle(const QString &newTitle);
    void changeContent(const QString &newContent);
};