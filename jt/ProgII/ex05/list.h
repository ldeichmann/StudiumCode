/** @file
 * Verwaltung von Arrays von Zeichenketten fuer Playlisten.
 *
 *  @date 27.05.2014
 *  @author: ansch
 */

#ifndef LIST_H_
#define LIST_H_

/**
 * Fuegt ein Element item der Liste hinzu sofern noch freie Eintraege in der Liste
 * existieren. Die Liste wird durch ein Array von Zeichenketten implementiert.
 * Die Funktion alloziert auf dem Heap Speicherplatz fuer die einzufuegende Zeichenkette,
 * kopiert die uebergebene Zeichenkette in den allozierten Speicherbereich mit
 * strcpy und fuegt einen Zeiger auf diesen Speicherplatz in das erste freie Feld
 * der uebergebenen Liste ein. Die Funktion erhoeht den als Referenz uebergebenen Counter um 1
 * falls die Zeichenkette eingefuegt werden konnte.
 * @param list Array in das die Zeichenkette eingefuegt werden soll.
 * @param item Einzufuegendes Element
 * @param count Referenz auf die Anzahl der in der Liste gespeicherten Elemente. Der Wert wird
 * von der Funktion entsprechend angepasst.
 * @param capacity Groesse des Arrays
 * @return 1 falls das Element eingefuegt werden konnte und 0 sonst (etwa falls das
 * Array bereits voll war)
 */

int listadditem(char** list, char* item, int* count, int capacity);

/**
 *  Findet das erste Vorkommen eines Elements in der Liste. Dazu vergleicht die Funktion mit strcmp
 *  jeden Listeneintrag mit der uebergebenen Zeichenkette. Die Funktion liefert den ersten
 *  Index einer Uebereinstimmung. Falls die uebergebene Zeichenkette nicht in der Liste
 *  enthalten ist, liefert die Funktion -1.
 * @param list Array von Zeichenketten in dem item gesucht werden soll
 * @param item Zu suchende Zeichenkette
 * @param count Anzahl der in dem Array gespeicherten Zeichenketten
 * @return Index von item in dem Array list falls item in list enthalten ist und -1 sonst.
 */

int listfinditem(char** list, char* item, int count);

/**
 * Loescht ein Element aus der Liste. Alle nachfolgenden Elemente werden um 1 nach vorne
 * verschoben. Die Funktion gibt beim Einfuegen eines Elements allozierten Speicher
 * fuer die Zeichenkette wieder frei.
 * @param list Liste aus der das Element geloescht werden soll.
 * @param item Zu loeschendes Element
 * @param count Referenz auf die Anzahl der in der Liste gespeicherten Elemente. Die
 * Funktion passt diesen Wert entsprechend an.
 * @return 1 falls das Element geloescht werden konnte und 0 sonst
 */
int listdeleteitem(char** list, char* item, int* count);


/**
 * Gibt ein Array von Zeichenketten auf der Konsole aus.
 * @param list Auszugebendes Array.
 * @param count Anzahl der im Array gespeicherten Zeichenketten.
 */
void listprint(char** list, int count);

/**
 * Loescht alle Eintraege in der Liste und gibt des fuer die Eintraege allozierten Speicher frei.
 * Die Funktion gibt nicht den Speicher fuer die Liste selbst frei.
 *
 * @param list Zu loeschendes Array.
 * @param count Anzahl der Eintraege im Array.
 */
void listfreeallitems(char** list, int count);

#endif /* LIST_H_ */
