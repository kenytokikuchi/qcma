/*
 *  QCMA: Cross-platform content manager assistant for the PS Vita
 *
 *  Copyright (C) 2013  Codestation
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LISTENERWORKER_H
#define LISTENERWORKER_H

#include "database.h"
#include "baseworker.h"

#include <QObject>

#include <stdint.h>

extern "C" {
#include <vitamtp.h>
}

class ListenerWorker : public BaseWorker
{
    Q_OBJECT
public:
    explicit ListenerWorker(QObject *parent = 0);

    void setDevice(vita_device_t *device);
    bool isConnected();
    void disconnect();
    int rebuildDatabase();

    Database db;

private:
    uint16_t processAllObjects(CMAObject *parent, uint32_t handle);
    void vitaEventSendObject(vita_event_t *event, int eventId);
    void vitaEventSendObjectMetadata(vita_event_t *event, int eventId);
    void vitaEventSendNumOfObject(vita_event_t *event, int eventId);
    void vitaEventCancelTask(vita_event_t *event, int eventId);
    void vitaEventSendHttpObjectFromURL(vita_event_t *event, int eventId);
    void vitaEventUnimplementated(vita_event_t *event, int eventId);
    void vitaEventSendObjectStatus(vita_event_t *event, int eventId);
    void vitaEventSendObjectThumb(vita_event_t *event, int eventId);
    void vitaEventDeleteObject(vita_event_t *event, int eventId);
    void vitaEventGetSettingInfo(vita_event_t *event, int eventId);
    void vitaEventSendHttpObjectPropFromURL(vita_event_t *event, int eventId);
    void vitaEventSendPartOfObject(vita_event_t *event, int eventId);
    void vitaEventOperateObject(vita_event_t *event, int eventId);
    void vitaEventGetPartOfObject(vita_event_t *event, int eventId);
    void vitaEventSendStorageSize(vita_event_t *event, int eventId);
    void vitaEventCheckExistance(vita_event_t *event, int eventId);
    void vitaEventGetTreatObject(vita_event_t *event, int eventId);
    void vitaEventSendCopyConfirmationInfo(vita_event_t *event, int eventId);
    void vitaEventSendObjectMetadataItems(vita_event_t *event, int eventId);
    void vitaEventSendNPAccountInfo(vita_event_t *event, int eventId);
    void vitaEventRequestTerminate(vita_event_t *event, int eventId);

    vita_device_t *device;
    volatile bool connected;
    static const metadata_t g_thumbmeta;

signals:
    void refreshDatabase();

private slots:
    void process();
};

#endif // LISTENERWORKER_H
