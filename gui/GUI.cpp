//
// Created by Kuba on 29/04/2024.
//

#include "GUI.h"

void GUI::gui() {
    while (true){
        mainMenu();
    }
}

void GUI::mainMenu() {
    cout << "1. Przetestuj algorytm Prima" << endl;
    cout << "2. Przetestuj algorytm Kruskala" << endl;
    cout << "3. Przetestuj algorytm Djikstry" << endl;
    cout << "4. Przetestuj algorytm Forda-Bellmana" << endl;
    cout << "5. Testuj wsyztsko" << endl;

    int option;
    cin >> option;

    if(option == 5){
        testALL();
        return;
    }

    cout << endl;
    cout << endl;

    cout << "1. Wygeneruj graf" << endl;
    cout << "2. Wczytaj graf z pliku" << endl;

    int option2;
    cin >> option2;

    cout << endl;
    cout << endl;

    cout << "1. Macierz incydencji" << endl;
    cout << "2. Lista sąsiedztwa" << endl;

    int option3;
    cin >> option3;

    bool directed = true;
    if(option < 3) directed = false;

    Generator g = Generator(0);
    if(option2 == 1){
        cout << "Podaj liczbę wierzchołków" << endl;
        int nodes;
        cin >> nodes;
        g = Generator(nodes);
        cout << "Podaj gestosc grafu (liczba 1 - 99)" << endl;
        int destiny;
        cin >> destiny;
        g.generate(destiny);
    }
    IncidentMatrixGraf incidentMatrix = IncidentMatrixGraf();
    NeighborhoodList neigborList = NeighborhoodList();

    switch (option3) {
        case 1:
            if(option2 == 1){
                incidentMatrix.loadFromGenerator(g,directed);
            } else{
                cout << "Podaj nazwe pliku z ktorego chcesz wczytac graf " << endl;
                string s;
                cin >> s;
                incidentMatrix.load_matrix(s,directed);
            }
            break;
        case 2:
            if(option2 == 1){
                neigborList.loadFromGenerator(g,directed);
            } else{
                cout << "Podaj nazwe pliku z ktorego chcesz wczytac graf " << endl;
                string s;
                cin >> s;
                neigborList.load(s,directed);
            }
            break;
    }

    switch (option) {
        case 1:
            if(option3 == 1){
                MstIncidentMatrixPrimAlgorithm mst1 = MstIncidentMatrixPrimAlgorithm();
                mst1.findMST(incidentMatrix.matrix);
            } else{
                MstNeighborhoodListPrimAlgorithm mst2 = MstNeighborhoodListPrimAlgorithm();
                mst2.findMST(neigborList.matrix);
            }
            break;
        case 2:
            if(option3 == 1){
                Kruskal* k = new KruskalIncidentMatrix(incidentMatrix.matrix);
                k->kruskal(k->getEdgesAmount());
            } else{
                Kruskal* k2 = new KruskalNeighborhoodMatrix(neigborList.matrix);
                k2->kruskal(k2->getEdgesAmount());
            }
            break;
        case 3:
            if(option3 == 1){
                DjikstraIncidentMatrix d2 = DjikstraIncidentMatrix(incidentMatrix.matrix);
                vector<vector<int> > output = d2.testDjikstra();
                for(int y = 0; y < output.size(); y++){
                    for(int x = 0; x < output[y].size(); x++){
                        if(output[y][x] != numeric_limits<int>::max() ){
                            cout << y << " -> " << x << ": " << output[y][x] << endl;
                        } else
                        {
                            cout << y << " -> " << x << ": brak sciezki" << endl;
                        }
                    }
                    cout << endl;
                    cout << endl;
                }
                cout << endl;
            } else{
                DjikstraNeighborList d = DjikstraNeighborList(neigborList.matrix);
                vector<vector<int> > output = d.testDjikstra();
                for(int y = 0; y < output.size(); y++){
                    for(int x = 0; x < output[y].size(); x++){
                        if(output[y][x] != numeric_limits<int>::max() ){
                            cout << y << " -> " << x << ": " << output[y][x] << endl;
                        } else
                        {
                            cout << y << " -> " << x << ": brak sciezki" << endl;
                        }
                    }
                    cout << endl;
                    cout << endl;
                }
                cout << endl;
            }
            break;
        case 4:
            if(option3 == 1){
                BellmanFordIncidentMatrix b2 = BellmanFordIncidentMatrix(incidentMatrix.matrix);
                vector<vector<int> >output = b2.testBellman();
                for(int y = 0; y < output.size(); y++){
                    for(int x = 0; x < output[y].size(); x++){
                        if(output[y][x] != numeric_limits<int>::max() ){
                            cout << y << " -> " << x << ": " << output[y][x] << endl;
                        } else
                        {
                            cout << y << " -> " << x << ": brak sciezki" << endl;
                        }
                    }
                    cout << endl;
                    cout << endl;
                }
                cout << endl;
            } else{
                BellmanFordNeighborList b = BellmanFordNeighborList(neigborList.matrix);
                vector<vector<int>> output = b.testBellman();
                for(int y = 0; y < output.size(); y++){
                    for(int x = 0; x < output[y].size(); x++){
                        if(output[y][x] != numeric_limits<int>::max() ){
                            cout << y << " -> " << x << ": " << output[y][x] << endl;
                        } else
                        {
                            cout << y << " -> " << x << ": brak sciezki" << endl;
                        }
                    }
                    cout << endl;
                    cout << endl;
                }
                cout << endl;
            }
            break;
        case 5:
            testALL();
            break;
    }

}

