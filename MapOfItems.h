#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"
#include <vector>


using std::vector;

// TODO: your code goes here

class MapOfItems {

  private:
    vector<Item> tour;


  public:

    void addItem(Item item) {
      tour.push_back(item);
    }

    int size() {
      return tour.size();
    }


   vector<Item> getTour(double walkSpeed) {
     double currentTime = 0;
     double walkTime = 0;

     vector<Item> visitedItems;
     vector<Item> tempVect = tour;
     Item currentItem = tour[0];
     int currentPos = 0;

     double firstAvailable = 3600;
     for (int i=0; i<size(); i++) {
       if (tour[i].getSecsPastHour() < firstAvailable) {
         firstAvailable = tour[i].getSecsPastHour();
         currentItem = tour[i];
         currentPos = i;
       }
     }

     visitedItems.push_back(tour[currentPos]);
     tempVect.erase(tempVect.begin() + currentPos);
  //   cout << "Start while loop" << endl;

     while (currentTime < 3600 && tempVect.size() > 0) {

      vector<double> visit;

    //  cout << "first for loop" << endl;
      for (int i=0; i<tempVect.size(); i++) {
        double visitI = 0;
        walkTime = currentItem.distanceTo(tempVect[i]) / walkSpeed;
        visitI = walkTime + currentTime;

        if (visitI < tempVect[i].getSecsPastHour()) {
          visitI = tempVect[i].getSecsPastHour();
        } else if (visitI > (tempVect[i].getSecsPastHour() + 15 * 60 )) {
          visitI = 99999;
        }

        visit.push_back(visitI);

      }

    //  cout << "second for loop" << endl;
      double minVisit = visit[0];
      for (int i=0; i<visit.size(); i++) {

        if (visit[i] <= minVisit)   {
          minVisit = visit[i];
          currentItem = tempVect[i];
          currentPos = i;
        }

      }

      if (minVisit < 3600) {
        visitedItems.push_back(tempVect[currentPos]);
        tempVect.erase(tempVect.begin() + currentPos);
      }
      currentTime = minVisit;
     }
    // cout << "End while loop" << endl;
     return visitedItems;

   }


};






// don't write any code below this line

#endif
