#include <iostream>
using namespace std;
#include <string>
#include <cassert>

#include "Voter.h"
#include "RegisterVoter.h"

int main(){
    RegisterVoter voters = RegisterVoter();

    voters.voter("Mike", "Lewis", 15);
    return 0;
}