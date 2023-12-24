#include <iostream>
#include "Pet.h"
using namespace std;

void runUnitest1()
{
    Pet pets[2];

    pets[1] = Pet("ZaakenZluken", "sheepdog", 30, 40);
    pets[0].SetBreed("shpits");
    pets[0].SetName("Nastya");
    pets[0].SetHealth(100);
    pets[0].SetSaturation(100);


    for (int i = 0; i < 2; i++)
    {
        pets[i].InfoPet();
    }

    pets[0].FeedPet(50);
    pets[0].WalkPet(4);
    pets[0].WalkPet(3);
    pets[0].WalkPet();
    pets[0].FeedPet(50);

    pets[1].FeedPet(40);
    pets[1].FeedPet(40);
    pets[1].WalkPet(1);

    for (int i = 0; i < 2; i++)
    {
        pets[i].InfoPet();
    }
}

void unique_ptrTest() 
{
    unique_ptr<Pet> pet1 = make_unique<Pet>(
        "ZaakenZluken", "sheepdog", 30, 40);
    pet1->FeedPet(40);
    pet1->FeedPet(40);
    pet1->WalkPet(1);
    cout << endl;

    unique_ptr<Pet> pet2 = make_unique<Pet>();
    pet2->FeedPet(10);
}

void shared_ptrTest() 
{
    Pet* pet = new Pet("Shpits", "Nastya", 100, 100);
    shared_ptr<Pet> pet1(pet);
    {
        shared_ptr<Pet> pet2(pet1);
        shared_ptr<Pet> pet3(pet1);
        cout << "Count: " << pet1.use_count() << endl;
    }
    cout << "Count: " << pet1.use_count() << endl;
}

void weak_ptrTest()
{
    Pet* pet = new Pet("Shpits", "Nastya", 100, 100);
    shared_ptr<Pet> pet_shared(pet);
    weak_ptr<Pet> pet_weak(pet_shared);
    {
        weak_ptr<Pet> pet2(pet_shared);
        weak_ptr<Pet> pet3(pet_shared);
        cout << "Count: " << pet_shared.use_count() << endl;

        shared_ptr<Pet> pet_shared_orig = pet2.lock();
        pet_shared_orig->WalkPet(6);
        pet_shared_orig->FeedPet(15);

        cout << "Count: " << pet_shared.use_count() << endl;
    }
    cout << "Count: " << pet_shared.use_count() << endl;
} 


int main()
{
    setlocale(0, "");
}
