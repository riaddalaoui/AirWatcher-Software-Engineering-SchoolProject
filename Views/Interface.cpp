#include <iostream>
#include "Interface.h"
#include "../Services/Services.h"
#include "../util/Date.h"
#include <vector>
#include <chrono>
#include <sstream>
#include <string>
using namespace std::chrono;

void Interface::afficherResultatAnalyse() {
    std::cout << "Service non-implémenté\n";
}

void Interface::afficherRanking() {
    std::cout << "Service non-implémenté\n";
}

void Interface::afficherAQIMoment() {
    std::cout << "Service non-implémenté\n";
}

void Interface::afficherAQIPeriode() {
    std::cout << "AfficherAQIPeriode\n";

    float latitude, longitude;
    int radius;
    int day, month, year;
    string start, end;
    std::cout<<"Entrez la latitude: ";
    std::cin >> latitude;
    std::cout<<"Entrez la longitude: ";
    std::cin >> longitude;
    std::cout<<"Entrez le rayon: ";
    std::cin >> radius;
    std::cout<<"Entrez la date de début: dd/mm/yyyy\n";
    std::cin >> start;

    std::istringstream dateStream(start);
    std::string segment;

    std::getline(dateStream, segment, '/');
    day = std::stoi(segment);

    std::getline(dateStream, segment, '/');
    month = std::stoi(segment);

    std::getline(dateStream, segment);
    year = std::stoi(segment);

    Date startDate(year, month, day);

    cout<<"Entrez la date de fin: dd/mm/yyyy\n";
    cin >> end;

    std::istringstream dateStream2(end);
    std::string segment2;

    std::getline(dateStream2, segment2, '/');
    day = std::stoi(segment2);

    std::getline(dateStream2, segment2, '/');
    month = std::stoi(segment2);

    std::getline(dateStream2, segment2);
    year = std::stoi(segment2);

    Date endDate(year, month, day);
    
    auto start_time = std::chrono::high_resolution_clock::now();

    // Appel du service
    Services service;
    int functionReturn = service.computeAQIPeriod(latitude, longitude, radius, startDate, endDate);
    functionReturn > 0 ? std::cout << "AQI moyen = " << functionReturn : std::cout << "Erreur";
    auto end_time = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); 

    std::cout << std::endl << "Temps d'exécution = " << duration.count() << " ms\n";
}

void Interface::afficherAmelioration() {
    std::cout << "Service non-implémenté\n";
}

void Interface::afficherZoneEffective() {
    std::cout << "AfficherZoneEffective\n";

    string cleanerID;

    std::cout<<"Entrez l'identifiant du cleaner à analyser \n";
    std::cin >> cleanerID;

    auto start_time = std::chrono::high_resolution_clock::now(); 

    // Appel du service
    Services service;
    service.measureAreaEffect(cleanerID); 
    auto end_time = std::chrono::high_resolution_clock::now(); // Renamed to end_time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); 

    std::cout << "Temps d'exécution = " << duration.count() << " ms\n";

}

void Interface::afficherAQIPoint() {
    std::cout << "Service non-implémenté\n";
}

