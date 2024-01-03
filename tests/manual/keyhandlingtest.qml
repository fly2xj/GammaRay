/*
  keyhandlingtest.qml

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2014 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Volker Krause <volker.krause@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

import QtQuick 2.0

Rectangle {
  color: "lightsteelblue"
  width: 640
  height: 480
  focus: true

  Text {
    id: label
    anchors.centerIn: parent
    text: "press a key"
  }

  // always works
  Keys.onLeftPressed: { label.text = "left pressed"; }

  // breaks with signal spy callbacks installed
  Keys.onPressed: { label.text = "key pressed"; console.log("xxx"); }
}
