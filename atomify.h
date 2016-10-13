#ifndef ATOMIFY_H
#define ATOMIFY_H
#include <QStateMachine>
#include <QObject>

class Atomify : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStateMachine* stateMachine READ stateMachine WRITE setStateMachine NOTIFY stateMachineChanged)
    Q_PROPERTY(States* states READ states WRITE setStates NOTIFY statesChanged)
public:
    explicit Atomify(QObject *parent = 0);
    QStateMachine* stateMachine() const;
    class States* states() const;

signals:
    void stateMachineChanged(QStateMachine* stateMachine);
    void statesChanged(class States* states);
    void crashed();
    void reset();
    void start();
    void continued();
    void finished();
    void paused();
    void unPaused();

public slots:
    void setStateMachine(QStateMachine* stateMachine);
    void setStates(States* states);

private:
    QStateMachine* m_stateMachine;
    class States* m_states;
};

#endif // ATOMIFY_H