void GUI::testALL() {

    ofstream outputFile("data/dataFiles/output.txt");

    vector<int> nodess = vector<int>({50,60,70,80,90,100,110,120});
    vector<int> gestosc = vector<int>({25,50,99});
    for(int y =0; y < gestosc.size(); y++){
        vector<double> avgresults = vector<double>();
        avgresults.resize(8,0);
        for(int x = 0; x < nodess.size(); x++ ){
            for(int z = 0; z <20; z++){
                //nodes
                //gestosc
                //Lista sąsiedztwa - Prim
                //Lista sasiedztwa - Kruskal
                //Lista sąsiedztwa - djikstra
                //Lista sąsiedztwa - Bellman
                //Lista incydencji - Prim
                //Lista incydencji - Kruskal
                //Lista incydencji - djikstra
                //Lista incydencji - Bellman
                Generator g = Generator(nodess[x]);
                g.generate(gestosc[y]);
                NeighborhoodList n = NeighborhoodList();
                n.loadFromGenerator(g, false);

                IncidentMatrixGraf m = IncidentMatrixGraf();
                m.loadFromGenerator(g, false);

                MstNeighborhoodListPrimAlgorithm nn = MstNeighborhoodListPrimAlgorithm();
                auto start = std::chrono::high_resolution_clock::now();
                nn.findMST(n.matrix);
                auto end = std::chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> duration = end - start;
                avgresults[0] += duration.count();


                Kruskal* k2 = new KruskalNeighborhoodMatrix(n.matrix);
                start = std::chrono::high_resolution_clock::now();
                k2->kruskal(k2->getEdgesAmount());
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[1] += duration.count();

                n.loadFromGenerator(g, false);

                DjikstraNeighborList d = DjikstraNeighborList(n.matrix);
                start = std::chrono::high_resolution_clock::now();
                d.testDjikstra();
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[2] += duration.count();

                BellmanFordNeighborList b = BellmanFordNeighborList(n.matrix);
                start = std::chrono::high_resolution_clock::now();
                b.testBellman();
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[3] += duration.count();

                MstIncidentMatrixPrimAlgorithm nn2 = MstIncidentMatrixPrimAlgorithm();
                start = std::chrono::high_resolution_clock::now();
                nn2.findMST(m.matrix);
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[4] += duration.count();

                Kruskal* k = new KruskalIncidentMatrix(m.matrix);
                start = std::chrono::high_resolution_clock::now();
                k->kruskal(k->getEdgesAmount());
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[5] += duration.count();

                m.loadFromGenerator(g, true);

                DjikstraIncidentMatrix d2 = DjikstraIncidentMatrix(m.matrix);
                start = std::chrono::high_resolution_clock::now();
                d2.testDjikstra();
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[6] += duration.count();

                BellmanFordIncidentMatrix b2 = BellmanFordIncidentMatrix(m.matrix);
                start = std::chrono::high_resolution_clock::now();
                b.testBellman();
                end = std::chrono::high_resolution_clock::now();
                duration = end - start;
                avgresults[7] += duration.count();

                cout << z << endl;
            }
            outputFile << gestosc[y] << ";" << nodess[x] << ";";
            for(int z = 0; z < avgresults.size(); z++){
                outputFile << avgresults[z]/20 << ";";
            }
            outputFile << endl;

        }
    }
}