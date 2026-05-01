#include "notesmodel.h"

NotesModel::NotesModel(QObject *parent) : QAbstractListModel(parent) {}

int NotesModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return static_cast<int>(m_notes.size());
}

QVariant NotesModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(m_notes.size())) {
        return QVariant();
    }

    const Note &note = m_notes.at(index.row());
    switch (role) {
        case TitleRole:
            return note.getTitle();
        case ContentRole:
            return note.getContent();
        case TimestampRole:
            return note.getTimestamp().toString("yyyy-MM-dd HH:mm");

        default:
            return QVariant();
    }
}

QHash<int, QByteArray> NotesModel::roleNames() const {
    QHash<int, QByteArray> roles{};
    roles[TitleRole] = "title";
    roles[ContentRole] = "content";
    roles[TimestampRole] = "timestamp";

    return roles;
}

void NotesModel::addNote(const QString &title) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_notes.emplace_back(title);
    endInsertRows();
}

void NotesModel::removeNote(int index) {
    if (index < 0 || index >= static_cast<int>(m_notes.size())) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    m_notes.erase(m_notes.begin() + index);
    endRemoveRows();
}

void NotesModel::updateNote(int index, const QString &newTitle, const QString &newContent) {
    if (index < 0 || index >= static_cast<int>(m_notes.size())) {
        return;
    }

    m_notes[index].changeTitle(newTitle);
    m_notes[index].changeContent(newContent);
    emit dataChanged(this->index(index, 0), this->index(index, 0), {TitleRole, ContentRole});
}

QString NotesModel::getNoteTitle(int index) const {
    if (index < 0 || index >= static_cast<int>(m_notes.size())) {
        return "";
    }

    return m_notes[index].getTitle();
}

QString NotesModel::getNoteContent(int index) const {
    if (index < 0 || index >= static_cast<int>(m_notes.size())) {
        return "";
    }

    return m_notes[index].getContent();
}