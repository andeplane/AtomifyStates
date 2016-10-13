#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <QState>
#include <QHistoryState>
#include <QVariantList>

class States : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QState* parsing READ parsing WRITE setParsing NOTIFY parsingChanged)
    Q_PROPERTY(QState* crashed READ crashed WRITE setCrashed NOTIFY crashedChanged)
    Q_PROPERTY(QState* idle READ idle WRITE setIdle NOTIFY idleChanged)
    Q_PROPERTY(QState* finished READ finished WRITE setFinished NOTIFY finishedChanged)
    Q_PROPERTY(QState* continued READ continued WRITE setContinued NOTIFY continuedChanged)
    Q_PROPERTY(QState* paused READ paused WRITE setPaused NOTIFY pausedChanged)
    Q_PROPERTY(QHistoryState* unPaused READ unPaused WRITE setUnPaused NOTIFY unPausedChanged)
    Q_PROPERTY(QVariantList list READ list WRITE setList NOTIFY listChanged)

public:
    explicit States(QObject *parent = 0);
    QState* crashed() const;
    QState* idle() const;
    QState* finished() const;
    QState* parsing() const;
    QVariantList list() const;
    QState* continued() const;
    QState* paused() const;
    QHistoryState* unPaused() const;

signals:
    void crashedChanged(QState* crashed);
    void idleChanged(QState* idle);
    void finishedChanged(QState* finished);
    void parsingChanged(QState* parsing);
    void listChanged(QVariantList list);
    void continuedChanged(QState* continued);
    void pausedChanged(QState* paused);
    void unPausedChanged(QHistoryState* unPaused);

public slots:
    void setCrashed(QState* crashed);
    void setIdle(QState* idle);
    void setFinished(QState* finished);
    void setParsing(QState* parsing);
    void setList(QVariantList list);
    void setContinued(QState* continued);
    void setPaused(QState* paused);
    void setUnPaused(QHistoryState* unPaused);

private:
    QState* m_crashed;
    QState* m_idle;
    QState* m_finished;
    QState* m_parsing;
    QVariantList m_list;
    QState* m_continued;
    QState* m_paused;
    QHistoryState* m_unPaused;
};

#endif // STATES_H
