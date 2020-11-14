import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects.private 1.0
import QtQuick.Controls 1.5

Window {
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    title: qsTr("Parite 1 : Huffman")

    Image {
        id: image
        x: 86
        y: 35
        width: 322
        height: 387
        clip: false
        fillMode: Image.PreserveAspectFit
        source: "../../arbre.png"
    }

    Button {
        id: button
        x: 492
        y: 383
        width: 111
        height: 39
        text: qsTr("Suivant")
    }

    Button {
        id: button1
        x: 492
        y: 428
        width: 111
        height: 39
        text: qsTr("Précédant")
    }
}
