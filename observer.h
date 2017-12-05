/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*			  Sarah Davies  - 100828244				 */
/*			  Mike Sayegh	- 101029473				 */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _observerh
#define _observerh
#include <string.h>

class Subject;
class Observer {
  public:
  virtual void update(Subject * subject)= 0;

  virtual void printOn(ostream & out) const = 0;

  int operator==(const Observer & obs) const {
    return this == & obs;
  }
};

// ostream & operator<<(ostream & out, const Observer & obs) {
//  obs.printOn(out);
//  return out;
//}
#endif
