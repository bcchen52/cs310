#include "RegisterVoter.h"

RegisterVoter::RegisterVoter(){
    root = nullptr;
}

bool RegisterVoter::voter(string first, string last, int age){
    //Add to BST, check if it exists
    Voter* v = new Voter(first, last, age);
    Voter* curr = root;

    //add to each thing and reorganize
    if(root == nullptr){
        root = v;
        ivector.push_back(v);
        avector.push_back(v);
        return true;
    } else { // check if we need to 
        //search + insert BST
        while(curr != nullptr){
            if(curr == v){
                cout << "Voter ";
                curr->show();
                cout << ", already exists.";
                return false;
            }
            else if(v<curr){
                if(curr->prev == nullptr){
                    curr->prev = v;
                    curr = nullptr;
                } else {
                    curr = curr->prev;
                }
            } else { // v>curr
                if(curr->next == nullptr){
                    curr->next = v;
                    curr = nullptr;
                } else {
                    curr = curr->next;
                }
            }
        } 
    }

    //if we are here, we are assuming that a match was NOT found in the BST, thus valid

    //add to age, just insert
    //add to heap, we need to percolate up

    //insert into age
    bool inserted = false;
    for(int i = 0; i<avector.size();i++){
        if(curr<ivector[i]){
            if(i == 0){
                avector.insert(avector.begin() + i, curr);
                inserted = true;
                break;
            } else {
                if(!(curr<ivector[i-1])){
                    avector.insert(avector.begin() + i, curr);
                    inserted = true;
                    break;
                }
            }
        }
    }

    if(!inserted){
        avector.push_back(curr);
    }

    //insert into impact vector
    ivector.push_back(curr);
    percolate_down(curr, ivector.size());

    //good message
    cout << "New voter ";
    curr->show();
    cout << ", added.";
    return true;
};

void RegisterVoter::voted(string first, string last, int age){
    //voted
    Voter* v = new Voter(first, last, age);

    Voter* curr = bst_search(v);

    delete v;

    curr->vote();

    cout << "Voter ";
    curr->show();
    cout << " voted.";
};

void RegisterVoter::reduce_likelihood(string first, string last, int age, double change){
    //reducing likelihood decreases impact, percolte down
    Voter* v = new Voter(first, last, age);

    Voter* curr = bst_search(v);

    delete v;

    if(!(curr->get_voted())){
        curr->updateLikelihood(change);
        percolate_down(curr, ivector.size());
        //print message
        cout << "reduced" << endl;
    } else {
        //print message that it alr happened
        cout << "alr voted" << endl;
    }
};

void RegisterVoter::support(string first, string last, int age, double change){
    //increase support increases likelhood, perolate up
    Voter* v = new Voter(first, last, age);

    Voter* curr = bst_search(v);

    delete v;

    if(!(curr->get_voted())){
        curr->updateStrength(change);
        percolate_up(curr, ivector.size());
        //print message

        cout << "Support from ";
        curr->name();
        cout << " increase by " << change << " strength points.";
    } else {
        //print message that it alr happened
        curr->name();
        cout << " already voted";
    }
};

void RegisterVoter::chauffeur(){
    bool chauffered = false;
    Voter* curr;
    Voter* voting;

    //LOOP THISSSS IF NOT VOTED
    while(!chauffered){
        voting = ivector[0];
        chauffered = voting->get_voted();

        voting->vote();

        curr = ivector[ivector.size()-1];
        curr->set_position(0);
        ivector[0] = curr;

        ivector.pop_back();
        //pop off voted

        //percolate down()
        percolate_down(curr, ivector.size());
    }


    //print voter
    cout << "Driving ";
    voting->show_full();
    cout << endl;
};

void RegisterVoter::show_impact(){
    //loop thru vector
    for(int i=0;i<avector.size();i++){
        avector[i]->show_full();
        cout << endl;
    }
};

bool RegisterVoter::swap_up(int current_index, int max){
    if(current_index > 0){
        Voter* child = ivector[current_index];
        Voter* parent = ivector[(current_index-1)/2];
        //if swapped and it has a child, return true if it has a child
        //use max and index

        if(parent->impactCompare(*child)){
            //if parent impact(Compare) child => parent < Child
            //change positions
            child->set_position(parent->get_position());
            parent->set_position(current_index);
            //change in vector
            ivector[child->get_position()] = child;
            ivector[parent->get_position()] = parent;
            return false;
        }
    }
    return true;
}

bool RegisterVoter::swap_down(int current_index, int max){
    int swap_with = 0;
    //change positionsss
    Voter* parent = ivector[current_index];
    if((current_index * 2) < max-1){ //guarantees first child
        Voter* child1 = ivector[current_index*2 + 1];

        if((current_index * 2) < max){ //second child exists
            Voter* child2 = ivector[current_index*2 + 2];
            if(parent->impactCompare(*child1)){
                if(parent->impactCompare(*child2)){
                    //if child 1 < child 2
                    if(!(child2->impactCompare(*child1))){
                        swap_with = 2;
                    } else {
                        swap_with = 1;
                    }
                    //compare?
                } else {
                    swap_with = 1;
                }
            } else if (parent->impactCompare(*child2)){
                swap_with = 2;
            }
        } else {
            if(parent->impactCompare(*child1)){
                swap_with = 1;
            }
        }
    }

    if(swap_with>0){
        Voter* curr;
        if(swap_with == 1){
            curr = ivector[current_index*2 + 1];
        } else {
            curr = ivector[current_index*2 + 2];
        }
        parent->set_position(curr->get_position());
        curr->set_position(current_index);
        //change in vector
        ivector[curr->get_position()] = curr;
        ivector[parent->get_position()] = parent;
        return false;
    }
    return true;
}

void RegisterVoter::percolate_down(Voter* curr, int max){
    bool valid = false;
    int current_pos = 0;

    while(!valid){
        valid = swap_down(current_pos, max);
        current_pos = curr->get_position();
    }
}

void RegisterVoter::percolate_up(Voter* curr, int max){
    bool valid = false;
    int current_pos = 0;

    while(!valid){
        valid = swap_up(current_pos, max);
        current_pos = curr->get_position();
    }
}

Voter* RegisterVoter::bst_search(Voter* v){
    Voter* curr = root;
    while(curr != nullptr){
        if(curr == v){
            return curr;
        }
        else if(v<curr){
            if(curr->prev == nullptr){
                return nullptr;
            } else {
                curr = curr->prev;
            }
        } else { // v>curr
            if(curr->next == nullptr){
                return nullptr;
            } else {
                curr = curr->next;
            }
        }
    } 
    return nullptr;
}