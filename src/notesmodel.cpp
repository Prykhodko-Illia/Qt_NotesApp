#include "notesmodel.h"


void NotesModel::addNote(const QString &title) {
    m_notesMap[nextId++] = Note(title);
}


void NotesModel::removeNote(int index) {
    if (!m_notesMap.count(index)) {
        return;
    }

    m_notesMap.erase(index);
}


void NotesModel::updateNote(int index, const QString &newContent) {
    m_notesMap.at(index).changeContent(newContent);
}