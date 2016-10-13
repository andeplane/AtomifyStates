#include "atomify.h"
#include "states.h"
#include <QDebug>

Atomify::Atomify(QObject *parent) : QObject(parent),
    m_stateMachine(new QStateMachine(this)),
    m_states(new States(this))
{
    m_stateMachine->addState(m_states->parsing());
    m_stateMachine->addState(m_states->crashed());
    m_stateMachine->addState(m_states->idle());
    m_stateMachine->addState(m_states->finished());
    m_stateMachine->addState(m_states->continued());

    m_states->idle()->addTransition(this, SIGNAL(start()), m_states->parsing());
    m_states->parsing()->addTransition(this, SIGNAL(crashed()), m_states->crashed());
    m_states->parsing()->addTransition(this, SIGNAL(finished()), m_states->finished());
    m_states->parsing()->addTransition(this, SIGNAL(reset()), m_states->idle());

    m_states->crashed()->addTransition(this, SIGNAL(reset()), m_states->idle());

    m_states->finished()->addTransition(this, SIGNAL(reset()), m_states->idle());
    m_states->finished()->addTransition(this, SIGNAL(continued()), m_states->continued());

    m_states->continued()->addTransition(this, SIGNAL(reset()), m_states->idle());

    m_stateMachine->setInitialState(m_states->idle());
    m_stateMachine->start();
}

QStateMachine *Atomify::stateMachine() const
{
    return m_stateMachine;
}

States *Atomify::states() const
{
    return m_states;
}

void Atomify::setStateMachine(QStateMachine *stateMachine)
{
    if (m_stateMachine == stateMachine)
        return;

    m_stateMachine = stateMachine;
    emit stateMachineChanged(stateMachine);
}

void Atomify::setStates(States *states)
{
    if (m_states == states)
        return;

    m_states = states;
    emit statesChanged(states);
}
