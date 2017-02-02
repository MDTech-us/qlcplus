/*
  Q Light Controller Plus
  vcframepageshortcut.h

  Copyright (c) Heikki Junnila
                Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef VCFRAMEPAGESHORTCUT_H
#define VCFRAMEPAGESHORTCUT_H

#include <QSharedPointer>
#include <QKeySequence>

#include "qlcinputsource.h"

class QXmlStreamReader;
class QXmlStreamWriter;

/** @addtogroup ui_vc_widgets
 * @{
 */

#define KXMLQLCVCFramePageShortcut       "Shortcut"
#define KXMLQLCVCFramePageShortcutID     "ID"
#define KXMLQLCVCFramePageShortcutPage   "Page"

#define KXMLQLCVCFramePageShortcutInput         "Input"
#define KXMLQLCVCFramePageShortcutInputUniverse "Universe"
#define KXMLQLCVCFramePageShortcutInputChannel  "Channel"

#define KXMLQLCVCFramePageShortcutKey "Key"

class VCFramePageShortcut
{
public:
    explicit VCFramePageShortcut(int page);
    explicit VCFramePageShortcut(VCFramePageShortcut const& shortcut);

    /** Destructor */
    ~VCFramePageShortcut();

public:
    bool operator<(VCFramePageShortcut const& right) const;
    static bool compare(VCFramePageShortcut const* left, VCFramePageShortcut const* right);
    /************************************************************************
     * Load & Save
     ***********************************************************************/
public:
    /** Load properties and contents from an XML tree */
    bool loadXML(QXmlStreamReader &root);

    /** Save properties and contents to an XML document */
    bool saveXML(QXmlStreamWriter *doc);

public:
    /**
     *  Shortcut unique ID
     */
    quint8 m_id;

    /**
     *  The index of the page to switch to
     */
    int m_page;

    QSharedPointer<QLCInputSource> m_inputSource;
    QKeySequence m_keySequence;

};

/** @} */

#endif // VCFRAMEPAGESHORTCUT_H
