import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4


Rectangle {
    visible: true
    width: 440
    height: 480
   // title: qsTr("Hello World")

    //定位元素，画四个带颜色的正方形
    Row {
        id: colorTools
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 8
        }

        property color paintColor: "#33B5E5"
        spacing: 4

        //清楚按钮
        Button {
            text: "Clear"
            onClicked: {
                canvas.clear()
            }
        }

        //绑定点击更换颜色
        Repeater {
            model: ["#33B5E5", "#99CC00", "#FFBB33", "#FF4444"]

            Rectangle {
                id: colorSquare;
                width: 48; height: 48
                color: modelData
                signal clicked
                property bool active: false
                border.color: active? "#666666" : "#f0f0f0"
                border.width: 2

                MouseArea {
                    id: area1
                    anchors.fill :parent
                    onClicked: {
                        colorTools.paintColor = color
                    }

                }
            }
        }
    }

    //画框
    Rectangle{
        anchors.fill: canvas
        border.color: "#666"
        border.width: 4;
    }

    Canvas {
        id: canvas
        anchors {
            left: parent.left
            right: parent.right
            top: colorTools.bottom
            bottom: parent.bottom
            margins: 8
        }

        property real lastX
        property real lastY
        property color color: colorTools.paintColor  //继承颜色

        //清除函数
        function clear() {
            var ctx = getContext('2d')
            ctx.reset();
            canvas.requestPaint();
        }

        onPaint: {
            var ctx = getContext('2d')
            ctx.lineWidth = 4.5
            ctx.strokeStyle = canvas.color
            ctx.beginPath()
            ctx.moveTo(lastX, lastY)
            lastX = area.mouseX
            lastY = area.mouseY
            ctx.lineTo(lastX, lastY)
            ctx.stroke()
        }

        MouseArea {
            id: area
            anchors.fill: parent
            onPressed: {
                canvas.lastX = mouseX
                canvas.lastY = mouseY
            }
            onPositionChanged: {
                canvas.requestPaint()
            }
        }
    }
}
