

#ifndef _PV_H_
#define _PV_H_

extern  int I(int semnum, int var);
extern void P(int semid, int semnum, int var);
extern void V(int semid, int semnum, int var);
extern void D(int semid);


#endif
