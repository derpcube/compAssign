/*
2/28/2023

A multi-file project in with a templated linked list which is used to create a
simple list of composers
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Composers.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    LinkedList<Composer> composers;
    ifstream inFile("composers.txt");
    char input;
    string name;
    Composer newComposer;

    if (inFile) {
        string line;

        while (getline(inFile, line)) {
            size_t commaPos = line.find(',');

            if (commaPos != string::npos) {
                string name = line.substr(0, commaPos);
                int year = stoi(line.substr(commaPos + 2));
                composers.append(Composer(name, year));
            }
        }

        composers.sortByDate();

        cout << "Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to "
            "exit: ";
        cin >> input;
        cin.ignore();

        while (input != 'e') {
            switch (input) {
            case 's':
                cout << "Enter a composer's name to search for: ";

                getline(cin, name);
                newComposer.setName(name);

                if (composers.find(newComposer)) {
                    cout << "\n"
                        << "\t" << newComposer.getName()
                        << " was found in the list\n\n";
                }
                else {
                    cout << "\n"
                        << "\t" << newComposer.getName()
                        << " was not found in the list\n\n";
                }

                break;

            case 'r':
                cout << "Enter a composer's name to remove: ";

                getline(cin, name);
                newComposer.setName(name);

                if (composers.remove(newComposer)) {
                    cout << "\n"
                        << "\t" << newComposer.getName()
                        << " was successfully removed from the list\n\n";
                }
                else {
                    cout << "\n"
                        << "\t" << newComposer.getName()
                        << " was not found in the list when attempting to "
                        "remove\n\n";
                }

                break;

            case 'd':
                cout << "\n ";

                composers.printList();

                break;
            case 'e':
                break;
            }

            cout << "Enter 's' to search, 'r' to remove, 'd' to display, or "
                "'e' to exit: ";
            cin >> input;
            cin.ignore();
        }

        inFile.close();
    }
    else {
        cout << "Cannot open file.\n";
    }

    return 0;
}

/*
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

 Claudio Monteverdi, 1643
 Henry Purcell, 1695
 Antonio Vivaldi, 1741
 Johann Sebastian Bach, 1750
 George Frideric Handel, 1759
 Wolfgang Amadeus Mozart, 1791
 Joseph Haydn, 1809
 Ludwig van Beethoven, 1827
 Franz Schubert, 1828
 Felix Mendelssohn, 1847
 Frederic Chopin, 1849
 Robert Schumann, 1856
 Hector Berlioz, 1869
 Richard Wagner, 1883
 Franz Liszt, 1886
 Pyotr Ilyich Tchaikovsky, 1893
 Johannes Brahms, 1897
 Giuseppe Verdi, 1901
 Antonin Dvorak, 1904
 Edvard Grieg, 1907
 Gustav Mahler, 1911
 Claude Debussy, 1918
 Camille Saint-Saens, 1921
 Giacomo Puccini, 1924
 Maurice Ravel, 1937
 George Gershwin, 1937
 Sergei Rachmaninoff, 1943
 Bela Bartok, 1945
 Arnold Schoenberg, 1951
 Sergei Prokofiev, 1953
 Igor Stravinsky, 1971
 Dmitri Shostakovich, 1975
 Aaron Copland, 1990
 Leonard Bernstein, 1990

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Franz Liszt

                Franz Liszt was found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Hanz Zimmer

                Hanz Zimmer was not found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: Camille Saint-Saens

                Camille Saint-Saens was successfully removed from the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: CPE Bach

                CPE Bach was not found in the list when attempting to remove

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

 Claudio Monteverdi, 1643
 Henry Purcell, 1695
 Antonio Vivaldi, 1741
 Johann Sebastian Bach, 1750
 George Frideric Handel, 1759
 Wolfgang Amadeus Mozart, 1791
 Joseph Haydn, 1809
 Ludwig van Beethoven, 1827
 Franz Schubert, 1828
 Felix Mendelssohn, 1847
 Frederic Chopin, 1849
 Robert Schumann, 1856
 Hector Berlioz, 1869
 Richard Wagner, 1883
 Franz Liszt, 1886
 Pyotr Ilyich Tchaikovsky, 1893
 Johannes Brahms, 1897
 Giuseppe Verdi, 1901
 Antonin Dvorak, 1904
 Edvard Grieg, 1907
 Gustav Mahler, 1911
 Claude Debussy, 1918
 Giacomo Puccini, 1924
 Maurice Ravel, 1937
 George Gershwin, 1937
 Sergei Rachmaninoff, 1943
 Bela Bartok, 1945
 Arnold Schoenberg, 1951
 Sergei Prokofiev, 1953
 Igor Stravinsky, 1971
 Dmitri Shostakovich, 1975
 Aaron Copland, 1990
 Leonard Bernstein, 1990

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e
Press any key to close this window . . .
*/