/******************************************************************************
**
** Copyright (C) 2017 Lorenz Haas
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtMqtt module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef QMQTTTOPICNAME_H
#define QMQTTTOPICNAME_H

#include <QtMqtt/qmqttglobal.h>

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QMetaType>
#include <QtCore/QString>
#include <QtCore/QStringList>

QT_BEGIN_NAMESPACE

class QMqttTopicNamePrivate;

class QMqttTopicName;
// qHash is a friend, but we can't use default arguments for friends (§8.3.6.4)
Q_MQTT_EXPORT size_t qHash(const QMqttTopicName &name, size_t seed = 0) Q_DECL_NOTHROW;

class Q_MQTT_EXPORT QMqttTopicName
{
public:
    QMqttTopicName(const QString &name = QString());
    QMqttTopicName(const QLatin1String &name);
    QMqttTopicName(const QMqttTopicName &name);
    ~QMqttTopicName();
    QMqttTopicName &operator=(const QMqttTopicName &name);

#ifdef Q_COMPILER_RVALUE_REFS
    QMqttTopicName &operator=(QMqttTopicName &&other) noexcept { swap(other); return *this; }
#endif

    void swap(QMqttTopicName &other) noexcept { d.swap(other.d); }

    QString name() const;
    void setName(const QString &name);

    Q_REQUIRED_RESULT bool isValid() const;
    Q_REQUIRED_RESULT int levelCount() const;
    Q_REQUIRED_RESULT QStringList levels() const;

    friend Q_MQTT_EXPORT bool operator==(const QMqttTopicName &lhs, const QMqttTopicName &rhs) Q_DECL_NOTHROW;
    friend inline bool operator!=(const QMqttTopicName &lhs, const QMqttTopicName &rhs) Q_DECL_NOTHROW { return !(lhs == rhs); }
    friend Q_MQTT_EXPORT bool operator<(const QMqttTopicName &lhs, const QMqttTopicName &rhs) Q_DECL_NOTHROW;
    friend Q_MQTT_EXPORT size_t qHash(const QMqttTopicName &name, size_t seed) Q_DECL_NOTHROW;

private:
    QExplicitlySharedDataPointer<QMqttTopicNamePrivate> d;
};

Q_DECLARE_SHARED(QMqttTopicName)

#ifndef QT_NO_DATASTREAM
Q_MQTT_EXPORT QDataStream &operator<<(QDataStream &, const QMqttTopicName &);
Q_MQTT_EXPORT QDataStream &operator>>(QDataStream &, QMqttTopicName &);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_MQTT_EXPORT QDebug operator<<(QDebug, const QMqttTopicName &);
#endif

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QMqttTopicName)

#endif // QMQTTTOPICNAME_H
