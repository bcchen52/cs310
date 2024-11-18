#ifndef _H_RegisterVoter_
#define _H_RegisterVoter_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath> 

#include "Voter.h"

using namespace std;

class RegisterVoter {
    private:
        vector<Voter*> ivector;
        vector<Voter*> avector;
        Voter* root;

    public:
        RegisterVoter();
        bool voter(string first, string last, int age); //return if sucessfully added
        void voted(string first, string last, int age);
        void reduce_likelihood(string first, string last, int age, double change);
        void support(string first, string last, int age, double change);
        void chauffeur();
        void show_impact();
        bool swap_down(int current_index, int max);
        bool swap_up(int current_index, int max);
        void percolate_down(Voter* curr, int max);
        void percolate_up(Voter* curr, int max);
        Voter* bst_search(Voter* v);
};

#endif