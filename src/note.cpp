#include "note.h"

Note::Note(const QString &title) : m_title(title), m_timestamp(QDateTime::currentDateTime()) {}

void Note::changeContent(const QString &newContent) {
    m_content = newContent;
}