#include "gvsu_cis.h"
#include "hw311_single_linked_list.hpp"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

TEST_CASE ("Linked list of string") {
    single_linked_list<string> names;

    SECTION ("Empty list") {
        stringstream os;

        REQUIRE (names.size() == 0);
        REQUIRE_FALSE (names.is_contained("anything"));
        names.print(os);
        REQUIRE (os.str().length() == 0);
        REQUIRE (os.str() == "");
    }

    SECTION ("One item") {
        stringstream os;

        names.addItem("Jupiter");
        REQUIRE (names.is_contained("Jupiter") == true);
        REQUIRE (names.size() == 1);

        names.print(os);
        REQUIRE (os.str().length() > 0);
        REQUIRE (os.str().find("Jupiter") == 0);
    }

    SECTION ("Two items") {
        stringstream os;

        names.addItem("Jupiter");
        names.addItem("Mars");
        REQUIRE (names.size() == 2);
        names.print(os);
        string out = os.str();
        REQUIRE (out.rfind("Mars") != string::npos);
        REQUIRE (out.rfind("Mars") == out.length() - 5);
    }

    SECTION ("Remove") {
        vector<string> planets{"Mars", "Venus", "Uranus", "Saturn",
                               "Jupiter", "Earth"};
        for (auto p : planets) {
            names.addItem(p);
        }

        REQUIRE (names.size() == planets.size());
        for (auto p : planets) {
            REQUIRE (names.is_contained(p));
            REQUIRE_FALSE (names.is_contained("X" + p));
        }
        for (auto p : planets) {
            names.remove(p);
            REQUIRE_FALSE (names.is_contained(p));
        }
    }

    SECTION ("Print") {
        vector<string> planets{"Mars", "Venus", "Uranus", "Saturn",
                               "Jupiter", "Earth"};
        vector<int> positions(planets.size());
        for (auto p : planets) {
            names.addItem(p);
        }
        stringstream out;
        names.print(out);
        for (int k = 0; k < planets.size(); k++) {
            int pos = out.str().find(planets[k]);
            positions[k] = pos;
        }
        for (int k = 1; k < positions.size(); k++)
            REQUIRE (positions[k] > positions[k - 1]);
    }

    SECTION ("Print Reverse") {
        vector<string> planets{"Mars", "Venus", "Uranus", "Saturn",
                               "Jupiter", "Earth"};
        vector<int> positions(planets.size());
        for (auto p : planets) {
            names.addItem(p);
        }
        stringstream out;
        names.print_reverse(out);
        for (int k = 0; k < planets.size(); k++) {
            int pos = out.str().find(planets[k]);
            positions[k] = pos;
        }
        for (int k = 1; k < positions.size(); k++)
            REQUIRE (positions[k] < positions[k - 1]);
    }
}

TEST_CASE ("Remove must delete node") {
    single_linked_list<int> numbers;

    REQUIRE (numbers.size() == 0);
    for (int k = 0; k < 100; k++)
        numbers.addItem(k + 1);
    REQUIRE (numbers.size() == 100);
    for (int k = 0; k < 100; k++)
        numbers.remove(k + 1);
    REQUIRE (numbers.size() == 0);

    auto memoryCount = GVSU_Allocator<int>::allocation_status();
    if (memoryCount.first != memoryCount.second)
        FAIL ("Be sure to call delete to dispose node in your remove()");
}

TEST_CASE ("Destructor") {
    single_linked_list<int> *numbers;

    numbers = new single_linked_list<int>;
    REQUIRE (numbers->size() == 0);
    for (int k = 0; k < 100; k++)
        numbers->addItem(k + 1);
    REQUIRE (numbers->size() == 100);
    delete numbers;

    auto memoryCount = GVSU_Allocator<int>::allocation_status();
    if (memoryCount.first != memoryCount.second)
        FAIL ("Incorrect implementation of destructor");
}
