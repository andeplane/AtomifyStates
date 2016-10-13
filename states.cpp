#include "states.h"

States::States(QObject *parent) : QObject(parent),
    m_crashed(new QState()),
    m_idle(new QState()),
    m_finished(new QState()),
    m_parsing(new QState()),
    m_continued(new QState())
{
    m_crashed->setObjectName("Crashed");
    m_idle->setObjectName("Idle");
    m_finished->setObjectName("Finished");
    m_parsing->setObjectName("Parsing");
    m_continued->setObjectName("Continued");
    m_list << QVariant::fromValue(m_idle) << QVariant::fromValue(m_crashed) << QVariant::fromValue(m_finished) << QVariant::fromValue(m_parsing) << QVariant::fromValue(m_continued);
}

QState *States::crashed() const
{
    return m_crashed;
}

QState *States::idle() const
{
    return m_idle;
}

QState *States::finished() const
{
    return m_finished;
}

QState *States::parsing() const
{
    return m_parsing;
}

QVariantList States::list() const
{
    return m_list;
}

QState *States::continued() const
{
    return m_continued;
}

void States::setCrashed(QState *crashed)
{
    if (m_crashed == crashed)
        return;

    m_crashed = crashed;
    emit crashedChanged(crashed);
}

void States::setIdle(QState *idle)
{
    if (m_idle == idle)
        return;

    m_idle = idle;
    emit idleChanged(idle);
}

void States::setFinished(QState *finished)
{
    if (m_finished == finished)
        return;

    m_finished = finished;
    emit finishedChanged(finished);
}

void States::setParsing(QState *parsing)
{
    if (m_parsing == parsing)
        return;

    m_parsing = parsing;
    emit parsingChanged(parsing);
}

void States::setList(QVariantList list)
{
    if (m_list == list)
        return;

    m_list = list;
    emit listChanged(list);
}

void States::setContinued(QState *continued)
{
    if (m_continued == continued)
        return;

    m_continued = continued;
    emit continuedChanged(continued);
}
