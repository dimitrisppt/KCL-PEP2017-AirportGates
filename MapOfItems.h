#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"
#include <vector>
#include <cmath>

using std::vector;


// TODO: your code goes here

class MapOfItems {

  private:
    vector<Item> tour;
    int tourTime = 0;


  public:

    void addItem(Item item) {
      tour.push_back(item);
    }

    int size() {
      return tour.size();
    }

    Item getItemTour(int i) {
      return tour.at(i);
    }


  //   vector<Item> getTour(double walkSpeed) {
  //     double walkTime;
  //     double visitI;
  //     vector<Item> visitedItems;
  //
  //
  //     for (int i=0; i<size()-1; i++) {
  //       for (int j=0; j<3600; j++) {
  //
  //       if (i == getItemTour(i).getSecsPastHour()) {
  //         walkTime = getItemTour(i).distanceTo(getItemTour(i+1)) / walkSpeed;
  //         visitI = walkTime + i;
  //         cout << i << "\n";
  //         cout << "\n";
  //         cout << "Visit I: " << visitI << "\n";
  //
  //         if (visitI > 15 * 60) {
  //           while ( visitI == i) {
  //             ++visitI;
  //
  //           }
  //         }
  //         if (visitedItems[i].getSecsPastHour() > visitI) {
  //           visitedItems.push_back(getItemTour(i));
  //         }
  //       }
  //
  //     }
  //
  //   }
  //   return visitedItems;
  // }

  //   vector<Item> getTour(double walkSpeed) {
  //     double currentTime = 0;
  //     double walkTime = 0;
  //     double visitI = 0;
  //     double minVisit = 999999999;
  //     vector<Item> tourItems;
  //     vector<Item> tempVect = tour;
  //
  //     while (currentTime < 3600) {
  //
  //       for (int i=0; i<tour.size()-1; i++) {
  //
  //         for (int j=i+1; j<tour.size(); j++) {
  //         //for (int j=i; i<j; j++) {
  //         // cout << "Tour time: " << currentTime <<"\n";
  //         // cout << "Element time: " << tour[i].getSecsPastHour() << "\n";
  //         //  if (i == 0 || currentTime == tourItems[i].getSecsPastHour()) {
  //             walkTime = tour[i].distanceTo(tour[j]) /  walkSpeed;
  //             //cout << "WalkTime: " << walkTime << endl;
  //             visitI = walkTime + currentTime;
  //             //cout << "Visit I: " << visitI << endl;
  //
  //             if (visitI >  (15 * 60 + tour[j].getSecsPastHour())) {
  //             //  tempVect.erase(tempVect.begin() + i);
  //               //cout << "Too late" << "\n";
  //               // visitI is too late, we can't visit that Item.
  //             } else {
  //
  //               //cout << "Time is good" << "\n";
  //               //cout << "VisitI: " << visitI << "\n";
  //               //cout << "Tour i time: " << tour[i] << "\n";
  //               if (visitI < tour[i].getSecsPastHour()) {
  //                 //cout << "in while loop" "\n";
  //                 visitI = tour[i].getSecsPastHour();
  //               }
  //
  //
  //
  //               //cout << "VisitI is now: " << visitI << "\n";
  //             }
  //             if (visitI < minVisit) {
  //               minVisit = visitI;
  //               //cout << "second loop" << "\n";
  //               tourItems.push_back(tour[i]);
  //               currentTime = minVisit;
  //               //cout << tourItems[i] << "\n";
  //               //cout << currentTime << "\n";
  //               for (int k=0; k<tourItems.size(); k++) {
  //                 cout << tourItems[k] << "\n";
  //               }
  //             }
  //             //cout << "I is : " << i << "\n";
  //
  //             currentTime++;
  //
  //           // } else {
  //           //   ++currentTime;
  //           // }
  //             //cout << "J :" << j << "\n";
  //         }
  //
  //
  //
  //
  //         //cout << "I :" << i <<"\n";
  //
  //
  //
  //       }
  //
  //
  //       //   cout << "walkTime: " << walkTime << endl;
  //       //     cout << "WlakSpeed: " << walkSpeed << endl;
  //             // cout << "VisitI: " << visitI << endl;
  //               // cout << "currentTime: " <<  currentTime << endl;
  //        //
  //       //  cout << "VisitI: " << visitI << "\n";
  //     }
  //     return tourItems;
  //
  // }
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

     while (currentTime < 3600 && tempVect.size() != 0) {

      vector<double> visit;

    //  cout << "first for loop" << endl;
      for (int i=0; i<tempVect.size(); i++) {
        int visitI = 0;
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

        if (minVisit > visit[i]) {
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


      cout << "End of a loop. Current time is " << currentTime
      << " and tempVect size is " << tempVect.size() <<endl;
     }
    // cout << "End while loop" << endl;
     return visitedItems;

   }


};


// for (int i=0; i<tour.size()-1; i++) {
//   for (int j=i+1; j<tour.size(); j++) {
//     if (i == 0 || currentTime == tourItems[j].getSecsPastHour()) {
//
//       walkTime = tour[i].distanceTo(tour[j]) / walkSpeed;
//       visitI = currentTime + walkTime;
//
//       if (visitI < (tour[i].getSecsPastHour() + 15 * 60)) {
//         visitI = tour[i].getSecsPastHour();
//       }
//       if (visitI < minVisit) {
//         minVisit = visitI;
//         tourItems.push_back(tour[i]);
//         currentTime = minVisit;
//         cout << currentTime << "\n";
//       }
//
//     }
//   }
// }
// }



// don't write any code below this line

#endif
