#pragma once

#include <QAbstractListModel>
#include <vector>
#include "note.h"

class NotesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum NoteRoles {
        TitleRole = Qt::UserRole + 1,
        ContentRole,
        TimestampRole
    };

    explicit NotesModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addNote(const QString &title);
    Q_INVOKABLE void removeNote(int index);
    Q_INVOKABLE void updateNote(int index, const QString &newTitle, const QString &newContent);

    Q_INVOKABLE QString getNoteTitle(int index) const;
    Q_INVOKABLE QString getNoteContent(int index) const;

private:
    std::vector<Note> m_notes;
};