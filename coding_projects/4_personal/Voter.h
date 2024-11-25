#ifndef _H_Voter_
#define _H_Voter_

#include <iostream>
#include <stdlib.h>
using namespace std;

class Voter {
   private:
      string first;
      string last;
      unsigned int age;
      double likelihood;
      double strength;
      double impact;
      bool voted;
      int position;

   public:
      Voter* next;
      Voter* prev;
      Voter* left;
      Voter* right;
      Voter(string firstname, string lastname, unsigned int voterage);
      Voter();
      Voter(const Voter& origObject);
      void show();
      void name();
      void show_full();
      void vote();
      bool get_voted();
      bool operator==(const Voter& other) const;
      bool operator!=(const Voter& other) const;
      bool operator<(const Voter& other) const;
      bool impactCompare(const Voter& other);
      bool ageCompare(const Voter& other);
      void updateImpact();
      void updateStrength(double strength);
      void updateLikelihood(double likelihood);
      int get_position();
      void set_position(int pos);
      friend std::ostream& operator<<(std::ostream& os, const Voter& voter);
};

#endif