void Interface::afficherTests() {
    int passed = 0;
    int total = 0;
    float result_computeAQIPeriod;
    Services service;

    // Test 1
    std::cout << "__________________________________________________________\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Test 1 : computeAQIPeriod(latitude, longitude, radius, startDate, endDate)\n";
    std::cout << "but : S'assurer que le service calcule avec précision la moyenne de l'IQA dans un cercle spécifié.\n";
    std::cout << "inputs : 44, 0, 2, 0, 2019-01-01 11:30:26, 2019-01-02 14:00:10\n";
    std::cout << "résultat attendu : 7,83 ± 0.01\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Déroulement du service...\n";
    result_computeAQIPeriod = service.computeAQIPeriod(44, 0, 2,Date(2019,01,01, 11,30,26), Date(2019,01,02, 14,00,10));
    std::cout << "__________________________________________________________\n";
    std::cout << "résultat obtenu : " << result_computeAQIPeriod << "\n";
    if (result_computeAQIPeriod > 7.82 && result_computeAQIPeriod < 7.84) {
        std::cout << "Test 1 réussi\n";
        passed++;
    } else {
        std::cout << "Test 1 échoué\n";
    }
    total++;
    std::cout << "__________________________________________________________\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Test 2 : computeAQIPeriod(latitude, longitude, radius, startDate, endDate)\n";
    std::cout << "but : Vérifier que le cas où aucun capteur n'est dans le cercle est traité\n";
    std::cout << "inputs : 0, 0, 1, 2019-01-01, 2019-01-02\n";
    std::cout << "résultat attendu : -1 ; 'No sensors found in the given radius.'\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Déroulement du service...\n";
    result_computeAQIPeriod = service.computeAQIPeriod(0, 0, 1, Date(2019, 1, 1), Date(2019, 1, 2));
    std::cout << "__________________________________________________________\n";
    std::cout << "résultat obtenu : " << result_computeAQIPeriod << "\n";
    if (result_computeAQIPeriod==-1) {
        std::cout << "Test 2 réussi\n";
        passed++;
    } else {
        std::cout << "Test 2 échoué\n";
    }
    total++;
    std::cout << "__________________________________________________________\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Test 3 : computeAQIPeriod(latitude, longitude, radius, startDate, endDate)\n";
    std::cout << "but : S'assurer de la gestion du cas où aucune mesure n'est trouvé dans la période donnée\n";
    std::cout << "inputs : 44, 0, 1, 2018-01-01, 2018-01-02\n";
    std::cout << "résultat attendu : -1 ; 'No measurements found in the given period.'\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Déroulement du service...\n";
    result_computeAQIPeriod = service.computeAQIPeriod(44, 0, 1, Date(2018, 1, 1), Date(2018, 1, 2));
    std::cout << "__________________________________________________________\n";
    std::cout << "résultat obtenu : " << result_computeAQIPeriod << "\n";
    if (result_computeAQIPeriod==-1) {
        std::cout << "Test 3 réussi\n";
        passed++;
    } else {
        std::cout << "Test 3 échoué\n";
    }
    total++;
    std::cout << "__________________________________________________________\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Test 4 : computeAQIPeriod(latitude, longitude, radius, startDate, endDate)\n";
    std::cout << "but : Vérifier qu'un rayon négatif donne une erreur \n";
    std::cout << "inputs : 44;0; -1; 2019-01-01; 2019-01-12\n";
    std::cout << "résultat attendu : -1 ; 'Invalid radius.'\n";
    std::cout << "__________________________________________________________\n";
    std::cout << "Déroulement du service...\n";
    result_computeAQIPeriod = service.computeAQIPeriod(44,0, -1,Date(2019,01,01), Date(2019,01,12));
    std::cout << "__________________________________________________________\n";
    std::cout << "résultat obtenu : " << result_computeAQIPeriod << "\n";
    if (result_computeAQIPeriod==-1) {
        std::cout << "Test 4 réussi\n";
        passed++;
    } else {
        std::cout << "Test 4 échoué\n";
    }
    total++;
    std::cout << "__________________________________________________________\n";
    std::cout << "__________________________________________________________\n\n\n";
    std::cout << "Nombre de tests réussis = " << passed << " sur "<< total << "\n";
}

int Interface::main() {
        
    int choice;

    do {
        // Display menu options


        std::cout << "Menu:\n";
        std::cout << "1. Analyser un capteur\n";
        std::cout << "2. Comparer un capteur à tous les autres et les classer par similarité\n";
        std::cout << "3. Calculer l'AQI à un moment dans une Zone\n";
        std::cout << "4. Calculer l'AQI sur une période dans une Zone\n";
        std::cout << "5. Calculer l'AQI à un moment à un endroit précis\n";
        std::cout << "6. Calculer l'amélioration de l'AQI d'un Cleaner\n";
        std::cout << "7. Calculer la zone d'efficacité d'un Cleaner\n";
        std::cout << "8. Lancer les tests\n";        
        std::cout << "9. Exit\n";
        std::cout << "votre choix: ";
        std::cin >> choice;

        // Process user's choice
        switch (choice) {
            case 1:
                // Code for option 1
                afficherResultatAnalyse();
                break;
            case 2:
                // Code for option 2
                afficherRanking();
                break;
            case 3:
                // Code for option 3
                afficherAQIMoment();
                break;
            case 4:
                afficherAQIPeriode();
                break;
            case 5:
                afficherAQIPoint();
                break;
            case 6:
                afficherAmelioration();
                break;
            case 7:
                afficherZoneEffective();
                break;
            case 8:
                // Code for option 8
                std::cout << "Lancement des tests...\n";
                afficherTests();
                break;
            case 9:
                // Exit the program
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "choix incorrect\n";
                break;
        }

        std::cout << "\n";
    } while (choice != 9);

    return 0;
}