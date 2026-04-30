#pragma once

#include "note.h"
#include <map>

class NotesModel
{
private:
    std::map<uint32_t, Note> m_notesMap{};
    uint32_t nextId = 0;

public:
    NotesModel() = default;

    void addNote(const QString &title);
    void removeNote(int index);
    void updateNote(int index, const QString &newContent);
};
