import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: root
    width: 900
    height: 600
    visible: true
    title: "Notes App"
    color: "#1e1e1e"

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.preferredWidth: 300
            Layout.fillHeight: true
            color: "#252526"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 15
                spacing: 10

                Text {
                    text: "Notes List (Count: " + notesList.count + ")"
                    color: "#ffffff"
                    font.pixelSize: 16
                    font.bold: true
                }

                ListView {
                    id: notesList
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    model: notesModel
                    clip: true
                    spacing: 5

                    delegate: Rectangle {
                        width: ListView.view.width
                        height: 65
                        color: ListView.isCurrentItem ? "#37373d" : "#2d2d30"
                        radius: 6

                        ColumnLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 2

                            Text {
                                text: model.title
                                color: "#ffffff"
                                font.bold: true
                                font.pixelSize: 14
                                Layout.fillWidth: true
                                elide: Text.ElideRight
                            }
                            Text {
                                text: model.timestamp
                                color: "#858585"
                                font.pixelSize: 11
                            }
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: notesList.currentIndex = index
                        }
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10

                    Button {
                        text: "Add Note"
                        Layout.fillWidth: true
                        onClicked: {
                            notesModel.addNote("New Note");
                            notesList.currentIndex = notesList.count - 1;
                        }
                        background: Rectangle {
                            color: parent.down ? "#005a9e" : "#0078d4"
                            radius: 4
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#ffffff"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        text: "Delete"
                        Layout.fillWidth: true
                        enabled: notesList.currentIndex >= 0
                        onClicked: notesModel.removeNote(notesList.currentIndex)
                        background: Rectangle {
                            color: parent.enabled ? (parent.down ? "#a4262c" : "#d13438") : "#555555"
                            radius: 4
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#ffffff"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#1e1e1e"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 30
                spacing: 15
                visible: notesList.currentIndex >= 0

                TextField {
                    id: titleEditor
                    Layout.fillWidth: true
                    text: notesList.currentIndex >= 0 ? notesModel.getNoteTitle(notesList.currentIndex) : ""
                    font.pixelSize: 28
                    font.bold: true
                    color: "#ffffff"
                    background: Item {}
                    placeholderText: "Note Title"
                    placeholderTextColor: "#555555"

                    onTextEdited: {
                        if (notesList.currentIndex >= 0) {
                            notesModel.updateNote(notesList.currentIndex, text, contentEditor.text)
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 1
                    color: "#3e3e42"
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true

                    TextArea {
                        id: contentEditor
                        text: notesList.currentIndex >= 0 ? notesModel.getNoteContent(notesList.currentIndex) : ""
                        color: "#cccccc"
                        font.pixelSize: 15
                        background: Item {}
                        wrapMode: TextEdit.WordWrap
                        placeholderText: "Start typing your note here..."
                        placeholderTextColor: "#555555"

                        onTextEdited: {
                            if (notesList.currentIndex >= 0) {
                                notesModel.updateNote(notesList.currentIndex, titleEditor.text, text)
                            }
                        }
                    }
                }
            }

            Text {
                anchors.centerIn: parent
                text: "Select a note from the list or create a new one"
                color: "#555555"
                font.pixelSize: 16
                visible: notesList.currentIndex < 0
            }
        }
    }
}