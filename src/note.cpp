#include "note.h"

Note::Note(const QString &title) : m_title(title), m_timestamp(QDateTime::currentDateTime()) {}

QString Note::getTitle() const {
    return m_title;
}

QString Note::getContent() const {
    return m_content;
}

QDateTime Note::getTimestamp() const {
    return m_timestamp;
}

void Note::changeTitle(const QString &newTitle) {
    m_title = newTitle;
}

void Note::changeContent(const QString &newContent) {
    m_content = newContent;
}