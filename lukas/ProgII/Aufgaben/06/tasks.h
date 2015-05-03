/** @file
 * Tasks fuer das Uhrenbetriebssystem
 * @param taskId
 */
#ifndef TASKS_H_
#define TASKS_H_

/**
 *  Typ fuer Funktionspointer auf Tasks
 * @param taskId ID des Tasks
 */

typedef void (*Task)(int taskId);

/**
 * Gibt die uebergebene ID auf der Konsole aus
 * @param taskid Task ID
 */
void printID(int taskid);

/**
 * Gibt eine Begruessung aus
 * @param taskid Task ID
 */
void printHello(int taskid);

/**
 *  Gibt das Datum auf der Konsole aus
 * @param taskid Task ID
 */
void printDate(int taskid);

#endif /* TASKS_H_ */
